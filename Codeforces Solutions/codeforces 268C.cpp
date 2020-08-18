#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc,char const *argv[]) {
    int m,n,x;
    cin>>m>>n;
    x=min(m,n);
    cout<<x+1<<endl;
    for(int i=0;i<=x;i++) {
        cout<<i<< " " <<x-i<<endl;
    }
    return 0;
}
