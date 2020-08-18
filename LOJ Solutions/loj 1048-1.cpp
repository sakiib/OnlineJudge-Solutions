#include<bits/stdc++.h>
using namespace std;

const int N=1005;
const int inf=100000000;

int n,k,ara[N];

bool possible(int d) {
    int c=0, dist=0;
    for(int i=1;i<=n+1;i++) {
        if(dist+ara[i]<=d) {
            dist+=ara[i];
        }
        else dist=ara[i],c++;
    }
    //printf("dist : %d %d\n",dist,c);
    if(c<=k) return true;
    else return false;
}
int Binary_Search(int lo,int hi) {
    int ret=-1;
    while(lo<=hi) {
        int mid=(lo+hi)/2;
        if(possible(mid)) {
            ret=mid;
            hi=mid-1;
            //printf("mid : %d\n",ret);
        }
        else lo=mid+1;
    }
    return ret;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        scanf("%d%d",&n,&k);
        int x=-inf, y=0;
        for(int i=1;i<=n+1;i++) {
            scanf("%d",&ara[i]);
            x=max(x,ara[i]);
            y+=ara[i];
        }
        int mx=Binary_Search(x,y);
        printf("Case %d: %d\n",tc,mx);
        int res=ara[1], idx=1;
        vector<int> ans;
        for(int i=2;i<=n+1;i++) {
            if(k-idx==(n-i+1)) {
                idx++;
                ans.push_back(res);
                res=ara[i];
            }
            else if(res+ara[i]>mx) {
                idx++;
                ans.push_back(res);
                res=ara[i];
            }
            else res+=ara[i];
        }
        ans.push_back(res);
        for(int i=0;i<ans.size();i++) {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
