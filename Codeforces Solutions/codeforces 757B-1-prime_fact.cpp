#include<bits/stdc++.h>
using namespace std;
int ara[100001];
vector<int>prime;
map<int,int>mp;
void gen_prime()
{
    vector<bool>isprime(100010,true);
    isprime[0]=false;
    isprime[1]=false;
    for(long long i=2;i<100001;i++){
        if(isprime[i]){
            prime.push_back(i);
            for(long long j=i*i;j<=100001;j+=i){
                isprime[j]=false;
            }
        }
    }
}
void factorize(int num)
{
    int lim=sqrt(num);
    for(int i=0;i<prime.size();i++){
        if(prime[i]>lim) break;
        if(num%prime[i]==0){
            mp[prime[i]]++;
            //cout<<mp[prime[i]]<<endl;
            while(num%prime[i]==0){
                num=num/prime[i];
            }
        }
    }
    if(num>1) mp[num]++;

}
int solve(int n)
{
    gen_prime();
    for(int i=0;i<n;i++){
        factorize(ara[i]);
    }
    int maxs=0;
    for(int i=2;i<100000;i++){
        maxs=max(maxs,mp[i]);
    }
    if(maxs==0) maxs++;
    return maxs;
}
int main()
{
    int n,ans;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    ans=solve(n);
    cout<<ans<<endl;
    return 0;
}
