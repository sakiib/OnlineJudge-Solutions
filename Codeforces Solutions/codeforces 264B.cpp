#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    set<int> S;
    long long sum=0;
    for(int i=0;i<n;i++) {
        cin>>ara[i];
        sum+=ara[i];
        S.insert(ara[i]);
    }
    if(S.size()==1) {
        cout<<n<<endl;
        return 0;
    }
    if(sum%n==0) {
        cout<<n<<endl;
    }
    else cout<<n-1<<endl;
    return 0;
}
