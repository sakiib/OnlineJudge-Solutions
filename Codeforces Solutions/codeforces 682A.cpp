#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<int,int>mp;
int main()
{
   ll n,m,cnt=0;
   cin>>n>>m;
   for(int i=1;i<=m;i++){
       mp[i%5]++;
   }
   for(int i=1;i<=n;i++){
        ll ans=(5-i%5)%5;
        cnt+=mp[ans];
   }
   cout<<cnt<<endl;
   return 0;
}
