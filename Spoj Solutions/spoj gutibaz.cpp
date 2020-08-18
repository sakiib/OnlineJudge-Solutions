#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    int ara[10][10];
    while(t--) {
        int r,c;
        cin>>r>>c;
        memset(ara,0,sizeof(ara));
        ara[1][1]=1;
        for(int i=2;i<=c;i++) {
            ara[1][i]=1;
        }
        for(int i=2;i<=r;i++) {
            ara[i][1]=1;
        }
        for(int i=2;i<=r;i++) {
            for(int j=2;j<=c;j++) {
                ara[i][j]=ara[i-1][j]+ara[i][j-1];
            }
        }
        //cerr<<ara[2][3]<<endl;
        cout<<ara[r][c]<<endl;
    }
    return 0;
}
