#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ara[300005];
int main()
{
    ll n,k,mn=9999999999999999,cnt=0,sum=0,step=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    for(int i=step;i<n-k-1;){
        sum+=ara[i]; cnt++;
        if(cnt==k){
            mn=min(mn,sum);
            step++; sum=0; cnt=0;
        }
        i++;
    }
    cout<<mn;

}
