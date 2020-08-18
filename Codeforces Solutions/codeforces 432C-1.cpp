#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
vector<bool> isprime(100010,true);
int ara[100010];
map<int,int> M;
int keep[100010];
vector<pair<int,int> > ans;

void sieve() {
    prime.push_back(2);
    int sq=sqrt(100010);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=100010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(int i=3;i<=100010;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
void build(int val) {
    int cur=keep[val];
    int m=cur-val+1;
    if(m==1) return;
    else {
        int loc=upper_bound(prime.begin(),prime.end(),m)-prime.begin();
        loc=prime[loc-1];
        swap(ara[cur],ara[cur-loc+1]);
        int a=ara[cur];
        int b=ara[cur-loc+1];
        swap(keep[a],keep[b]);
        ans.push_back(make_pair(cur-loc+1,cur));
        build(val);
    }

}
int main(int argc,char const *argv[]) {
    sieve();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        keep[ara[i]]=i;
    }
    for(int i=1;i<=n;i++) {
        build(i);
    }
    cout<<ans.size()<<endl;
    for(auto&x : ans) {
        cout<<x.first<< " " <<x.second<<endl;
    }
    return 0;
}
