#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,b,p,bot=0,ans,a;
    cin>>n>>b>>p;
    a=n;
    while(n>1){
        for(int i=2;n/i>=1;i*=2){
            ans=i;
        }
        bot+=(ans*b+ans/2);
        n=n%ans+ans/2;
      // cout<<bot<< " "<<n<<endl;
    }
    cout<<bot<< " "<<a*p<<endl;
    return 0;
}
