#include<bits/stdc++.h>
using namespace std;
long long a[11]={0};
int main()
{

    long n,m,x,y;
    long long all=0;
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        a[y]+=x;
    }
    for(int i=10; i>0&&n!=0; i--)//Maximum value 10 bola ase//
    {
        if(a[i]!=0)
        {
            if(n>=a[i])
            {
                all+=(i*a[i]);
                n-=a[i];
            }
            else
            {
                all+=(i*n);
                n=0;
            }
        }
    }
    cout<<all<<endl;
    return 0;
}
