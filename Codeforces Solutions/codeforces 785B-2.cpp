#include<bits/stdc++.h>
#include<stdio.h>
typedef long long int ll;
typedef unsigned long long int llu;
using namespace std;
stack<int>mysti;
stack<char>mystc;
vector<ll>myvec;
map<string,int>mymapsi;
map<string,string>mymapss;
map<int,int>mymapii;
map<ll,ll>mymapll;
int main()
{
    ll n,m,che_max=0,che_min=1000000001,x,y;
    ll pro_max=-1,pro_min=1000000001;
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        if(x>che_max)
            che_max=x;
        if(y<che_min)
            che_min=y;
    }
    //cout<<che_max<< " " <<che_min<<endl;
    cin>>m;
    while(m--)
    {
        cin>>x>>y;
        if(x>pro_max)
            pro_max=x;
        if(y<pro_min)
            pro_min=y;
    }
    ll ans=max(pro_max-che_min,che_max-pro_min);
    if(ans<=0) cout<<0<<endl;
    else cout<<ans<<endl;
  return 0;
}



