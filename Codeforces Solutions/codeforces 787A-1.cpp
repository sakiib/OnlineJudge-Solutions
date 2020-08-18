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
ll ara1[100001],ara2[100001];
int main()
{
    ll a,b,c,d,count=0,yes=0,i,j,ans;
    cin>>a>>b>>c>>d;
    ara1[0]=b;ara2[0]=d;
    for(i=1;i<100;i++)
    {
        ara1[i]=ara1[i-1]+a;
        ara2[i]=ara2[i-1]+c;
    }
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
          if(ara1[i]==ara2[j])
          {
              yes=1;
              ans=ara1[i];
              break;
             //cout<<ara1[i]<< " " <<ara2[j]<<endl;
          }
        }
        if(yes==1)break;
    }
    if(yes==1) cout<<ans<<endl;
    else cout<<-1<<endl;

  return 0;
}



