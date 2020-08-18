#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int a,b;
    while(cin>>a>>b) {
        if(a==0&&b==0) break;
        int cnt=0;
        for(int i=a;i<=b;i++) {
            int k=sqrt(i);
            if(k*k==i) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
