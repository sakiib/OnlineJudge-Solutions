#include<bits/stdc++.h>
using namespace std;

const int N=10000;
bool know[N][N];
int degree[N]={0};

int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int a,b;
        cin>>a>>b;
        degree[a]++; degree[b]++;
        know[a][b]=true; know[b][a]=true;
    }
    int ans=100000000;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(know[i][j]) {
                for(int k=j+1;k<=n;k++) {
                    if(know[j][k]&&know[i][k]) {
                        ans=min(ans,degree[i]+degree[j]+degree[k]);
                    }
                }
            }
        }
    }
    if(ans==100000000) cout<<-1<<endl;
    else cout<<ans-6<<endl;
    return 0;
}
