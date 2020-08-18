#include<bits/stdc++.h>
using namespace std;

int r,c;
int ara[105][105];

int main(int argc,char const *argv[]) {
    while(scanf("%d%d",&r,&c)) {
        if(r==0&&c==0) break;
        for(int i=1;i<=r;i++) {
            for(int j=1;j<=c;j++) {
                cin>>ara[i][j];
                if(ara[i][j]==0) ara[i][j]=1;
                else ara[i][j]=0;
            }
        }
        cout<<endl;
        for(int i=1;i<=r;i++) {
            for(int j=1;j<=c;j++) {
                cout<<ara[i][j]<< " ";
            }
            cout<<endl;
        }
    }
    return 0;
}
