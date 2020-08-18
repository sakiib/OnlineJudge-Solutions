#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int mn=100010;
    int ind,cnt=0;
    for(int i=0;i+n<=m;i++) {
             cnt=0;
        for(int j=0;j<n;j++) {
            if(s[j]!=t[i+j]) {
                cnt++;
            }
           // cout<<mn<<endl;
        }
         if(cnt<mn) {
                mn=cnt;
                ind=i;
            }
    }
    //cerr<<cnt<< " "<<ind<<endl;
    cout<<mn<<endl;
    for(int i=0;i<n;i++) {
        if(s[i]!=t[ind+i]) cout<<i+1<< " ";
    }
    return 0;
}
