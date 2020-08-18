#include<bits/stdc++.h>
using namespace std;

bool palin(int h,int m) {
    if(h/10==m%10&&h%10==m/10) return true;
    else return false;
}
int main(int argc,char const *argv[]) {
    int h,m;
    scanf("%d:%d",&h,&m);
    while(true) {
        m++;
        if(m==60) {
            h++,m=0;
        }
        if(h==24) {
            h=0;
        }
        if(palin(h,m)) break;
    }
    printf("%02d:%02d\n",h,m);
    return 0;
}
