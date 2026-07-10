#include <iostream>
#include <vector>
#include <utility>
 
 
int one() {
    int n;
    std::cin >> n;
 
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
 
    long long swap_count = 0;
 
    for (int i = 0; i < n; i++) {
        bool swapped = false;
 
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                swap_count++;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    return swap_count;
}
 
int main() {
    int t;
    std::cin >> t;
 
    int cop_t = t;
 
    std::vector<int> swapes(10);
 
    while (t) {
        t--;
        swapes[t] = one();
    }
 
    for (int i = cop_t-1; i >= 0; i--){
        std::cout << swapes[i] << "\n";
    }
 
}