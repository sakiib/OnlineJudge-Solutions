#include<bits/stdc++.h>
using namespace std;

void NO() {
    cout<<-1<<endl;
    exit(0);
}
bool dist(int *ara,int n) {
    set<int> S;
    for(int i=0;i<n;i++) {
        S.insert(ara[i]);
        if(S.size()>1) return false;
    }
    if(S.size()==1) return true;
}
bool ok(int *ara,int n,int i,int j) {
    swap(ara[i],ara[j]);
    bool sorted=true;
    for(int i=0;i<n-1;i++) {
        if(ara[i]<=ara[i+1]) continue;
        else {
            sorted=false; break;
        }
    }
    if(sorted) {
        swap(ara[i],ara[j]);
        return false;
    }
    bool rev=true;
    for(int i=0;i<n-1;i++) {
        if(ara[i]>=ara[i+1]) continue;
        else {
            rev=false; break;
        }
    }
    if(rev) {
        swap(ara[i],ara[j]);
        return false;
    }
    swap(ara[i],ara[j]);
    return true;
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    for(int i=0;i<n;i++) {
        cin>>ara[i];
    }
    if(n==1||n==2) NO();
    if(dist(ara,n)) NO();
    for(int i=0;i<n-1;i++) {
        if(ara[i]!=ara[i+1]) {
           if(ok(ara,n,i,i+1)) {
             cout<<i+1<< " "<<i+2<<endl;
             return 0;
           }
        }
    }
    NO();
    return 0;
}
