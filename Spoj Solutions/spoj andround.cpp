#include<bits/stdc++.h>
using namespace std;

const int N=20005;
int ara[N];

int main(int argc,char const *argv[]) {
    cout<<(1&11)<<" "<<(1&11&111)<<" "<<(11&111&1111)<<endl;
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
        }
    }
    return 0;
}
