#include<bits/stdc++.h>
using namespace std;

class A{
public : 
int d;
A(int x){
    d = x;
}
};
class B{
    public:
    vector<A> myvec;
    void addThis(int x){
        A a = A(x);
        myvec.push_back(a);
    }
    void  print(){
        for(auto & it : myvec){
            cout<< it.d <<" ";
        }
        cout<<endl;
    }
};
int main()
{
    // int i = 5;
    // B b = B();
    // while(--i){
    //     b.addThis(i);
    // }
    // // b.print();

    // vector<int> a1 = {1,2,4};
    // vector<int> b1 = a1;
    // b1.push_back(54);
    // for(auto it : b1){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // a1.pop_back();
    // for(auto it : a1){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    vector<int> x = {1,2,3,44,5}; 
    x.erase(x.begin());
    cout<<x[0];



 return 0;
}