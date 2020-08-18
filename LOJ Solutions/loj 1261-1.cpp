#include<stdio.h>
int main()
{
    int t,tc,person,limit,wish,ara1[100][1000],ara2[1000],i,j,k;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%d%d%d",&person,&limit,&wish);
        for(i=0;i<person;i++) {
            for(j=0;j<wish;j++) {
                scanf("%d",&ara1[i][j]);
            }
        }
        scanf("%d",&limit);
        for(k=0;k<limit;k++) {
            scanf("%d",&ara2[k]);
        }
        for(i=0;i<person;i++) {
            for(j=0;j<wish;j++) {
                if(ara1[i][j]<0) {
                    for(k=0;k<limit;k++) {

                    }
                }
                else {
                    for(k=0;k<limit;k++) {

                    }
                }
            }

        }
        if( )
            printf("Case %d: Yes\n",tc);
        else
            printf("Case %d: No\n",tc);
    }
    return 0;
}
