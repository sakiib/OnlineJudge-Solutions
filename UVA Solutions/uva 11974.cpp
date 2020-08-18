#include<bits/stdc++.h>
using namespace std;

int ara[105][105];

int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                scanf("%d",&ara[i][j]);
            }
        }
    }
    return 0;
}
