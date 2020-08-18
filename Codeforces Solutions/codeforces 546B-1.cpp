#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010],temp[100010];
    int ase=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        temp[i]=ara[i];
    }
    sort(ara+1,ara+n+1);
    ara[0]=ara[1];
    int ans=0;
    for(int i=2;i<=n;i++) {
        if(ara[i]<=ara[i-1]) {
            ara[i]+=(ara[i-1]-ara[i]+1);
            //ans+=(ara[i-1]-ara[i]+1);
        }
    }
    /*for(int i=1;i<=n;i++) {
        cout<<ara[i]<< " ";
    }
    set<int> S;
    for(int i=1;i<=n;i++) {
        S.insert(ara[i]);
    }
    if(S.size()==n) cerr<<"distinct"<<endl;*/
    for(int i=1;i<=n;i++) {
        ans+=(ara[i]-temp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
