#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    while(scanf("%d",&n)) {
       if(n==0) break;
       bool found=false;
       int a,b;
       for(int i=0;i<=100;i++) {
         for(int j=0;j<=100;j++) {
             if(i*i*i-j*j*j==n) {
                found=true;
                a=i,b=j;
                break;
             }
             //cerr<<i<< " "<<j<< " "<<i*i*i-j*j*j<<endl;
         }
         if(found) break;
       }
       if(found) {
        cout<<a<< " "<<b<<endl;
        continue;
       }

       for(int j=0;j<=100;j++) {
         for(int i=0;i<=100;i++) {
             if(j*j*j-i*i*i==n) {
                found=true;
                a=j,b=i;
                break;
             }
         }
         if(found) break;
       }
       if(found) {
        cout<<a<< " "<<b<<endl;
       }
       else cout<<"No solution"<<endl;
    }
    return 0;
}
