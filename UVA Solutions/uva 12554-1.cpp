#include<bits/stdc++.h>
using namespace std;

string s[100]={"Happy","birthday","to","you","Happy","birthday","to","you",
          "Happy","birthday","to","Rujia","Happy","birthday","to","you"};

int main(int argc,char const *argv[]) {
    int n;
    while(scanf("%d",&n)!=EOF) {
        vector<string> V;
        for(int i=1;i<=n;i++) {
            string str;
            cin>>str;
            V.push_back(str);
        }
        int idx=0,i=0;
        int k=n/16;
        if(n%16!=0) k++;

        while(i<16*k) {
            cout<<V[i%n]<<": "<<s[idx%16]<<endl;
            i++,idx++;
        }
    }
    return 0;
}
