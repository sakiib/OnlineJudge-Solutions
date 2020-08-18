#include<bits/stdc++.h>
using namespace std;
bool vowel(char ch) {
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return true;
    return false;
}
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    int t=3;
    while(t--) {
        getline(cin,str);
        //cout<<str<<endl;
        int cnt=0;
        for(auto x:str) {
            if(vowel(x)) cnt++;
        }
        if(t==2) {
            if(cnt!=5) {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if(t==1) {
            if(cnt!=7) {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if(t==0) {
            if(cnt!=5) {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}

