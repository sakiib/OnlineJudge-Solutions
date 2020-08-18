#include<bits/stdc++.h>
using namespace std;

int main(){
    int mx=0;
    string str;
    cin>>str;
    set<string> S;
    for(int i=0;i<str.size();i++){
            string st="";
        for(int j=i;j<str.size();j++){
            st+=str[j];
            if(S.find(st)!=S.end()){
                int x=st.size();
                mx=max(mx,x);
            }
            S.insert(st);
        }
    }
    /*set<string> :: iterator it;
    for(it=S.begin();it!=S.end();it++){
        string a=*it;
        cout<<a<<endl;
    }*/
    cout<<mx<<endl;
    return 0;
}
