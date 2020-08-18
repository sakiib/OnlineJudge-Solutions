#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv) {
    int n;
    string str;
    cin>>n;
    map<string,int> M;
    while(n--) {
        cin>>str;
        if(M[str]==0) {cout<<"OK"<<endl; M[str]++;}
        else {cout<<str<<M[str]<<endl; M[str]++;}
    }
    return 0;
}
