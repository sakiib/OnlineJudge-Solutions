#include<iostream>
#include<cstdio>
#include<string.h>
#include<cstring>

using namespace std;

int main()
{
    int t,tc,num,a,b,c,i,ara[100000],temp,j;
    char str[100][10000],str1[10000];
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++)
    {
        scanf("%d",&num);
        for(i=0;i<num;i++)
        {
           scanf("%s%d%d%d",str[i],&a,&b,&c);
           ara[i]=a*b*c;
        }
         for(i=0;i<num;i++)
    {
        for(j=i+1;j<num;j++)
        {
            if(ara[j]<ara[i])
            {
                temp=ara[i];
                ara[i]=ara[j];
                ara[j]=temp;
                strcpy(str1,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],str1);

            }
        }
    }
    if(ara[0]==ara[num-1])
    printf("Case %d: no thief\n",tc);
    else
    printf("Case %d: %s took chocolate from %s\n",tc,str[num-1],str[0]);
    }

    return 0;
}

