#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> M;
    M.clear();
    int n,mx=0;
    string team;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        M[str]++;
    }

    map<string,int> :: iterator it;
    for(it=M.begin();it!=M.end();it++){
        if(it->second>mx){
            team=it->first;
            mx=it->second;
        }
    }
    cout<<team<<endl;
    return 0;
}
