#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int ara[N],ans[N];
int main( int argc,char const *argv[] ) {
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    set<int> S;
    for(int i=n;i>=1;i--) {
        S.insert(ara[i]);
        ans[i]=(int)(S.size());
    }
    while(q--) {
        int pos;
        scanf("%d",&pos);
        printf("%d\n",ans[pos]);
    }
    return 0;
}
