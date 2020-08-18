#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    map<char,int> M;
    for(auto c:str) {
        M[c]++;
        if(M[c]>k) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
