#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        int angle;
        cin>>angle;
        //180*(n-2)=angle*n;
        //180*n-angle*n=360;
        //n*(180-angle)=360;
        //n=360/(180-angle);
        int temp=180-angle;
        if(360%temp==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
