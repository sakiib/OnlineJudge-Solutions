#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    bool k=false;
    for(int tc=1;tc<=t;tc++) {
        if(k) printf("\n");
        k=true;
        int n;
        scanf("%d",&n);
        int a[30][30],b[30][30];

        for(int i=1;i<=26;i++) {
            for(int j=1;j<=26;j++) {
                if(i==j) a[i][j]=1,b[i][j]=1;
                else a[i][j]=0,b[i][j]=0;
            }
        }

        for(int i=1;i<=n;i++) {
            string x,y;
            cin>>x>>y;
            int u=x[0]-'A'+1;
            int v=y[0]-'A'+1;
            a[u][v]=1; a[v][u]=1;
        }
        for(int k=1;k<=26;k++) {
            for(int i=1;i<=26;i++) {
                for(int j=1;j<=26;j++) {
                    a[i][j]=a[i][j]|(a[i][k]&a[k][j]);
                }
            }
        }
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++) {
            string x,y;
            cin>>x>>y;
            int u=x[0]-'A'+1;
            int v=y[0]-'A'+1;
            b[u][v]=1; b[v][u]=1;
        }
        for(int k=1;k<=26;k++) {
            for(int i=1;i<=26;i++) {
                for(int j=1;j<=26;j++) {
                    b[i][j]=b[i][j]|(b[i][k]&b[k][j]);
                }
            }
        }
        bool f=true;
        for(int i=1;i<=26;i++) {
            for(int j=1;j<=26;j++) {
                if(a[i][j]!=b[i][j]) f=false;
            }
        }
        if(f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
