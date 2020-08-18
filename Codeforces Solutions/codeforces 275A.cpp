#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ara[5][5];
    int ans[5][5];

    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            ans[i][j]=1;
        }
    }
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            cin>>ara[i][j];
        }
    }
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            if(ara[i][j]%2==0&&ara[i][j]!=0) {
                continue;
            }
            else if(ara[i][j]%2==1) {
                if(ans[i][j]==1) ans[i][j]=0;
                else ans[i][j]=1;
                if(ans[i-1][j]==1) ans[i-1][j]=0;
                else ans[i-1][j]=1;
                if(ans[i][j-1]==1) ans[i][j-1]=0;
                else ans[i][j-1]=1;
                if(ans[i][j+1]==1) ans[i][j+1]=0;
                else ans[i][j+1]=1;
                if(ans[i+1][j]==1) ans[i+1][j]=0;
                else ans[i+1][j]=0;
            }
        }
    }
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}
