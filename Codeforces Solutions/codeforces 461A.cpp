#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[300010];

int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        sum+=ara[i];
    }
    sort(ara+1,ara+n+1);
    ll prev=sum,temp;
    for(int i=1;i<n;i++) {
       sum+=(ara[i]);
       temp=prev-ara[i];
       sum+=(prev-ara[i]);
       prev=temp;
    }
    cout<<sum<<endl;
    return 0;
}
