#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    vector<int> V(n);
    for(int i=0;i<n;i++) {
        cin>>V[i];
    }
    int sum=0;
    sort(V.begin(),V.end());
    for(int i=0;i<k;i++) {
        if(V[i]<0) sum+=(-1*V[i]);
    }
    cout<<sum<<endl;
    return 0;
}
