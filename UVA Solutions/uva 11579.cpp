#include<bits/stdc++.h>
using namespace std;

double ara[100010];

double calc(double a,double b,double c) {
    double s=(a+b+c)/2.0;
    double res=sqrt(s*(s-a)*(s-b)*(s-c));
    return res;
}
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>ara[i];
        }
        sort(ara,ara+n);
        reverse(ara,ara+n);
        double mx=0.0;
        double ans=0.0;
        for(int i=0;i<n-2;i++) {
            if(ara[i+1]+ara[i+1]>ara[i]) {
                ans=calc(ara[i],ara[i+1],ara[i+2]);
            }
            if(ans>mx) {
                mx=ans;
            }
        }
        printf("%0.2f\n",mx);
    }
    return 0;
}
