#include<bits/stdc++.h>
using namespace std;

int ara[200010]={0};

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    int n;
    map<int,int> M;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        M[ara[i]]++;
    }
    for(int i=1;i<=n;i++) {
        M[i]+=M[i-1];
    }
    int s=str.size();
    for(int i=0;i<str.size()/2;i++) {
        if(M[i+1]&1) swap(str[i],str[s-i+1]);
    }
    cout<<str<<endl;
    return 0;
}
