#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1.0);

int main(int argc,char const *argv[]) {
    int t,tc;
    cin>>t;
    for(tc=1;tc<=t;tc++) {
        double R,n;
        cin>>R>>n;
        double ans=(sin(PI/n)*R)/(1.0+sin(PI/n));
        printf("Case %d: %.10lf\n",tc,ans);
    }
    return 0;
}
