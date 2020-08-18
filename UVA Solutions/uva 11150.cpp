#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    while(scanf("%d",&n)!=EOF) {
        int ans=n;
        while(n>=3) {
            ans+=(n/3);
            n=n/3+n%3;
        }
        if(n==2) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
