#include <bits/stdc++.h>
using namespace std ;
int main ()
{
  int t,tc,ara[100005],i,n,q,x,y,low,up;
  scanf("%d",&t);
  for(tc=1;tc<=t;tc++)
  {
      printf("Case %d:\n",tc);
      scanf("%d%d",&n,&q);
      for(i=0;i<n;i++)
      {
          scanf("%d",&ara[i]);
      }
      while(q--)
      {
       scanf("%d%d",&x,&y);
       low=lower_bound(ara,ara+n,x)-ara;
       up=upper_bound(ara,ara+n,y)-ara;
       printf("%d\n",up-low);
      }
  }
    return 0 ;
}
