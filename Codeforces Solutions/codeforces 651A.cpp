#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,x,y,cnt=0;
    cin>>a>>b;
    if(a==1&&b==1){
        cout<<0<<endl;
        return 0;
    }
    x=a;y=b;
    while(x>0&&y>0){
         x=min(a,b);
         y=max(a,b);
         x++;y-=2;
         a=x;b=y;
         cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
