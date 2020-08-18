#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int llu;

map<string,int>mymap;

int main()
{
    int n,tc,taka;
    llu sum;

    string str,str1;

    scanf("%d%d",&n,&tc);
    getchar();

    while(n--)
    {
        cin>>str>>taka;
        mymap[str]=taka;
    }

    while(tc--)
    {
        sum=0;
        while(cin>>str1&&str1!=".")
       {
         sum+=mymap[str1];
       }
      cout << sum <<endl;
    }

    return 0;
}

