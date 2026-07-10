#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> clans;
    for (int i = 0; i < n; i++) {
        ll size;
        cin >> size;
        clans.push(size);
    }

    for (int i = 0; i < n-1; i++) {
        ll firs = clans.top();
        clans.pop();

        ll second = clans.top();
        clans.pop();

        cout << firs << " " << second << "\n";

        ll new_clan = firs + second;
        clans.push(new_clan);
    }

    return 0;
}