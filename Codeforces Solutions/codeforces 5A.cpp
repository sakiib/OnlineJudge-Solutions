#include<bits/stdc++.h>
using namespace std;

int cur=0;
int ans=0;

int main(int argc,char const *argv[]) {
    string str;
    while(getline(cin,str)) {
        if(str[0]=='+') cur++;
        else if(str[0]=='-') cur--;
        else {
            int k=str.find(':');
            int s=str.size()-k-1;
            ans+=(cur*s);
        }
    }
    cout<<ans<<endl;
    return 0;
}
