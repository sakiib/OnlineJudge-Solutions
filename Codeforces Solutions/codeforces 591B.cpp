#include<bits/stdc++.h>
using namespace std;
map<char,char> M;
int main()
{
    int l,q;
    cin>>l>>q;
    string str;
    char a,b,c;
    cin>>str;
    for(char i='a';i<='z';i++){
        M[i]=i;
    }
    while(q--){
        cin>>a>>b;
        for(char i='a';i<='z';i++){
            if(M[i]==a) M[i]=b;
            else if(M[i]==b) M[i]=a;
        }
    }
    for(int i=0;i<l;i++){
        cout<<M[str[i]];
    }
    return 0;
}
