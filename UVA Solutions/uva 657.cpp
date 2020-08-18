#include<bits/stdc++.h>
using namespace std;

int r,c;
char str[55][55];

int main(int argc,char const *argv[]) {
    while(scanf("%d%d",&c,&r)) {
        if(r==0&&c==0) break;
        for(int i=0;i<r;i++) {
            scanf("%s",str[i]);
        }
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cout<<str[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
