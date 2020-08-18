#include<bits/stdc++.h>
using namespace std;

map<char,int> M;

int main(int argc,char const *argv[]) {
    string str;
    for(int i=1;i<=3;i++) {
        cin>>str;
        if(str[1]=='>') M[str[0]]++;
        else M[str[2]]++;
    }
    if(M['A']==2&&M['B']==1&&M['C']==0) cout<<"CBA"<<endl;
    else if(M['A']==2&&M['B']==0&&M['C']==1) cout<<"BCA"<<endl;
    else if(M['A']==1&&M['B']==2&&M['C']==0) cout<<"CAB"<<endl;
    else if(M['A']==0&&M['B']==2&&M['C']==1) cout<<"ACB"<<endl;
    else if(M['A']==1&&M['B']==0&&M['C']==2) cout<<"BAC"<<endl;
    else if(M['A']==0&&M['B']==1&&M['C']==2) cout<<"ABC"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}
