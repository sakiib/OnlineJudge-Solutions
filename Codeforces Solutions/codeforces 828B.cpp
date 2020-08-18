#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    char str[105][105];
    for(int i=1;i<=n;i++) {
        cin>>str[i];
    }
    int ui=0,uj=0,di=0,dj=0;
    int cnt=0;
    for(int i=1;i<=n;i++) {
        string s=str[i];
        for(int j=1;j<=m;j++) {
            if(s[i][j]=='B') {
                cnt++;
                ui=min(ui,i); di=max(di,i);
                uj=min(uj,j); dj=max(dj,j);
            }
        }
    }
    cout<<ui<<" "<<uj<<" "<<di<<" "<<dj<<endl;
    if(cnt==0) {
        cout<<1<<endl;
        return 0;
    }
    int a=max(di-ui,dj-uj)+1;
    if(a>m||a>n) cout<<-1<<endl;
    else cout<<a*a-cnt<<endl;
    return 0;
}
