#include<bits/stdc++.h>
using namespace std;

map<pair<char,char>,int> M;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<n-1;i++) {
       if(str[i]==str[i+1]) continue;
       else M[{str[i],str[i+1]}]++;
    }
    int a=0,b=0;
    a=M[{'S','F'}]; b=M[{'F','S'}];
    if(a>b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
