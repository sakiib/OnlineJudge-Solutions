#include<bits/stdc++.h>
using namespace std;
int SQ(int x) {
    return (x*x);
}
double dist(int x1,int y1,int x2,int y2) {
    double val=sqrt(SQ(x1-x2)+SQ(y1-y2));
    return val;
}
int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    int a[1000],b[1000];
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
    }
    double res=0.0;
    for(int i=2;i<=n;i++) {
        res+=dist(a[i],b[i],a[i-1],b[i-1]);
    }
    cout<<setprecision(10)<<fixed<<(res/50.0)*k<<endl;
    return 0;
}
