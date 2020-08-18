#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
int main(int argc,char const *argv[]) {
    double l;
    int t;
    cin>>t;
    while(t--) {
        cin>>l;
        double w=6.0*l*0.1;
        double rad=l/5.0;
        double tot=l*w;
        double red=PI*rad*rad;
        printf("%0.2f %0.2f\n",red,(tot-red));
    }
    return 0;
}
