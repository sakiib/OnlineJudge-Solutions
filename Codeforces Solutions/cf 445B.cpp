#include<bits/stdc++.h>
using namespace std;

int cnt[2*100005];
int ara[2*100005];

int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
        cnt[ara[i]]++;
    }
    for(int i=1;i<=n;i++) {
        cnt[ara[i]]--;
        if(cnt[ara[i]]==0) {
            printf("%d\n",ara[i]);
            return 0;
        }
    }
    return 0;
}
