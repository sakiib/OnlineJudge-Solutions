#include<bits/stdc++.h>
using namespace std;
int ara[10001];
int main()
{
    int n,m,l,r,sum=0,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>ara[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r;
        for(int j=l;j<=r;j++)
        {
            sum+=ara[j];
        }
        if(sum>0) ans+=sum; sum=0;
    }
    cout<<ans;
    return 0;
}
