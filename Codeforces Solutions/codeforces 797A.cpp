#include<bits/stdc++.h>
using namespace std;
vector<int>myvec;
int main()
{
    int n,k,count=1,flag=0;
    cin>>n>>k;
    if(k==1)
    {
        cout<<n<<endl;return 0;
    }
    for(int i=2;i<=100000;i++)
    {
        while(n%i==0)
        {

            myvec.push_back(i);
            n=n/i;
            count++;
            if(count==k||n==1)
            {
              flag=1;break;
            }
        }
        if(flag==1)
        {
            if(n==1)
            {
                cout<<-1<<endl;return 0;
            }
            else
            {
                for(int j=0;j<myvec.size();j++)
                {
                    cout<<myvec[j]<< " ";
                }
                cout<<n<<endl;return 0;
            }
        }

    }
    return 0;
}
