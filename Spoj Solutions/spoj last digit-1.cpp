#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--){
      scanf("%d%d",&a,&b);
      if(a%10==0||a%10==1||a%10==5||a%10==6){
        printf("%d\n",a%10);
      }
      else if(a%10==4){
        if(b%2==0) puts("6");
        else puts("4");
      }
      else if(a%10==9){
        if(b%2==0) puts("1");
        else puts("9");
      }
      else{
        ll x=b%4;
        if(x==0){
            ll ans=(int)(pow(a%10,4));
            printf("%d\n",ans%10);
        }
        else{
            ll ans=(int)(pow(a%10,x));
            printf("%d\n",ans%10);
        }
      }
    }
    return 0;
}
