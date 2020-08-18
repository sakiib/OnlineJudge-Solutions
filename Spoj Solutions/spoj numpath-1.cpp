#include<bits/stdc++.h>
using namespace std;

int r,c;

int rec(int x,int y) {
    int sum=0;
    if(x==r&&y==c) return 1;
    if(x<r) sum+=rec(x+1,y);
    if(y<c) sum+=rec(x,y+1);
    return sum;
}
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        cin>>r>>c;
        int ans=rec(1,1);
        cout<<ans<<endl;
    }
    return 0;
}
