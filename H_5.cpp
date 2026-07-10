#include <iostream>
#include <vector>

using namespace std;

const int M = 40000000;

int min_prime[M + 1];

unsigned char prost[M + 1];

vector<int> primes;

void f() {
    prost[1] = 0; 
    
    for (int i = 2; i <= M; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            prost[i] = 1; 
            primes.push_back(i);
        }
        
        for (int p : primes) {
            if (p > min_prime[i] || i * p > M) {
                break;
            }
            
            int next_num = i * p;
            min_prime[next_num] = p;
            
            if (i % p == 0) {
                prost[next_num] = prost[i];
            } else {
                prost[next_num] = prost[i] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    f();

    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;

            if (min_prime[n] == n) {
                cout << "Prime\n";
            } else {
                cout << (int)prost[n] << "\n";
            }
        }
    }
    return 0;
}
