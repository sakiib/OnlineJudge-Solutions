#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll power(int a,int b)
{
   ll res=1;
   for(int i=1;i<=b;i++){
      res*=a;
   }
   return res;
}
int main()
{
    int n;
    cin>>n;
    cout<<power(2,n+1)-2<<endl;
    return 0;
}
