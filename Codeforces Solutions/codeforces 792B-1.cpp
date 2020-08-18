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
   ll n,k,a,i,num,lead=0,del;
   cin>>n>>k;
   for(i=1;i<=n;i++)
   {
       myvec.push_back(i);
   }
   /*for(i=0;i!=myvec.size();i++)
   {
       cout<<myvec[i]<< " ";
   }*/
   while(k--)
   {
       cin>>num;
       del=(lead+num)%n;
       cout<<myvec[del]<< " ";
       myvec.erase(myvec.begin()+del);
       n--;
       lead=del%n;
   }
   cout<<endl;
  return 0;
}


