#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    vector<int> temp,ans;
    for(int i=0;i<a.size();i++) {
        temp.push_back(i+1);
    }
    int mn=temp.size();
    for(int i=0;i<=m-n;i++) {
            ans.clear();
        for(int j=0;j<n;j++) {
            if(a[j]!=b[i+j]) {
                ans.push_back(j+1);
            }
        }
        if(ans.size()<temp.size()) {
            temp=ans;
        }
    }
    int sz=temp.size();
    cout<<sz<<endl;
    for(int i=0;i<temp.size();i++) {
        cout<<temp[i]<< " ";
    }

    return 0;
}
