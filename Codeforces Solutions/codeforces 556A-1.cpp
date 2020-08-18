#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int one=0,zer=0;
    for(int i=0;i<n;i++){
        if(str[i]=='1') one++;
        else zer++;
    }
    cout<<abs(one-zer)<<endl;
    return 0;
}
