#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main () {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll n, k, m;
    cin >> n >> k >> m;

    const ll MOD = 1e9 + 7;

    vector<bool> dang(n + 1, false);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        dang[x] = true;
    }

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    ll sum = 1;

    for ( int i = 1; i <= n; i++) {
        if (dang[i]) {
            dp[i] = 0;
        } else {
            dp[i] = sum % MOD;
        }

        sum = (sum + dp[i]) % MOD;
        if (i - k >= 0) sum = (sum - dp[i - k] + MOD) % MOD;
    }

    cout << dp[n] % MOD << "\n";


}