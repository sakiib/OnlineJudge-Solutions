#include <iostream>
using namespace std;

int main ()
{
	int a,b,c,d;

	cin>>a>>b>>c>>d;

	cout<<min(min(a, c),d) * 256 + min(a - min(min(a, c),d), b) * 32;

	return 0;
}
