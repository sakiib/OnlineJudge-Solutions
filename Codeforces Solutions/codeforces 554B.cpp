#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string str[105];
    map<string,int> M;
    for(int i=0;i<n;i++) {
        cin>>str[i];
        M[str[i]]++;
    }
    int mx=0;
    for(auto &x : M) {
        mx=max(mx,x.second);
    }
    cout<<mx<<endl;
    return 0;
}
