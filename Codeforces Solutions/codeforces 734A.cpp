#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,anton=0,danik=0;
    string str;

    cin>>n>>str;

    for(int i=0;i<n;i++){

        if(str[i]=='A') anton++;
        else danik++;
    }
    if(anton==danik) cout<<"Friendship"<<endl;
    else if(anton>danik) cout<<"Anton"<<endl;
    else cout<<"Danik"<<endl;

    return 0;
}
