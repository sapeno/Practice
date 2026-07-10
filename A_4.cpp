#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;

    vector<ll> a(n + 2, 0);


    for (ll i = 0; i < q; i++) {
        ll l, r, v;
        cin >> l >> r >> v;
        a[l] += v;
        a[r + 1] -=v;
    }

    ll cur = 0;
    for (ll i = 1; i <=n; i++) {
        cur += a[i];
        cout << cur << " ";
    }

    

    
}


