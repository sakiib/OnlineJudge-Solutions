#include<bits/stdc++.h>
using namespace std;


void print_answer(int sum,int n) {
    setprecision(10);
    cout<<fixed<<(1.0*sum/n)<<endl;
    return;
}
int solve(int n,int *ara) {
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=ara[i];
    }
    print_answer(sum,n);
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[10010];
    for(int i=0;i<n;i++) {
        cin>>ara[i];
    }
    solve(n,ara);
    return 0;
}
