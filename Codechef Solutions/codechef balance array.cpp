#include<bits/stdc++.h>
using namespace std;
int ara[100010];
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a,b;
        a.clear();
        b.clear();
        for(int i=1;i<=n;i++) {
            cin>>ara[i];
            a.push_back(ara[i]);
            b.push_back(ara[i]);
        }
        reverse(b.begin(),b.end());
        for(int i=1;i<a.size();i++) {
            a[i]+=a[i-1];
        }
        for(int i=1;i<b.size();i++) {
            b[i]+=b[i-1];
        }
        reverse(b.begin(),b.end());
        int ans;
        bool found=false;
        for(int i=0;i<a.size();i++) {
            //cout<<a[i]<< " "<<b[i]<<endl;
            if(a[i]==b[i]) {
                ans=i;
                found=true;
                break;
            }
        }
        if(found) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
