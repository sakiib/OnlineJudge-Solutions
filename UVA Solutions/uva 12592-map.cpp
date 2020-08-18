#include<bits/stdc++.h>
using namespace std;
map<string,string>mymap;
int main()
{
    int n,tc;
    string str,str1,str2;
    cin>>n;
    getchar();
    while(n--)
    {
      getline(cin,str);
      {
        getline(cin,str1);
        mymap[str]=str1;
      }
    }
    cin>>tc;
    getchar();
    while(tc--)
    {
        getline(cin,str2);
        cout<<mymap[str2]<<endl;
    }
    return 0;
}
