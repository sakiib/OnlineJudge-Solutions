#include <iostream>
using namespace std;
int main()
{
	string a,b,a2,b2;
	cin>>a>>b;
	a2= string (b.size(),'0') + a;
	b2= string (a.size(), '0') + b;
	cout<<a2<< " " <<b2<<endl;
	cout<<(a2 > b2 ? ">" : a2 < b2 ? "<" : "=")<<endl;
	return 0;
}
