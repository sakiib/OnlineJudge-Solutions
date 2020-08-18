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
int ara[100001]={0};
int main()
{
    int n,soc,tab=0,ans=0;
    cin>>n;
    int a=2*n;
    while(a--)
    {
        cin>>soc;
        if(ara[soc]==0)
        {
          tab++;
          if(tab>ans) ans=tab;
          ara[soc]=1;
        }
        else
        {
          tab--;
        }
    }
    cout<<ans<<endl;
  return 0;
}



