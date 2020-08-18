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
    ll a,b,count=0;
    cin>>a>>b;
    while(a<=b)
    {
        a*=3;
        b*=2;
        count++;
    }
   cout<<count<<endl;
  return 0;
}



