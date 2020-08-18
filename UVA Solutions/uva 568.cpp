#include<bits/stdc++.h>
using namespace std;

int ans[100010];

void calc() {
    ans[0]=1;
    int sum=1;
    for(int i=1;i<=1000;i++) {
        sum=sum*i;
        while(sum%10==0) {
            sum/=10;
        }
        sum=sum%100000;
        ans[i]=sum%10;
    }
}
int main(int argc,char const *argv[]) {
    int n;
    calc();
    while(scanf("%d",&n)!=EOF) {
       printf("%5d -> %d\n",n,ans[n]);
    }
    return 0;
}
