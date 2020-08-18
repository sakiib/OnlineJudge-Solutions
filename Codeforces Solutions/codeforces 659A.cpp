#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,ans;
    cin>>n>>a>>b;
    ans=((a+b-1)%n+n)%n+1;
    cout<<ans<<endl;
    return 0;
}
