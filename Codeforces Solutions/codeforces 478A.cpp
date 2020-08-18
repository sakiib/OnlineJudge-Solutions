#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,sum=0,av;
    cin>>a>>b>>c>>d>>e;
    sum+=a+b+c+d+e;
    av=sum/5;
    if(av*5==sum&&av!=0) cout<<av<<endl;
    else cout<<-1<<endl;
    return 0;
}
