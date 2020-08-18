#include<bits/stdc++.h>
using namespace std;

const int N=100005;
const int inf=1000000000;

int ara[N];

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int n,d;
        scanf("%d%d",&n,&d);
        deque<int> Q;
        int m=-inf;
        for(int i=1;i<=n;i++) {
           scanf("%d",&ara[i]);
        }
        int mx=-inf,mn=inf,ans=-inf;
        for(int i=1;i<=n;i++) {
           Q.push_back(ara[i]);
           if(Q.size()==d) {
            mx=max(mx,Q.back());
            mn=min(mn,Q.front());
            cout<<"mx  mn : "<<mx<<" "<<mn<<endl;
            ans=max(ans,abs(mx-mn));
            Q.pop_front();
           }
        }
        ans=max(mx,abs(mx-mn));
        printf("Case %d: %d\n",tc,max(0,ans));
        while(!Q.empty()) Q.pop_front();
    }
    return 0;
}
