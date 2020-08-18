#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<string>
#define pi acos(-1)
#define mod 1000000007
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;
int main()
{
 int a[100001],i, n, max=1,k=1;
	scanf("%d", &n);
	for (i=0; i<n; ++i)
		scanf("%d", &a[i]);
	for (i=1; i<n; ++i) {
		if (a[i]>a[i-1]) {
			k++;
			if (max<=k)
				max=k;
		}
		else
			k=1;
	}
	printf("%d\n",max);
    return 0;
}


