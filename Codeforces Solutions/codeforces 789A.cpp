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
    int n,k,i,count=0,pocket=0,left=0;
    scanf("%d%d",&n,&k);
    int ara[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }
    for(i=0;i<n;i++)
    {
       while(ara[i]>0)
       {
           ara[i]=ara[i]-k;
           pocket++;
           if(pocket==2)
           {
               count++;
               pocket=0;
           }
       }
    }
    if(pocket>=1)
    count++;
    printf("%d\n",count);
  return 0;
}



