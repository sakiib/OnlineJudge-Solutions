#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    int x1,x2,y1,y2,x,y;
    cin>>x1>>y1>>x2>>y2;
    cin>>x>>y;
    if(abs(x2-x1)%x==0&&abs(y2-y1)%y==0&&
       ((abs(x2-x1)/x)%2==(abs(y2-y1)/y)%2)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
