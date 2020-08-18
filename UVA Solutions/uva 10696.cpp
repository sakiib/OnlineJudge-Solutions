#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    if(n<=100) return (solve(solve(n+11)));
    else if(n>=101) return (n-10);
}
int main(int argc,char const *argv[]) {
    int n;
    while(scanf("%d",&n)&&n!=0) {
        int temp=n;
        int ans=solve(n);
        printf("f91(%d) = %d\n",temp,ans);
    }
    return 0;
}
