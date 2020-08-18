#include<bits/stdc++.h>
using namespace std;

inline int st_int(string &str) {
    int num; stringstream st(str);
    st>>num; return num;
}
const int inf=100000000;
int ara[105][105];

int main(int argc,char const *argv[]) {
    int n;
    while(scanf("%d",&n)!=EOF) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) ara[i][j]=0;
                else ara[i][j]=inf;
            }
        }
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                string str;
                cin>>str;
                if(str=="x") {
                    ara[i][j]=ara[j][i]=inf;
                }
                else {
                    int val=st_int(str);
                    ara[i][j]=ara[j][i]=val;
                }
            }
        }
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    ara[i][j]=min(ara[i][j],ara[i][k]+ara[k][j]);
                }
            }
        }
        int mx=0;
        for(int i=1;i<n;i++) {
            mx=max(mx,ara[0][i]);
        }
        printf("%d\n",mx);
    }
    return 0;
}
