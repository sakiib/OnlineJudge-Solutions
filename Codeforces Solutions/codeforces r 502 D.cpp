#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

/* lis() returns the length of the longest increasing
  subsequence in arr[] of size n */
int lis( int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );

    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;

    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];

    /* Free memory to avoid memory leak */
    free(lis);

    return max;
}

int a[ N ] , b[ N ];
int mn = inf;
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int n;
        while( cin >> n ) {
                mn = inf;
                for( int i = 0; i < n; i++ ) a[i] = i+1;
                do {
                        int LIS = lis( a , n );
                        for( int i = 0; i < n; i++ ) b[i] = -a[i];
                        int LDS = lis( b , n );
                        //cout << LIS << " " << LDS << endl;
                        if( LIS+LDS == 5 ) {
                                mn = LIS+LDS;
                                for( int i = 0; i < n; i++ ) {
                                        cout << a[i] << " ";
                                }
                                getchar();
                                cout << endl;
                                cout << "Mn : " << mn << endl;
                        }
                } while( next_permutation( a , a+n ) );
                cout <<"ans : " << mn << endl;
        }
        return 0;
}






