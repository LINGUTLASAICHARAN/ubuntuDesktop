#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void inOrder(Node *r)
{
    // l R r
    if (r == NULL)
        return;
    inOrder(r->left);
    cout << r->data << " ";
    inOrder(r->right);
}

Node *build(string s, int start, int end)
{
    if (end - start == 2)
    {
        Node *root = new Node(s[start + 1]);
        return root;
    }
    stack<int> stk;
    for (int i = start; i <= end; i++)
    {
        if (s[i] == '(')
        {
            stk.push(1);
        }
        else if (s[i] == ')')
        {
            stk.pop();
            if (stk.size() == 1)
            {
                if (s[i + 1] == '(')
                {
                    Node *x = new Node('.');
                    x->left = build(s, start + 1, i);
                    x->right = build(s, i + 1, end - 1);
                    return x;
                }
                else if (s[i + 1] == '*')
                {
                    Node *x = new Node('*');
                    x->left = build(s, start + 1, i);

                    return x;
                }
                else if (s[i + 1] == '+')
                {
                    Node *x = new Node('+');
                    x->left = build(s, start + 1, i);
                    return x;
                }
                else if (s[i + 1] == '|')
                {
                    Node *x = new Node('|');
                    x->left = build(s, start + 1, i);
                    x->right = build(s, i + 2, end - 1);
                    return x;
                }
            }
        }
    }
    cout << "returning NULL" << endl;
    return NULL;
}

Node *inserthash(Node *root)
{
    // while (root->right != NULL)
    // {
    //     root = root->right;
    // }
    // root->right = new Node('#');
    Node *temp = new Node('.');
    temp->right = new Node('#');
    temp->left = root;
    return temp;
}

struct state
{
    // for a given character a or b possible stansitions to other states
    map<char, set<state *>> transition;
    int id;
    state(int x)
    {
        id = x;
    }
};

struct nfa
{
    set<state *> states;
    state *start;
    set<state *> endStates;
};

nfa *buildNFA(Node *root)
{
    static int pos = 0;

    if (root->data == 'a' || root->data == 'b')
    {
        nfa *mynfa = new nfa;
        state *s1 = new state(pos++);
        state *s2 = new state(pos++);
        s1->transition['e'].insert(s1);
        s2->transition['e'].insert(s2);
        mynfa->states.insert(s1);
        mynfa->states.insert(s2);
        mynfa->start = s1;
        mynfa->endStates.insert(s2);
        s1->transition[root->data].insert(s2);
        // cout<<"building a"<<endl;
        return mynfa;
    }

    if (root->data == '|')
    {
        nfa *mynfa = new nfa;
        nfa *m1 = buildNFA(root->left);
        nfa *m2 = buildNFA(root->right);
        state *s1 = new state(pos++);
        state *s2 = new state(pos++);
        mynfa->states.insert(s1);
        mynfa->states.insert(s2);
        for (auto &it : m1->states)
        {
            mynfa->states.insert(it);
        }
        for (auto &it : m2->states)
        {
            mynfa->states.insert(it);
        }
        s1->transition['e'].insert(s1);
        s2->transition['e'].insert(s2);
        mynfa->start = s1;
        mynfa->endStates.insert(s2);
        s1->transition['e'].insert(m1->start);
        s1->transition['e'].insert(m2->start);

        for (auto &it : m1->endStates)
        {
            it->transition['e'].insert(s2);
        }
        for (auto &it : m2->endStates)
        {
            it->transition['e'].insert(s2);
        }
        // cout<< "building |"<<endl;
        return mynfa;
    }
    if (root->data == '*')
    {

        state *s1 = new state(pos++), *s2 = new state(pos++);
        nfa *mynfa = new nfa;
        nfa *mleft = buildNFA(root->left);
        s1->transition['e'].insert(s1);
        s2->transition['e'].insert(s2);

        mynfa->states.insert(s1);
        mynfa->states.insert(s2);
        for (auto &it : mleft->states)
        {
            mynfa->states.insert(it);
        }

        mynfa->start = s1;

        mynfa->endStates.insert(s2);
        // mynfa ->endStates.insert(s1);

        // s2->transition['e'].insert(s1);
        s1->transition['e'].insert(mleft->start);
        s1->transition['e'].insert(s2);
        for (auto &it : mleft->endStates)
        {
            it->transition['e'].insert(s2);
            it->transition['e'].insert(mleft->start);
        }
        // cout<<"building *"<<endl;
        return mynfa;
    }
    if (root->data == '+')
    {

        state *s1 = new state(pos++), *s2 = new state(pos++);
        nfa *mynfa = new nfa;
        nfa *mleft = buildNFA(root->left);
        s1->transition['e'].insert(s1);
        s2->transition['e'].insert(s2);

        mynfa->states.insert(s1);
        mynfa->states.insert(s2);
        for (auto &it : mleft->states)
        {
            mynfa->states.insert(it);
        }

        mynfa->start = s1;

        mynfa->endStates.insert(s2);
        // mynfa ->endStates.insert(s1);

        // s2->transition['e'].insert(s1);
        s1->transition['e'].insert(mleft->start);
        // s1->transition['e'].insert(s2);
        for (auto &it : mleft->endStates)
        {
            it->transition['e'].insert(s2);
            it->transition['e'].insert(mleft->start);
        }
        // cout<<"building *"<<endl;
        return mynfa;
    }
    if (root->data = '.')
    {
        nfa *mynfa = new nfa;

        nfa *m1 = buildNFA(root->left);
        nfa *m2 = buildNFA(root->right);

        state *s1 = new state(pos++);
        state *s2 = new state(pos++);

        s1->transition['e'].insert(s1);
        s2->transition['e'].insert(s2);
        mynfa->states.insert(s1);
        mynfa->states.insert(s2);
        for (auto &it : m1->states)
        {
            mynfa->states.insert(it);
        }
        for (auto &it : m2->states)
        {
            mynfa->states.insert(it);
        }
        mynfa->start = s1;

        mynfa->endStates.insert(s2);

        s1->transition['e'].insert(m1->start);

        for (auto &it : m1->endStates)
        {
            it->transition['e'].insert(m2->start);
        }

        for (auto &it : m2->endStates)
        {
            it->transition['e'].insert(s2);
        }
        // cout<<"building dot"<<endl;
        return mynfa;
    }

    return NULL;
}

set<state *> eclosure(state *cur)
{
    queue<state *> q;
    set<state *> ans;
    q.push(cur);
    while (!q.empty())
    {
        state *cur = q.front();
        for (auto &s : cur->transition['e'])
        {
            if (ans.find(s) == ans.end())
            {
                ans.insert(s);
                q.push(s);
            }
        }
        q.pop();
    }
    return ans;
}

bool runNFA(nfa *machine, state *cur, string s)
{
    if (s.size() == 0)
    {
        if (machine->endStates.find(cur) != machine->endStates.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (s[0] == 'e')
    {
        bool ans = false;
        set<state *> st = eclosure(cur);
        for (auto &stt : st)
        {
            ans = ans || runNFA(machine, stt, s.substr(1));
        }
        return ans;
    }
    else
    {
        bool ans = false;
        set<state *> st = cur->transition[s[0]];
        for (auto &stt : st)
        {
            ans = ans || runNFA(machine, stt, s.substr(1));
        }
        return ans;
    }
}

string nfastring(string match)
{
    string x;
    for (int i = 0, j = 0; j < match.size(); i++)
    {
        if (i % 2 == 0)
        {
            x = x + 'e';
        }
        else
        {
            x = x + match[j++];
        }
    }
    x.push_back('e');
    return x;
}

void runner(nfa *machine, string s, int start, int end, string &ans)
{

    if (start > end)
    {
        return;
    }
    for (int i = end; i >= start; i--)
    {
        bool x = runNFA(machine, machine->start, nfastring(s.substr(start, i - start + 1)));
        if (x)
        {
            // cout<<"$"<<s.substr(start,i-start+1);
            ans = ans + "$" + s.substr(start, i - start + 1);
            runner(machine, s, i + 1, end, ans);
            return;
        }
    }
    // cout<<"@"<<s[start];
    ans = ans + "@" + s[start];
    runner(machine, s, start + 1, end, ans);
    return;
}

void doit(vector<nfa *> machs, string s, int start, int end, string &ans, string unm)
{
    if (start > end)
    {
        if (unm.size() != 0)
        {
            ans += "@" + unm;
        }
        ans += "#";
        return;
    }
    map<int, pair<int, int>> matches;
    for (int j = 0; j < machs.size(); j++)
    {
        for (int i = end; i >= start; i--)
        {
            bool x = runNFA(machs[j], machs[j]->start, nfastring(s.substr(start, i - start + 1)));
            if (x)
            {
                // cout<<"$"<<s.substr(start,i-start+1);
                matches.insert({i - start + 1, {j, i}});
                // cout<<"matched by machine "<<j +1<<" " <<s.substr(start,i-start+1) <<" from "<<start <<" to " << i <<endl;
                // if(unm.size() != 0){
                //     ans = ans +  "@"+unm;
                // }

                // ans = ans + "$";
                // ans.push_back(j+'0'+1);

                // doit(machs,s,i+1,end,ans,"");
                // return;
                break;
            }
        }
    }
    // cout<<"not match"<<endl;
    if (matches.size() == 0)
    {
        unm += s[start];
        doit(machs, s, start + 1, end, ans, unm);
        return;
    }
    else
    {
        if (unm.size() != 0)
        {
            ans = ans + "@" + unm;
        }
        ans = ans + "$";
        auto it = matches.end();
        it--;
        int mach = it->second.first;
        ans.push_back(mach + '0' + 1);
        int i = it->second.second;
        doit(machs, s, i + 1, end, ans, "");
        return;
    }
}

int main()
{

    string s;
    ifstream inputFile;
    inputFile.open("input.txt");
    int n;
    inputFile >> n;
    getline(inputFile, s);
    vector<string> ms(n);
    for (int i = 1; i <= n; i++)
    {
        getline(inputFile, ms[i - 1]);
        // cout<<ms[i-1]<<endl;
    }

    string input;
    getline(inputFile, input);
    // cout<<input;

    vector<nfa *> machines(n);
    vector<Node *> roots(n);

    for (int i = 0; i < n; i++)
    {
        roots[i] = build(ms[i], 0, (ms[i].size()) - 1);
        machines[i] = buildNFA(roots[i]);
    }

    string ans = "";
    doit(machines, input, 0, input.size() - 1, ans, "");
    // cout<<ans<<endl;
    ofstream outputFile;

    outputFile.open("output.txt");

    outputFile << ans;
    return 0;
}