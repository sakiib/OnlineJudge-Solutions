#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string a,b;
    cin>>a>>b;
    map<char,int> F,S;

    for(int i=0;i<b.size();i++) {
        S[b[i]]++;
    }
    int y=0,n=0;
    vector<char> baki;
    for(int i=0;i<a.size();i++) {
        if(S[a[i]]!=0) {
            y++;
            S[a[i]]--;
        }
        else baki.push_back(a[i]);
    }
    for(int i=0;i<baki.size();i++) {
        if(baki[i]>='a'&&baki[i]<='z') {
            if(S[baki[i]-32]>0) {
                n++; S[(baki[i]-'0'-32)+'0']--;
            }
        }
        if(baki[i]>='A'&&baki[i]<='Z') {
            if(S[baki[i]+32]>0) {
                n++; S[(baki[i]-'0'+32)+'0']--;
            }
        }
    }
    cout<<y<< " "<<n<<endl;
    return 0;
}
