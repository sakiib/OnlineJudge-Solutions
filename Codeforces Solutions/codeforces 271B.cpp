#include<bits/stdc++.h>
using namespace std;

vector<bool> isprime(1000000,true);

void sieve() {

    isprime[1]=false;
    isprime[0]=false;
    isprime[2]=true;

    for(int i=2;i<=1000;i++) {
       if(isprime[i]) {
         for(int j=i;j*i<1000000;j++) {
            isprime[i*j]=false;
         }
       }
    }
}
int fixit(int x) {
    int ret=0;
    while(!isprime[x]) {
        ret++; x++;
    }
    return ret;
}
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    sieve();

    int n,m;
    cin>>n>>m;

    int ara[505][505];

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>ara[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        bool row=true;
        for(int j=1;j<=m;j++) {
            if(isprime[ara[i][j]]) continue;
            else {
                row=false; break;
            }
        }
        if(row) {
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i=1;i<=m;i++) {
        bool col=true;
        for(int j=1;j<=n;j++) {
            if(isprime[ara[j][i]]) continue;
            else {
                col=false; break;
            }
        }
        if(col) {
            cout<<0<<endl;
            return 0;
        }
    }
    int mn=9999999999999;
    for(int i=1;i<=n;i++) {
        int cnt=0;
       for(int j=1;j<=m;j++) {
         if(isprime[ara[i][j]]) continue;
         else {
            int k=ara[i][j];
            cnt+=fixit(k);
         }
       }
       mn=min(mn,cnt);
    }
    for(int i=1;i<=m;i++) {
        int cnt=0;
        for(int j=1;j<=n;j++) {
            if(isprime[ara[j][i]]) continue;
            else {
                int k=ara[j][i];
                cnt+=fixit(k);
            }
        }
        mn=min(mn,cnt);
    }
    cout<<mn<<endl;
    return 0;
}
