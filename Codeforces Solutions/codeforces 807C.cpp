#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll b_search(int a,int b,int x,int y)
{
    ll low=0,high=1000000000;
    while(low<=high){
        mid=(high+low)/2;

    }
}
int main()
{
    ll a,b,x,y,t;
    cin>>t;
    while(t--){
        cin>>a>>b>>x>>y;
        if(x==0){
            if(a==0) cout<<0;
            else cout<<-1;
            return 0;
        }
        else if(x==y){
            if(a==b) cout<<0;
            else cout<<-1;
            return 0;
        }
        ll ans=solve(a,b,x,y);
        cout<<ans;
    }
    return 0;
}
