#include<bits/stdc++.h>
using namespace std;
bool ab=false;
bool ba=false;
int main()
{
    string str,st;
    cin>>str;
    st=str;
    for(int i=0;i<str.size()-1;i++){
        if(str[i]=='A'&&str[i+1]=='B'){
            ab=true;
            str[i]='X';
            str[i+1]='X';
            break;
        }
    }
    for(int i=0;i<str.size()-1;i++){
       if(str[i]=='B'&&str[i+1]=='A'){
         ba=true;
         break;
       }
    }
    if(ab&&ba){
        puts("YES");
        return 0;
    }
    ab=false;
    ba=false;
    for(int i=0;i<st.size()-1;i++){
        if(st[i]=='B'&&st[i+1]=='A'){
            st[i]='X';
            st[i+1]='X';
            ba=true;
            break;
        }
    }
    for(int i=0;i<st.size()-1;i++){
        if(st[i]=='A'&&st[i+1]=='B'){
            ab=true;
            break;
        }
    }
    if(ab&&ba) puts("YES");
    else puts("NO");
    return 0;
}
