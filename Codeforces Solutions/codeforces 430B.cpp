#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,k,c;
    int ara[100010];
    cin>>n>>k>>c;
    int cnt=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    if(n<2) {
        cout<<0<<endl; return 0;
    }
    int l,r,mx=-1,st,en;
    for(int i=1;i<=n-1;i++) {
        if(ara[i]==c&&ara[i+1]==c) {
            cnt=3;
            st=i-1;
            en=i+2;
            while(st>0&&en<=n) {
            if(ara[st]!=ara[en]) break;
            l=1,r=1;
            while(ara[st]==ara[st-1]&&st>1) {
                st--; l++;
            }
            while(ara[en]==ara[en+1]&&en<n) {
                en++; r++;
            }
            st--; en++;
            if(l+r>=3) cnt+=(l+r);
            else break;
            }
            mx=max(mx,cnt);
        }
    }
    mx--;
    mx=max(mx,0);
    cout<<mx<<endl;
    return 0;
}
