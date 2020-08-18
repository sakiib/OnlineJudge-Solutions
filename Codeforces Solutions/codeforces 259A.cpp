#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    char str[10][10];
    for(int i=0;i<8;i++) {
        cin>>str[i];
    }
    for(int i=0;i<8;i++) {
        string a=str[i];
        if(a!="WBWBWBWB"&&a!="BWBWBWBW") {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
