#include <stdio.h>
#define INF 1000000000000000

typedef long long LL;
LL ts,tf,dt,n,t[100010];

int main(void)
{
    //freopen("queue.in","r",stdin);
    //freopen("queue.out","w",stdout);
    scanf("%I64d%I64d%I64d%I64d",&ts,&tf,&dt,&n);
    LL i;
    for(i=1;i<=n;i++)
        scanf("%I64d",&t[i]);
    LL ans=INF,x=ts,t0;
    for(i=1;i<=n;i++)
    {
        if(x+dt>tf) break;
        if(t[i]>x)
        {
            t0=x;
            break;
        }
        if(x-t[i]+1<ans)
        {
            ans=x-t[i]+1;
            t0=t[i]-1;
        }
        x+=dt;
    }
    if(x+dt<=tf) t0=x;
    printf("%I64d\n",t0);
    return 0;
}
