#include<bits/stdc++.h>
#include<fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

bool belong(string r,string q){
    if(r.size()==0 ){
        if(q.size()==0){
            return true;

        }
        else{
            return false;
        }
    }
    else if(r.size()!=0){
        if(r[0]=='('){
            int i=1;
            int count=1;
            while(count!=0){
                if(r[i]==')'){
                    count--;
                }
                else if(r[i]=='('){
                    count++;
                }
                i++;
            }
            if(i==r.size()){
                return belong(r.substr(1,i-2),q);
            }
            else if(r[i]=='+'){
                for(int j=0;j<=q.size();j++){
                    cout<<"modda 1";
                    bool a=belong(r.substr(1,i-2),q.substr(0,j));
                    r[i]='*';
                    bool b=belong(r,q.substr(j,q.size()-j));
                    r[i]='+';
                    if(a && b){
                        return true;
                    }
                }
            }
            else if(r[i]=='*'){
                if(belong(r.substr(i+1,r.size()-i-1),q)){
                    return true;
                }
                else{
                    for(int j=1;j<=q.size();j++){
                        cout<<"sdg"<<j;
                        bool a=belong(r.substr(1,i-2),q.substr(0,j));
                        bool b=belong(r,q.substr(j,q.size()-j));
                        if(a && b){
                            return true;
                        }
                    }
                }
            }
            else if(r[i]=='|'){
                // if(belong(r.substr(i+1,r.size()-i-1),q)){
                //     return true;
                // }
                // else{
                //     for(int j=1;j<=q.size();j++){
                        bool a=belong(r.substr(1,i-2),q);
                        bool b=belong(r.substr(i+1,r.size()-i-1),q);
                        if(a || b){
                            return true;
                        }
                //     }
                // }
            }
            else{
                for(int j=0;j<=q.size();j++){
                    cout<<"RWgwrg3";
                    bool a=belong(r.substr(1,i-2),q.substr(0,j));
                    bool b=belong(r.substr(i,r.size()-i),q.substr(j,q.size()-j));
                    if(a && b){
                        return true;
                    }
                }
            }
        }
        else{
            if(q.size()==0){
                return false;
            }
            else if(r[0]!=q[0]){
                return false;
            }
            else{
                // if(r.size()==1 && q.size()==1){
                //     return true;
                // }
                return belong(r.substr(1,r.size()-1),q.substr(1,q.size()-1));
            }
        }
    }

    return false;
}

string solve(string r,string q)
{
    if(q.size()==0)
    return "";
    string x="";
    int check=0;
    for(int i=q.size();i>=1;i--)
    {
        cout<<"shfgheheh4";
        if(belong(r,q.substr(0,i)))
        {
            check=1;
            x+="$";
            x+=q.substr(0,i);
            
            x+=solve(r,q.substr(i));
            return x;
        }
    }
    
    x+="@";
    x+=q.substr(0,1);
    x+=solve(r,q.substr(1));
    
    return x;
}

string match(int l, vector<string> m, string n) {

    if(n.size()==0) {
        return "";
    }
    string x = "";
    int chec = 0;

    
        for(int j=n.size();j>=1;j--){
            cout<<"brfbssbsfbgd4";
        
        for(int i=0; i<l; i++) {
            cout<<"sfgbdfggfn5";
            if(belong(m[i],n.substr(0,j))){
               
               chec = 1;
               x+="$";
               x+=to_string(i+1);

               x+=match(l,m,n.substr(j));
               return x;
            }
        }
    }

    x+="@";
    x+=n.substr(0,1);
    x+=match(l,m,n.substr(1));

    return x;

}

int main(){

    vector<string> s;
    int r;
    string q;

    fin>>r;
    
    for(int i = 0; i < r; i++) {
        string y;
        fin >> y;
        s.push_back(y);
    }
    fin>>q;
    
    // cout<<belong(r,q);
    string x = match(r,s,q);
    //=solve(r,q);
    x+="#";
    fout<<x;
    
    return 0;

}