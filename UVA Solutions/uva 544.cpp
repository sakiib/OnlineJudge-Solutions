#include<bits/stdc++.h>
using namespace std;

map<string,int> M;

int main(int argc,char const *argv[]) {
    int n,k,tc=1;

    while(scanf("%d%d",&n,&k)) {
        if(n==0&&k==0) break;
        int idx=0;
        int ara[300][300];

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i==j) ara[i][j]=0;
                else ara[i][j]=0;
            }
        }
        for(int i=1;i<=k;i++) {
            string a,b;
            int c;
            cin>>a>>b>>c;
            if(M[a]==0) M[a]=++idx;
            if(M[b]==0) M[b]=++idx;
            ara[M[a]][M[b]]=c;
            ara[M[b]][M[a]]=c;
        }
        string st,en;
        cin>>st>>en;
        for(int k=1;k<=n;k++) {
            for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                ara[i][j]=max(ara[i][j],min(ara[i][k],ara[k][j]));
            }
          }
        }
        printf("Scenario #%d\n",tc++);
        printf("%d tons\n",ara[M[st]][M[en]]);

        printf("\n");
    }
    return 0;
}
