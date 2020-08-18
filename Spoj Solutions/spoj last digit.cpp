#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    scanf("%d",&t);

    int s2[]={6,2,4,8},s3[]={1,3,9,7},s4[]={6,4},

    s7[]={1,7,9,3},s8[]={6,8,4,2},s9[]={1,9};

  while(t--)
   {
     long long b,a;

     scanf("%lld%lld",&a,&b);

     int x=b%4,y=b%2;

     if(b==0) {
       printf("1\n"); continue;
     }
     if(a%10==1||a%10==5||a%10==6) printf("%d\n",a%10);

     if(a%10==0) printf("0\n");

     if(a%10==2) printf("%d\n",s2[x]);

     if(a%10==3) printf("%d\n",s3[x]);

     if(a%10==4) printf("%d\n",s4[y]);

     if(a%10==7) printf("%d\n",s7[x]);

     if(a%10==8) printf("%d\n",s8[x]);

     if(a%10==9) printf("%d\n",s9[y]);

     }
     return 0;
}
