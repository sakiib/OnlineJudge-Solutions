#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,ans,temp=10;

    while(scanf("%d",&n)==1){
      ans=1;
      a=1;
      while(a%n!=0){
        a=(a*temp+1)%n;
        //cout<<a<<endl;
        ans++;
      }
      cout<<ans<<endl;
    }
    return 0;
}
