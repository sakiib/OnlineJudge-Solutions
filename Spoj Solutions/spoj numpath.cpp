#include<bits/stdc++.h>
using namespace std;

int r,c;
int ans=0;

void rec(int x,int y) {
    if(x==r&&y==c) {
        ans++;
        //cerr<<"here"<<endl;
    }
    if(y+1<=c)  rec(x,y+1);
    if(x+1<=r)  rec(x+1,y);
}
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        cin>>r>>c;
        //cout<<"ans : "<<rec(1,1)<<endl;
        ans=0;
        rec(1,1);
        cout<<ans<<endl;
    }
    return 0;
}
