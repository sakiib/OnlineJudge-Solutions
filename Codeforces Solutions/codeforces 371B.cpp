#include<bits/stdc++.h>
using namespace std;
int x_1,x_2,y_1,y_2,z_1,z_2;
int main()
{
    int a,b,ans=0;
    cin>>a>>b;
    int p=__gcd(a,b);
    a=a/p;b=b/p;
    while(a%2==0){
        a=a/2;
        x_1++;
    }
    while(a%3==0){
        a=a/3;
        y_1++;
    }
    while(a%5==0){
        a=a/5;
        z_1++;
    }
    while(b%2==0){
        b=b/2;
        x_2++;
    }
    while(b%3==0){
        b=b/3;
        y_2++;
    }
    while(b%5==0){
        b=b/5;
        z_2++;
    }
    if(a>1||b>1||(a!=b)){
        cout<<-1;
    }
    else{
        ans+=abs(x_2-x_1)+abs(y_2-y_1)+abs(z_2-z_1);
        cout<<ans;
    }
    return 0;
}
