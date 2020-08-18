#include<bits/stdc++.h>
using namespace std;

int n,k;
char ans[1000];
bool used[1000];
int taken=0;

void solve(int idx) {
    if(idx==n) {
        if(taken>k) return;
        taken++;
        ans[idx]='\0';
        for(int i=0;i<n;i++) {
            cout<<ans[i];
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++) {
        if(!used[i]&&taken<k) {
            ans[idx]='A'+i;
            used[i]=true;
            solve(idx+1);
            used[i]=false;
        }
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%d%d",&n,&k);
        printf("Case %d:\n",tc);
        taken=0;
        solve(0);
    }
    return 0;
}
