#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,f,a,sum=0,x,ans=0;
    set<int> S;
    cin>>n;
    for(int i=1,j=0;i<=101;i++,j+=n) {
        S.insert(j+i);
    }
    for(int i=0;i<n;i++) {
        cin>>x;
        sum+=x;
    }
    for(int i=1;i<=5;i++) {
        if(S.find(sum+i)!=S.end()){
            continue;
        }
        else ans++;
    }
    cout<<ans<<endl;
    return 0;
}

