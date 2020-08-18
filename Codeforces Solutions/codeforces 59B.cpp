#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[10000];
    int mx=0;
    int sum=0;
    vector<int> odd;
    for(int i=0;i<n;i++) {
        cin>>ara[i];
        if(ara[i]&1){
           odd.push_back(ara[i]);
        }
        else sum+=ara[i];
    }
    if(n==1){
        if(ara[0]&1) cout<<ara[0]<<endl;
        else cout<<0<<endl;
        return 0;
    }
    if(odd.size()==0) {
        cout<<0<<endl;
        return 0;
    }
    sort(odd.rbegin(),odd.rend());
    if(odd.size()&1) {
        for(int i=0;i<odd.size();i++) {
            sum+=odd[i];
        }
    }
    else {
        for(int i=0;i<odd.size()-1;i++) {
            sum+=odd[i];
        }
    }
    //cout<<sum<< " "<<mx<<endl;
    cout<<sum+mx<<endl;
    return 0;
}
