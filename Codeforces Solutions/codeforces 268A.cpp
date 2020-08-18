#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,ans=0;
    int A[10001],B[10001];
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>A[i]>>B[i];
    }
    for(int i=0;i<n-1;i++) {
        int t=A[i];
        for(int j=i+1;j<n;j++) {
            if(B[j]==t) ans++;
        }
    }
    for(int i=0;i<n-1;i++) {
        int t=B[i];
        for(int j=i+1;j<n;j++) {
            if(A[j]==t) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
