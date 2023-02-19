#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_operand(char c) {
    return c == 'a' || c == 'b';
}

bool is_operator(char c) {
    return c == '+' || c == '*';
}

bool is_concatenation(char c1, char c2) {
    return (is_operand(c1) || c1 == ')') && (is_operand(c2) || c2 == '(');
}

bool is_closure(char c) {
    return c == '*';
}

bool match(string w, int &i, string r, int &j) {
    if (j == r.size()) {
        return i == w.size();
    }
    if (is_operand(r[j])) {
        if (r[j] != w[i]) {
            return false;
        }
        i++;
        j++;
        return match(w, i, r, j);
    }
    if (is_closure(r[j])) {
        int k = i;
        while (match(w, k, r, j + 1)) {
            i = k;
        }
        j++;
        return true;
    }
    if (r[j] == '+') {
        return match(w, i, r, j + 1) || match(w, i, r, j + 2);
    }
    return false;
}

int main() {
    string r, w, s;
    cin >> r >> w;

    int i = 0, j = 0;
    while (i < w.size()) {
        int k = i;
        if (match(w, k, r, j)) {
            s.append("$");
            s.append(w.substr(i, k - i));
            i = k;
        } else {
            s.append("@");
            s.append(1, w[i]);
            i++;
        }
    }
    s.append("#");

    cout << s << endl;

    return 0;
}