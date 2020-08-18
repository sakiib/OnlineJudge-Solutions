#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

map <int,int> A , B;

int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        int x , y;
        scanf("%d%d",&x,&y);
        A[x+y]++ , B[x-y]++;
    }
    LL ans = 0;
    for (auto x : A) {
        ans += (x.second * (x.second - 1) / 2);
    }
    for (auto x : B) {
        ans += (x.second * (x.second - 1) / 2);
    }
    printf("%lld\n",ans);
    return 0;
}
