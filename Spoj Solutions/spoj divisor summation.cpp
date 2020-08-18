#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        if(n==1) {printf("%d\n",0); continue; }
        int sq=sqrt(n);
        int sum=1;
        for(int i=2;i<=sq;i++) {
            if(n%i==0) {
                if(n/i!=i) sum+=(n/i)+i;
                else sum+=i;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
