#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<cmath>
#include<math.h>
#include<stack>
#include<vector>
#include<map>
#include<set>
#define eps 1e-6
#define pi acos(-1)
#define mod 1e9+7
#define inf 2000000000LL
typedef long long int ll;
typedef unsigned long long int llu;
using namespace std;
set<int>myseti;
set<string>mysets;
set<char>mysetc;
stack<int>mysti;
stack<char>mystc;
vector<ll>myvecl;
vector<int>myveci;
map<char,int>mymapci;
map<string,int>mymapsi;
map<string,string>mymapss;
map<int,int>mymapii;
map<ll,ll>mymapll;
int A,C,G,T;
int main()
{
    int n,i,ara[10001],limit;
    string str,str2="";
    cin>>n;
    limit=n/4;
    cin>>str;
    if(n%4!=0)
    {
        cout<<"==="<<endl;
        return 0;
    }
    else
    {
      for(i=0;i<str.size();i++)
      {
       if(str[i]=='A') A++;
       else if(str[i]=='C') C++;
       else if(str[i]=='T') T++;
       else if(str[i]=='G') G++;
       if(str[i]!='?') mymapci[str[i]]++;
      }
      if(A>n/4||C>n/4||T>n/4||G>n/4)
      {
          cout<<"==="<<endl;
          return 0;
      }
      A=n/4-A;C=n/4-C;T=n/4-T;G=n/4-G;
      //cout<<A<<" "<<C<<" "<<T<<" "<<G<<endl;
     /*map<char,int>::iterator it;//Works Fine//
      for(it=mymapci.begin();it!=mymapci.end();it++)
      {
         // cout<<it->first<< " " <<it->second<<endl;
         if(it->second>limit)
         {
             cout<<"==="<<endl;
             return 0;
         }
      }*/
      for(i=0;i<str.size();i++)
      {
          if(str[i]=='?')
          {
              if(A>0)
              {
                  str2.push_back('A'); A--;
              }
              else if(C>0)
              {
                  str2.push_back('C'); C--;
              }
              else if(T>0)
              {
                  str2.push_back('T'); T--;
              }
              else if(G>0)
              {
                  str2.push_back('G'); G--;
              }
          }
           else str2.push_back(str[i]);
      }
      cout<<str2<<endl;
    }
    return 0;
}



