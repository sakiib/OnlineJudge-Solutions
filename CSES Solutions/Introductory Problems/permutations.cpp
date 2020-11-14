#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 2 || n == 3) return cout << "NO SOLUTION" << "\n", 0;
    if (n == 4) return cout << "3 1 4 2" << "\n", 0;
    for (int i = 1; i <= n; i += 2) cout << i << " ";
    for (int i = 2; i <= n; i += 2) cout << i << " ";
    cout << "\n";
    return 0;
}
