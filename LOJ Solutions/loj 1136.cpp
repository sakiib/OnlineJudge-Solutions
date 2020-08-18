#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int fun(int n)
{
    if(n==1||n==0) return 0;
    return n-1-(n-1)/3;
}

int main()
{
    int a,b,t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        printf("Case %d: %d\n",i,fun(b)-fun(a-1));
    }
    return 0;
}
