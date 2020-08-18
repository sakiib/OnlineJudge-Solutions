#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string str="";
    cin>>n;
    for(int i=1;i<=1000;i++){
        stringstream iss;
        iss<<i;
        str+=iss.str();
    }
    //cout<<str;
    cout<<str[n-1];
    return 0;
}
