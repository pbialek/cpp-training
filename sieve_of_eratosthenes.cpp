#include <iostream>
#include <cmath>
#include <vector>
#include <string>

std::vector<int> SieveOfEratosthenes(const int n) {
    std::vector<int> vec = {};
    std::vector<bool> bool_vec(n, true);
    
    for (auto i = 2; i <= std::sqrt(n); ++i) {
        if (bool_vec[i]) {
            for (auto j = i*i; j < n; j += i) {
                bool_vec[j] = false;
            }
        }
    }
    
    for (auto i = 2; i < n; ++i) {
        if (bool_vec[i]) {
            vec.push_back(i);
        }
    }
    return vec;
}

int main()
{
    std::vector<int> v = SieveOfEratosthenes(30);
    for (auto i : v) {
        std::cout << i << std::endl;
    }
}