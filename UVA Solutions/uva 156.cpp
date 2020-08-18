#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str;
    vector<string> V;
    vector<string> ans;
    map<string,int> M;

    while(cin>>str) {
        if(str=="#") break;#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str;
    vector<string> V;
    vector<string> ans;
    map<string,int> M;

    while(cin>>str) {
        if(str=="#") break;
        V.push_back(str);
        string k=str;
        for(int i=0;i<k.size();i++) {
            if(k[i]>='A'&&k[i]<='Z') k[i]-='A',k[i]+='a';
        }
        sort(k.begin(),k.end());
        M[k]++;
    }
    for(int i=0;i<V.size();i++) {
        string temp=V[i];
        for(int j=0;j<temp.size();j++) {
            if(temp[j]>='A'&&temp[j]<='Z') temp[j]-='A',temp[j]+='a';
        }
        sort(temp.begin(),temp.end());
        if(M[temp]==1) ans.push_back(V[i]);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}

        V.push_back(str);
        string k=str;
        for(int i=0;i<k.size();i++) {
            if(k[i]>='A'&&k[i]<='Z') k[i]-='A',k[i]+='a';
        }
        sort(k.begin(),k.end());
        M[k]++;
    }
    for(int i=0;i<V.size();i++) {
        string temp=V[i];
        for(int j=0;j<temp.size();j++) {
            if(temp[j]>='A'&&temp[j]<='Z') temp[j]-='A',temp[j]+='a';
        }
        sort(temp.begin(),temp.end());
        if(M[temp]==1) ans.push_back(V[i]);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
