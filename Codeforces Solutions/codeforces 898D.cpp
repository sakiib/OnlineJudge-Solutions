#include <bits/stdc++.h>
using namespace std;

#define maxn            100010
#define esp             1e-6
#define mod             1000000007
#define ll              long long
#define inf             1061109567

typedef pair<ll, int> ii;
typedef pair<int, ii> iii;

int n, k, m;
int arr[ 2 * maxn ];

int tree[1000010];

void update(int idx, int val){
        while(idx <= 1000000){
                tree[idx] += val;
                idx += idx & (-idx);
        }
}

int query(int idx)
{
        int sum = 0;
        while(idx > 0){
                sum += tree[idx];
                idx -= idx & (-idx);
        }
        return sum;
}

int main(){

        scanf("%d %d %d", &n, &m, &k);

        for(int i = 1; i <= n; i ++){
                scanf("%d", &arr[i]);
        }

        sort(arr + 1, arr + 1 + n);

        int cnt = 0;
        for(int i = 1; i <= n; i ++){
                int last = max(arr[i] - m, 0);
                int ret = query(arr[i]) - query(last);
                if(ret + 1 >= k){
                        cnt ++;
                }
                else update(arr[i], 1);
                cout << last << " " << ret << endl;
        }

        cout << cnt << endl;

        return 0;
}
