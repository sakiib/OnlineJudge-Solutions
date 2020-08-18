#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct point{
    ll x,y;
};

ll calc(point A,point B,point C) {
    return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
}
int main(int argc,char const *argv[]) {
    point A,B,C;
    cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
    ll ans=calc(A,B,C);
    if(ans==0) cout<<"TOWARDS"<<endl;
    else if(ans>0) cout<<"LEFT"<<endl;
    else cout<<"RIGHT"<<endl;
    return 0;
}
