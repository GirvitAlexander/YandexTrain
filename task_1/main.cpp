#include <iostream>
#include <ctype.h>
#include <map>
#include <list>

int main() {
	std::map<char, int> alph;
	char ch;
	
	while (std::cin.get(ch)) {
		if (!isspace(ch)) {
			if (alph.count(ch) == 0) {
				alph[ch] = 1;
			}
			else {
				++alph[ch];
			}
		}
	}
	bool is_again = true;
	std::list<std::string> list_res_str;

	std::string res;
	res.reserve(alph.size());
	for (auto& elem : alph) {
		res.push_back(elem.first);
	}

	list_res_str.push_front(res);

	while (is_again) {
		is_again = false;
		std::string res_str;
		res_str.reserve(alph.size() + 1);
		for (auto& elem : alph) {
			if (elem.second != 0) {
				res_str.push_back('#');
				--elem.second;
				is_again = true;
			}
			else {
				res_str.push_back(' ');
			}
		}
		if (is_again)
			list_res_str.push_front(res_str);
	}

	for (auto& str : list_res_str) {
		std::cout << str << '\n';
	}
}