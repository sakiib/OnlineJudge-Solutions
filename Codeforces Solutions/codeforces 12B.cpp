#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    sort(a.begin(),a.end());
    if(a[0]=='0'&&a.length()>1)
    {
        swap(a[0],a[a.find('0')+1]);
    }
    if(a==b)
        cout<<"OK"<<endl;
    else
        cout<<"WRONG_ANSWER"<<endl;
    return 0;
}
