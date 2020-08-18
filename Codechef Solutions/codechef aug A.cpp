#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        int n,ls,le;
        cin>>n>>ls>>le;
        double ts=sqrt(2)*n*1.0/ls;
        double te=2.0*n/(le*1.0);
        //cerr<<ts<< " "<<te<<endl;
        if(ts<te) cout<<"Stairs"<<endl;
        else cout<<"Elevator"<<endl;
    }
    return 0;
}
