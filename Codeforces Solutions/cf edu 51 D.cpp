#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

vector<int> prefix_function(string &s)
{
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++)
	{
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> find_occurences(string &text, string &pattern)
{
	string cur=pattern + '#' + text;
	int sz1=text.size(), sz2=pattern.size();
	vector<int> v;
	vector<int> lps=prefix_function(cur);
	for(int i=sz2+1;i<=sz1+sz2;i++)
	{
		if(lps[i]==sz2) v.push_back(i-2*sz2);
	}
	return v;
}

int main( int argc , char const *argv[] ) {
        string text , pattern;
        cin >> text >> pattern;
        vector <int> V =  find_occurences( text , pattern );
        for( auto x : V ) cout << x << " ";
        return 0;
}






