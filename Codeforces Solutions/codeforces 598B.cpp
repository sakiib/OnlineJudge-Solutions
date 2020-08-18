#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str="acab";
    for(int i=0;i<=str.size()/2;i++) {
        swap(str[i],str[str.size()-1]);
    }
    cout<<str;
}
