#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int ara[N];
int n;

void inc() {
    for(int i=2;i<=n;i++) {
        if(ara[i]<=ara[i-1]) return;
    }
    printf("yes\n");
    printf("1 1");
    exit(0);
}
void dec() {
    for(int i=2;i<=n;i++) {
        if(ara[i]>ara[i-1]) return;
    }
    printf("yes\n");
    printf("1 %d\n",n);
    exit(0);
}
int main(int argc,char const *argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    inc();
    dec();
    int st=0,en=n;
    bool f=false;
    for(int i=1;i<=n;i++) {
        if(ara[i+1]<ara[i]&&!f) {
            f=true;
            st=i;
        }
        if(f&&ara[i]<ara[i+1]) {
            en=i;break;
        }
    }
    sort(ara+st,ara+en+1);
    bool k=true;
    for(int i=2;i<=n;i++) {
       if(ara[i]<=ara[i-1]) {
         k=false;
         break;
       }
    }
    if(k) {
        printf("yes\n");
        printf("%d %d\n",st,en);
        return 0;
    }
    printf("no\n");
    return 0;
}
