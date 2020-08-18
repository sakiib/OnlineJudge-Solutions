#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ara[100001];
vector<ll>myvec;
int main()
{
    ll n,delay,rem=1,maxs=1,ans=0;
    cin>>n>>delay;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<n-1;i++){
        if(ara[i+1]-ara[i]<=delay){
            rem++;
        }
        else{
            rem=1;
        }

    }
    cout<<rem;
    return 0;
}
