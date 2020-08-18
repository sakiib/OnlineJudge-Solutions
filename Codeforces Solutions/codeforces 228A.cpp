#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n,num;
    cin>>n;
    vector<int> V;
    for(int i=0;i<n;i++) {
        cin>>num;
        V.push_back(num);
    }
    while(true) {
        sort(V.rbegin(),V.rend());
        bool found=false;
        for(int i=0;i<V.size()-1;i++) {
            if(V[i]>V[i+1]) {V[i]-=V[i+1]; found=true;}
        }
        if(!found) break;
    }
    int sum=0;
    for(auto &x : V) {
        sum+=x;
    }
    cout<<sum<<endl;
    return 0;
}
