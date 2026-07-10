#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;

struct Rebro {
    int u, v;
    ll w;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;

    vector<Rebro> rebra(m);
    for (int i = 0; i < m; i++) {
        cin >> rebra[i].u >> rebra[i].v >> rebra[i].w;
    }

    vector<long long> dist(n + 1, INF);
    dist[s] = 0;

    for (int i = 1; i < n; ++i) {
        bool changed = false;
        for (const auto& rebro : rebra) {
            if (dist[rebro.u] != INF && dist[rebro.u] + rebro.w < dist[rebro.v]) {
                dist[rebro.v] = dist[rebro.u] + rebro.w;
                changed = true;
            }
        }

        if (!changed) break;

    }
        
    bool negativ_cycle = false;
    for (const auto& rebro : rebra) {
        if (dist[rebro.u] != INF && dist[rebro.u] + rebro.w < dist[rebro.v]) {
            negativ_cycle = true;
            break;
        }
    }

    if (negativ_cycle) {
        cout << "Negative cycle\n";
    } else {
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) {
                cout << "inf";
            } else {
                cout << dist[i];
            }
            cout << " ";
        }
        cout << "\n";
    }
}
