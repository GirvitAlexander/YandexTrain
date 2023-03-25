#include <iostream>
#include <cstdint>

int main() {
	int64_t N, K, row, place;
	std::cin >> N >> K >> row >> place;
	int64_t sit = (row - 1) * 2 + place;
	int64_t pos1 = sit - K;
	int64_t pos2 = sit + K;
	int64_t row1 = (pos1 + 1) / 2;
	int64_t row2 = (pos2 + 1) / 2;

	if (pos1 > 0 && (pos2 > N || abs(row - row1) < abs(row - row2))) {
		std::cout << row1 << " " << 2 - pos1 % 2;
	}
	else if (pos2 <= N) {
		std::cout << row2 << " " << 2 - pos2 % 2;
	}
	else {
		std::cout << -1;
	}

	return 0;
}