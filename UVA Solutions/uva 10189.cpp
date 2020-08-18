#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int m,n,tc=1;
    while(scanf("%d%d",&m,&n)) {
        if(m==0&&n==0) break;
        char str[105][105];
        int ans[105][105];
        if(tc!=1) cout<<endl;
        memset(str,'\0',sizeof(str));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<m;i++) {
            cin>>str[i];
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(str[i][j]=='*') ans[i][j]=-1;
                else {
                    if(str[i+1][j]=='*')   ans[i][j]++;
                    if(str[i][j+1]=='*')   ans[i][j]++;
                    if(str[i-1][j]=='*')   ans[i][j]++;
                    if(str[i][j-1]=='*')   ans[i][j]++;
                    if(str[i+1][j+1]=='*') ans[i][j]++;
                    if(str[i-1][j-1]=='*') ans[i][j]++;
                    if(str[i+1][j-1]=='*') ans[i][j]++;
                    if(str[i-1][j+1]=='*') ans[i][j]++;
                }
            }
        }
        printf("Field #%d:\n",tc);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(ans[i][j]==-1) cout<<"*";
                else cout<<ans[i][j];
            }
            cout<<endl;
        }
        tc++;
    }
    return 0;
}
