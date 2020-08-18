#include<bits/stdc++.h>
using namespace std;

int A[]={0,1,2};

int main(int argc,char const *argv[]) {
    long long n,x;
    cin>>n>>x;
    n%=6;
    for(int i=1;i<=n;i++) {
        if(i&1) swap(A[0],A[1]);
        else swap(A[1],A[2]);
    }
    cout<<A[x]<<endl;
    return 0;
}
