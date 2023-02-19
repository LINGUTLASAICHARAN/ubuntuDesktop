#include<bits/stdc++.h>
using namespace std;
int main() {


    ifstream inputFile;
    inputFile.open("input.txt");
  

    string l1,l2;
    getline(inputFile,l1);
    getline(inputFile,l2);
    cout<<l1<<" " <<l2;

    inputFile.close();
  
  
  return 0;
}
