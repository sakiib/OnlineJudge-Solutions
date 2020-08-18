#include<bits/stdc++.h>
using namespace std;
vector<bool> isprime(1000000,true);
void sieve() {
    isprime[0]=false;
    isprime[1]=false;
    isprime[2]=true;
    for(int i=2;i<=1000;i++) {
        if(isprime[i]) {
            for(int j=i;i*j<1000000;j++) {
                isprime[i*j]=false;
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    sieve();
    int ara[505][505];
    int next[100010];
    for(int i=100010;i>=0;i--) {
        if(isprime[i]) next[i]=i;
        else next[i]=next[i+1];
    }
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>ara[i][j];
        }
    }
    int mn=1e9+7;
    for(int i=1;i<=n;i++) {
        int sum=0;
        for(int j=1;j<=m;j++) {
            sum+=next[ara[i][j]]-ara[i][j];
        }
        mn=min(sum,mn);
    }
    for(int i=1;i<=m;i++) {
        int sum=0;
        for(int j=1;j<=n;j++) {
            sum+=next[ara[j][i]]-ara[j][i];
        }
        mn=min(mn,sum);
    }
    cout<<mn<<endl;
    return 0;
}
