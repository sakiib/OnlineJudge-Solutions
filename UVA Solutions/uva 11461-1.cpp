#include<bits/stdc++.h>
using namespace std;

int val[100010]={0};

bool yes(int x) {
    int k=sqrt(x);
    if(k*k==x) return true;
    return false;
}
void calc() {
    val[0]=0;
    for(int i=1;i<=100005;i++) {
        if(yes(i)) val[i]=1;
        val[i]+=val[i-1];
    }
}
int main(int argc,char const *argv[]) {
    int a,b;
    calc();
    while(scanf("%d%d",&a,&b)) {
        if(a==0&&b==0) break;
        a--;
        printf("%d\n",val[b]-val[a]);
    }
    return 0;
}
