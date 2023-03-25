#include <iostream>
#include <cstdint>
#include <vector>


int main() {
	size_t N;
	std::vector<int64_t> cnt_ch;
	std::cin >> N;
	cnt_ch.resize(N);

	for (size_t i = 0; i < N; ++i) {
		std::cin >> cnt_ch[i];
	}

	int64_t res = 0;
	bool is_again = true;

	while (is_again) {
		is_again = false;
		size_t cur_without_zero;
		for (cur_without_zero = 0; cur_without_zero < N; ++cur_without_zero) {
			if (cnt_ch[cur_without_zero] != 0) {
				break;
			}
		}

		if (cur_without_zero < N) {
			int64_t min = cnt_ch[cur_without_zero];
			size_t cnt_good = 0, last;
			for (last = cur_without_zero + 1; last < N; ++last) {
				is_again = true;
				if (cnt_ch[last] == 0) {
					break;
				}
				++cnt_good;
				if (cnt_ch[last] < min) {
					min = cnt_ch[last];
				}
			}
			res += min * cnt_good;
			for (size_t i = cur_without_zero; i < last; ++i) {
				cnt_ch[i] -= min;
			}
		}
	}

	std::cout << res;
}