#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    if(n==1&&k==0) {
        cout<<1<<endl; return 0;
    }
    if(n==1&&k>0) {
        cout<<-1<<endl; return 0;
    }
    if(k<(n/2)) {
        cout<<-1<<endl; return 0;
    }
    if(k==(n/2)) {
        for(int i=1;i<=n;i++) {
            cout<<i<<" ";
        }
        cout<<endl;
        return 0;
    }
    int x=k-(n-2)/2;
    cout<<x<<" "<<2*x<<" ";
    int t=2*x+1;
    for(int i=2;i<n;i++,t++) cout<<t<<" ";
    cout<<endl;
    return 0;
}
