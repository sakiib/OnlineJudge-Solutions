#include<bits/stdc++.h>
using namespace std;
vector<int>myvec;
map<int,int>mymap;
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        if(mymap.count(n)==0)
        {
            mymap[n]=1;
            myvec.push_back(n);
        }
        else
        {
            mymap[n]++;
        }
    }
     for(i=0;i<myvec.size();i++)
        {
            printf("%d %d\n",myvec[i],mymap[myvec[i]]);
        }
    return 0;
}
