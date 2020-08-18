#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll n,t;
    ll ara[100010];
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    ll st=0,l=0,sum=0,mx=0,cnt=0;
    while(st<n){
        if(sum+ara[st]<=t){
            sum+=ara[st];
            cnt++;
            st++;
            mx=max(mx,cnt);
        }
        else{
            sum-=ara[l];
            cnt--;
            l++;
            mx=max(mx,cnt);
        }
    }
    cout<<mx<<endl;
    return 0;
}
