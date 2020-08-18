#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {

    int t;
    cin>>t;
    getchar();
    while(t--) {

        vector<string> V;
        V.clear();

        string str;
        getline(cin,str);

        stringstream iss(str);
        string s;

        while(iss>>s) {
           V.push_back(s);
        }
        if(V.size()==1) {
            string ans=V[0];
            if(ans[0]>='a'&&ans[0]<='z') ans[0]-=32;
            for(int i=1;i<ans.size();i++) {
                if(ans[i]>='A'&&ans[i]<='Z') ans[i]+=32;
            }
            cout<<ans<<endl;
        }
        if(V.size()==2) {
            string a=V[0],b=V[1];
            if(a[0]>='a'&&a[0]<='z') a[0]-=32;
            cout<<a[0]<<". ";
            if(b[0]>='a'&&b[0]<='z') b[0]-=32;
            for(int i=1;i<b.size();i++) {
                if(b[i]>='A'&&b[i]<='Z') b[i]+=32;
            }
            cout<<b<<endl;
        }
        if(V.size()==3) {
            string x=V[0],y=V[1],z=V[2];
            if(x[0]>='a'&&x[0]<='z') x[0]-=32;
            if(y[0]>='a'&&y[0]<='z') y[0]-=32;
            cout<<x[0]<<". "<<y[0]<<". ";
            if(z[0]>='a'&&z[0]<='z') z[0]-=32;
            for(int i=1;i<z.size();i++) {
                if(z[i]>='A'&&z[i]<='Z') z[i]+=32;
            }
            cout<<z<<endl;
        }
    }
    return 0;
}
