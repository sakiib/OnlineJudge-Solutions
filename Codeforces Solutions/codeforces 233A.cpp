#include<bits/stdc++.h>
using namespace std;

void solve(int n) {
    int ara[1000];
    for(int i=1;i<=n;i++) {
        ara[i]=i;
    }
    for(int i=1;i<=n;i+=2) {
        swap(ara[i],ara[i+1]);
    }
    for(int i=1;i<=n;i++) {
        cout<<ara[i]<< " ";
    }
    return;
}
void NO() {
    cout<<-1<<endl;
    exit(0);
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    if(n&1) NO();
    solve(n);
    return 0;
}
