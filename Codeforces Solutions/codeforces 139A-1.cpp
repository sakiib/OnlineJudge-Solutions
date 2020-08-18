#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[10010];
    for(int i=0;i<7;i++) {
        cin>>ara[i];
    }
    while(true) {
        for(int i=0;i<7;i++) {
            n-=ara[i];
            if(n<=0) {
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
    return 0;
}
