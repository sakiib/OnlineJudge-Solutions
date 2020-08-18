#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    if(str[0]>='a'&&str[0]<='z') str[0]-=32;
    cout<<str<<endl;
    return 0;
}

