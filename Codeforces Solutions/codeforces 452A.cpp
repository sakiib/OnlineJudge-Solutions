#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {

    string pok[10]={"jolteon","flareon",
                    "umbreon","leafeon",
                    "glaceon","sylveon"};

    int n;
    cin>>n;
    string str;
    cin>>str;
    if(n==8) {
        cout<<"vaporeon"<<endl; return 0;
    }
    if(n==6) {
        cout<<"espeon"<<endl; return 0;
    }
    for(int i=0;i<6;i++) {
        string check=pok[i];
        bool nai=false;
        if(str.size()==check.size()) {
            for(int j=0;j<str.size();j++) {
                if(str[j]!='.') {
                    if(str[j]!=check[j]) {
                        nai=true;
                        break;
                    }
                }
            }
            if(!nai) {
                cout<<check<<endl;
                return 0;
            }
        }
    }
    return 0;
}
