#include<bits/stdc++.h>
using namespace std;
int ara[20][20];
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int i,j;
    for( i=n+1,j=1;j<=n+1;j++) {
        ara[i][j]=(j-1);
    }
    for(int i=n+1,k=n+2,j=n;j>=1;j--,k++) {
        ara[i][k]=ara[i][j];
    }
    /*for(int i=1;i<=2*n+1;i++) {
        for(int j=1;j<=2*n+1;j++) {
            cout<<ara[i][j]<< " ";
        }
        cout<<endl;
    }*/
    for(int i=n+2;i<=2*n+1;i++) {
        for(int j=1;j<=2*n+1;j++) {
            if(ara[i-1][j]==0||ara[i-1][j]==-1) {
                ara[i][j]=-1;
            }
            else ara[i][j]=(ara[i-1][j]-1);
        }
    }
    int k=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=2*n+1;j++) {
            ara[i][j]=ara[2*n+1-k][j];
        }
        k++;
    }

    for(int i=1;i<=2*n+1;i++) {
        for(int j=1;j<=2*n+1;j++) {
             if(ara[i][j]!=-1) cout<<ara[i][j]<< " ";
             else cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}
