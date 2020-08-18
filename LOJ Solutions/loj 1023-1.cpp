#include<bits/stdc++.h>
using namespace std;
int t,tc,n,k,cnt=0;
char ans[30];
bool keep[26];
void solve(int ind)
{
    if(ind==n){
        if(k==cnt) return;
            cnt++;
            ans[ind]='\0';
            //puts(ans);
            for(int i=0;i<n;i++) {
                cout<<ans[i];
            }
            cout<<endl;
    }
        for(int i=0;i<n;i++){
            if(!keep[i]&&cnt<k){
            keep[i]=true;
            ans[ind]='A'+i;
            solve(ind+1);
            keep[i]=false;
          }
        }
}
void pro()
{
    memset(keep,false,sizeof(keep));
    cnt=0;
    solve(0);
}
int main()
{
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d%d",&n,&k);
        printf("Case %d:\n",tc);
        pro();
    }
    return 0;
}
