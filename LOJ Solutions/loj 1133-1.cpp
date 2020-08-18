#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    int tc,t,i,ara[100000],n,sim,add,mul,div,x,y;
    char ch[2];

    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%d%d",&n,&sim);

        for(i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
        }

        while(sim--) {
            scanf("%s",ch);

            if(ch[0]=='S') {
                scanf("%d",&add);
                for(i=1;i<=n;i++) {
                    ara[i]+=add;
                }
            }

            else if(ch[0]=='M') {
                scanf("%d",&mul);
                for(i=1;i<=n;i++) {
                    ara[i]*=mul;
                }
            }

            else if(ch[0]=='D') {
                scanf("%d",&div);
                for(i=1;i<=n;i++) {
                    ara[i]/=div;
                }
            }

            else if(ch[0]=='P') {
                scanf("%d%d",&x,&y);
                for(i=1;i<=n;i++) {
                    swap(ara[x],ara[y]);
                }
            }

            else if(ch[0]=='R') {
                reverse (ara,ara+n);
            }
          }
         printf("Case %d:\n",tc);

        for(i=1;i<n;i++) {
           printf("%d ",ara[i]);
        }
          printf("%d\n",ara[n]);
    }

    return 0;
}
