#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int arr[maxn], l[maxn], r[maxn];

int main(int argc, char const *argv[]) {
	int n; cin>>n;
	arr[0] = arr[n+1] = 0;

	for(int i=1; i<=n; i++) cin>>arr[i];
	for(int i=1; i<=n; i++) {
		if(arr[i] > arr[i-1]) l[i] = l[i-1] + 1;
		else l[i] = 1;
 	}

 	for( int i = 1; i <= n; i++ ) cout << l[i] << " ";
 	cout << endl;

 	for(int i=n; i>=1; i--) {
 		if(arr[i] < arr[i+1]) r[i] = r[i+1] + 1;
 		else r[i] = 1;
 	}
 	for( int i = 1; i <= n; i++ ) cout << r[i] << " ";
 	cout << endl;

 	int ans = 1;
 	for(int i=1; i<=n; i++) {
 		ans = max(ans, l[i-1] + 1);
 		ans = max(ans, r[i+1] + 1);
 		if((arr[i-1] + 1) < arr[i+1])
 			ans = max(ans, l[i-1]+r[i+1]+1);
 	}
 	cout<<ans<<endl;
 	return 0;
}
