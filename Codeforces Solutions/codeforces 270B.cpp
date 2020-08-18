#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }
    int cnt=0;
    int i=n;
    while(i>1&&ara[i-1]<ara[i]) {
        i--;
    }
    cout<<max(0,i-1)<<endl;
    return 0;
}
