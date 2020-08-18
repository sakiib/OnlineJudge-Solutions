#include<bits/stdc++.h>
using namespace std;

int n,h;
double total,base=1.0,one,low=0.0,high,mid,area=0.0;
double ans,a,single;

void solve(double a)
{
    double low=0,high=h,new_base;
    int time=10000;
    while(time--){
        mid=(low+high)/2.0;
        new_base=mid/h;
        area=0.5*new_base*mid;
        if(area>a){
            high=mid;
          //  printf("%lf\n",high);
        }
        else if(area<a){
            low=mid;
          //  printf("%lf\n",low);
        }
    }
    printf("%.10lf ",mid);
}
int main()
{
    scanf("%d%d",&n,&h);
    total=(0.5*base*h);
   // printf("%.10lf",total);
    one=total/n;
   // printf("%.10lf\n",single);
    n--;
    a=one;
    while(n--){
       solve(a);
       a+=one;
    }
    return 0;
}
