#include<bits/stdc++.h>
using namespace std;

string str[200];
vector<string> V;
int r,c;

int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    scanf("\n");
    for(int tc=1;tc<=t;tc++) {
        string s;
        while(getline(cin,s)) {
            if(s[0]!='L'&&s[0]!='W') break;
            V.push_back(s);
        }
        r=V.size(); c=V[0].size();
        for(int i=0;i<r;i++) {
            str[i]=V[i];
        }

    }
    return 0;
}
