#include<bits/stdc++.h>
using namespace std;

int mat[10][10];
int r=0,c=0;
int main(int argc,char const *argv[]) {
    for(int i=1;i<=5;i++) {
        for(int j=1;j<=5;j++) {
            scanf("%d",&mat[i][j]);
            if(mat[i][j]==1) {
                r=i,c=j;
            }
        }
    }
    int ans=abs(3-r)+abs(3-c);
    printf("%d\n",ans);
    return 0;
}
