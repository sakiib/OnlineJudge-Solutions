#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
    int l,jump,grass,target;
    string str;
    cin>>l>>jump;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
      if(str[i]=='G') grass=i+1;
      if(str[i]=='T') target=i+1;
    }
    if(grass<target)
    {
      int dist=grass+jump;
      while(dist<=target)
      {
          if(str[dist-1]=='#')
          {
              //cout<<dist-1<<endl;
              cout<<"NO"<<endl; return 0;
          }
          if(str[dist-1]=='T')
          {
              //cout<<dist-1<<endl;
              cout<<"YES"<<endl; return 0;
          }
          dist+=jump;
      }
      cout<<"NO"<<endl;
    }
    else
    {
        int dist=grass-jump;
        while(dist>=target)
        {
            if(str[dist-1]=='#')
            {
                //cout<<dist-1<<endl;
                cout<<"NO"<<endl; return 0;
            }
            if(str[dist-1]=='T')
            {
                //cout<<dist-1<<endl;
                cout<<"YES"<<endl; return 0;
            }
            dist-=jump;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}
