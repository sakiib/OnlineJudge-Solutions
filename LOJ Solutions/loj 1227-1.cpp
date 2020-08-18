#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int n,p,q,tc,t,i,ara[100000],sum,count,j;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++)
    {
        sum=0;
        count=0;
        scanf("%d%d%d",&n,&p,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        sort(ara,ara+n);
        for(i=1;i<=n;i++)
        {
           sum+=ara[i];
            if(sum>q||(i-1)==p)
              break;
            else
              count++;
        }
        printf("Case %d: %d\n",tc,count);
    }
    return 0;
}

