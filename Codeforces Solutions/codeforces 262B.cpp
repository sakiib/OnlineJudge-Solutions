#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc,char const *argv[]) {
    ll n,k;
    cin>>n>>k;
    int ara[100010];
    int cnt=0;
    for(int i=0;i<n;i++) {
        cin>>ara[i];
        if(ara[i]<0) cnt++;
    }
    ll sum=0;
    if(cnt==k) {
        for(int i=0;i<n;i++) {
            if(ara[i]<0) ara[i]=ara[i]*(-1);
            sum+=ara[i];
        }
        cout<<sum<<endl<<endl;
        return 0;
    }
    if(cnt<k) {
        int m=cnt;
        bool done=false;
        while(true) {
            if(!done) {
            for(int i=0;i<cnt;i++) {
                ara[i]=ara[i]*(-1);
                done=true;
            }
           }
            sort(ara,ara+n);
            int x=k-cnt;
            if(x&1) ara[0]=ara[0]*(-1);
            break;
        }
        for(int i=0;i<n;i++) {
            sum+=ara[i];
        }
        cout<<sum<<endl;
        return 0;
    }
    if(cnt>k) {
        for(int i=0;i<k;i++) {
            if(ara[i]<0) ara[i]=ara[i]*(-1);
            sum+=ara[i];
        }
        for(int i=k;i<n;i++) {
            sum+=ara[i];
        }
        cout<<sum<<endl;
        return 0;
    }
    return 0;
}
