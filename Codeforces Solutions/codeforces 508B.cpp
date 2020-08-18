#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    bool found=false; bool done=false;
    int n=str.size()-1;
    string a="",b="";
    for(int i=0;i<n;i++) {
        if((str[i]-'0')%2==0&&(str[i]-'0')<(str[n]-'0')){
            swap(str[i],str[n]);
            a=str;
            swap(str[i],str[n]);
            found=true;
            break;
        }
    }
    for(int i=n-1;i>=0;i--) {
        if((str[i]-'0')%2==0&&(str[i]-'0'>str[n]-'0')) {
            swap(str[i],str[n]);
            b=str;
            found=true;
            break;
        }
    }

    if(found) cout<<max(a,b);
    else cout<<-1<<endl;
    return 0;
}
