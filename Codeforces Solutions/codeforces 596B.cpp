#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,ara[200005],ans=0,track;
    scanf("%I64d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&ara[i]);
    }
    ara[0]=0;
    for(int i=1;i<=n;i++){
       ans+=abs(ara[i]-ara[i-1]);
    }
    printf("%I64d\n",ans);
    return 0;
}
