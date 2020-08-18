#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    char str[20][100];
    for(int i=0;i<8;i++) {
        cin>>str[i];
    }
    for(int i=0;i<8;i++) {
        cerr<<str[i]<<endl;
    }
    string a;
    int B=0,W=0;
    map<char,int> M;
    M['Q']=M['q']=9;M['R']=M['r']=5;M['B']=M['b']=3;
    M['N']=M['n']=3;M['P']=M['p']=1;M['K']=M['k']=0;
    M['.']=0;
    cerr<<M['B']<< " "<<M['P']<<endl;
    for(int i=0;i<8;i++) {
        a=str[i];
        cerr<<a<<endl;
        for(int j=0;j<a.size();j++) {
            if(a[j]>='A'&&a[j]<='Z') W+=M[a[j]];
            else if(a[j]>='a'&&a[j]<='z') B+=M[a[j]];
        }
    }
    cerr<<W<< " " <<B<<endl;
    if(B==W) cout<<"Draw"<<endl;
    else if(B>W) cout<<"Black"<<endl;
    else cout<<"White"<<endl;
    return 0;
}
