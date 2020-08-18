#include <iostream>
using namespace std;
int a[500],n,m,k,i;
int main()
{
	cin>>n>>k;
	for (i=0;i<n;i++)
	cin>>a[i];
	for (i=1;i<n;i++)
	{
		if (a[i]+a[i-1]<k)
           {
              m+=k-a[i-1]-a[i];
               a[i]=k-a[i-1];
           }
	}
	cout<<m<<endl;
	for (i=0;i<n;i++)
	cout<<a[i]<<' ';
	return 0;
}
