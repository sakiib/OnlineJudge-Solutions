#include<bits/stdc++.h>
using namespace std;

int calc(int n) {
    int sum=0;
    for(int i=5;n/i>=1;i*=5) {
        sum+=(n/i);
    }
    return sum;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        int ans=calc(n);
        printf("%d\n",ans);
    }
    return 0;
}
