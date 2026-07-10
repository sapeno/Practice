#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[k] = 0;
    q.push(k);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : a[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for ( int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

}