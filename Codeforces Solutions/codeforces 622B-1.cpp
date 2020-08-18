#include<bits/stdc++.h>
using namespace std;
int main()
{
    int hour,mint,elapse,total,h,m;
    scanf("%d:%d%d",&hour,&mint,&elapse);
    total=hour*60+mint+elapse;
    h=total/60;
    m=total%60;
    h=h%24;
    printf("%02d:%02d\n",h,m);
    return 0;
}
