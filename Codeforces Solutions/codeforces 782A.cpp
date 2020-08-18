#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,ara[100009],i,count=1,j,yes=0,ara1[10000],k,max=0;
    scanf("%d",&n);
    for(i=0;i<n*2;i++)
    {
        scanf("%d",&ara[i]);
    }
    k=0;
    for(i=1;i<n*2;i++)
    {
        for(j=0;j<i;j++)
        {
            if(ara[i]==ara[j])
                {
                    ara1[k]=count;
                    count=1;
                    yes=1;
                    k++;
                    break;
                }
                else
                    yes=0;

        }
        if(yes==0)
        count++;
    }
    sort(ara1,ara1+n);
    printf("%d\n",ara1[n-1]);
    return 0;
}

