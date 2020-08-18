#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    string str;
    cin>>n;
    getchar ();
    while(n--){
        cin>>str>>a>>b;
        if(a>=2400&&b>a){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
