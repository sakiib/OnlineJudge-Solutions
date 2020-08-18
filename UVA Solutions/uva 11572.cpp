#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        set<long long> S;
        long long mx=0;
        for(long long i=1;i<=n;i++) {
            long long val;
            cin>>val;
            S.insert(val);
        }
        mx=(long long) (S.size());
        for(auto x:S) {
            cout<<x<<" ";
        }
        //cout<<mx<<endl;
        S.clear();
    }
    return 0;
}

