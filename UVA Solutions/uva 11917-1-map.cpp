#include<bits/stdc++.h>
using namespace std;
map<string,int>mymap;
int main()
{
    int t,tc,n;
    string subject,khujo;
    int days,deadline;
    cin>>t;
    for(tc=1;tc<=t;tc++)
    {
        mymap.clear();
        cin>>n;
        while(n--)
        {
           cin>>subject>>days;
           mymap[subject]=days;
        }
        cin>>deadline>>khujo;

        map<string,int>::iterator it;

        it=mymap.find(khujo);

        if((it==mymap.end())||(it->second>deadline+5))
         printf("Case %d: Do your own homework!\n",tc);

        else if(it->second<=deadline)
         printf("Case %d: Yesss\n",tc);

        else if(it->second<=deadline+5)
         printf("Case %d: Late\n",tc);
    }
    return 0;
}
