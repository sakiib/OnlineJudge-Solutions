#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    cin>>a>>b;
    int l=b.size();
    int ans=0;
    for(int i=0;i<a.size();i++) {
        if(a[i]==b[0]) {
            if(a.substr(i,l)==b){
                ans++;
                i+=(l-1);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
