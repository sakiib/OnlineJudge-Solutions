#include<bits/stdc++.h>
using namespace std;

stack<string> S;
map<string,bool> M;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    while(n--) {
        string str;
        cin>>str;
        S.push(str);
    }
    while(!S.empty()) {
        string x=S.top();
        S.pop();
        if(!M[x]) {
        cout<<x<<endl;
        M[x]=true;
        }
    }
    return 0;
}
