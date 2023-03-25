#include <iostream>
#include <set>
#include <vector>

int32_t bin_search(const std::vector<int32_t>& vect, int32_t l, int32_t r, int32_t elem) {
    while (l < r) {
        int32_t m = (l + r) / 2;
        if (vect[m] >= elem) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    size_t N, K;
    int32_t elem;
    std::set<int32_t> nums_set;
    std::vector<int32_t> nums_arr;
    std::cin >> N;

    for (size_t i = 0; i < N; ++i) {
        std::cin >> elem;
        nums_set.insert(elem);
    }
    nums_arr.reserve(nums_set.size());
    for (auto elem : nums_set) {
        nums_arr.push_back(elem);
    }

    std::cin >> K;

    for (size_t i = 0; i < K; ++i) {
        std::cin >> elem;
        std::cout << bin_search(nums_arr, 0, nums_arr.size(), elem) << '\n';
    }
}