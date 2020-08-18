#include<bits/stdc++.h>
using namespace std;
int s,n,ara[1000];
void rec(int ind,int sum)
{
    if(sum>=s) {
        cout<<"Sum "<<sum<<endl;
    }
    for(int i=0;i<n;i++){
        if(sum+ara[i]<=s){
            rec(ind+1,sum+ara[i]);
            cout<<sum<<endl;
        }
       // else rec(ind,sum-ara[i]);
    }
   //cout<<sum<<endl;
}
int main()
{
   cin>>n;
   for(int i=0;i<n;i++){
     cin>>ara[i];
   }
   cin>>s;
   rec(0,0);
}
