#include<bits/stdc++.h>
using namespace std;

struct Point
{
    double x,  y;
};



bool isAcute(Point v1, Point v2, Point v3){
    // double ans = (v1.x)-(v2.x)(v3.x-v2.x)) + ((v1.y-v2.y)(v3.y-v2.y));
    double a =v1.x - v2.x;
    // cout<< a<<" ";
    double b = v1.y-v2.y;
    // cout<<b<<" ";
    double c = v3.x - v2.x;
    // cout<< c<<" ";
    double d = v3.y-v2.y;
    // cout<< d<<endl;
    double dot = (a*c) + (b*d);
    double moda = sqrt(a*a +b*b);
    double modb = sqrt(c*c + d*d);

    double angle = acos(dot/(moda*modb));

    if(angle < acos(-1)){
        return true;
    }
    else{
        return false;  
    }
}


int main()
{
    cout<<isAcute({1,2},{0.2,1},{1,0})<<endl;
    // cout<<acos(-1);
    
 return 0;
}