#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    map<char,int> M,N;
    for(int i=0;i<a.size();i++){
        if(a[i]!=' ') M[a[i]]++;
    }
    for(int i=0;i<b.size();i++){
        if(b[i]!=' ') N[b[i]]++;
    }
    for(int i=0;i<200;i++){
        if(N[i]>M[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
