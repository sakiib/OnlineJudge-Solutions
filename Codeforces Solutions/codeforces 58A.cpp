#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int j=0;
    string a="hello";
    cin>>str;
    bool ache=true;
    for(int i=0;i<str.size();i++){
        (str[i]==a[j]) ? j++ : j=j;
    }
    (j==5) ? puts("YES") : puts("NO");
    return 0;
}
