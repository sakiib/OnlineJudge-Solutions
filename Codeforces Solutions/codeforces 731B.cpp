#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ara[200001];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
    }
   for(int i=0;i<n;i++)
   {
       if(ara[i]%2==1)
       {
           if(ara[i+1]==0||i==n-1)
           {
               cout<<"NO"<<endl; return 0;
           }
           else ara[i+1]--;
       }
   }
   cout<<"YES"<<endl;
   return 0;
}
