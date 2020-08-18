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
    int ball, n = 3;
	int a, b;

	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	scanf("%d", &ball);
	while (n--)
	{
		scanf("%d%d", &a, &b);
		if (a == ball)
			ball = b;
		else if (b == ball)
			ball = a;
	}
	printf("%d\n", ball);

    return 0;
}


