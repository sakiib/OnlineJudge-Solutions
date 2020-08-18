#include<bits/stdc++.h>
using namespace std;
#define Founds(x,y) (x.find(y)!=string::npos)
int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    string temp[11];
    map<string,int> M;
    for(int i=0;i<10;i++) {
        cin>>temp[i];
        M[temp[i]]=i;
    }
    for(int i=0;i<80;i+=10) {
        int k=M[str.substr(i,10)];
        cout<<k;
    }
    return 0;
}
