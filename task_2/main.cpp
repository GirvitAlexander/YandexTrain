#include <iostream>
#include <cctype>
#include <vector>
#include <set>

int main() {
  size_t K;
  std::string str;
  int res_max = 0;
  // bool is mask
  std::vector<std::pair<char, bool>> tmp_str;
  std::set<char> set;
  std::cin >> K;
  std::cin >> str;
  if (K > str.size()) {
    std::cout << str.size();
    return 0;
  }


  tmp_str.resize(str.size());

  for (size_t i = 0; i < str.size(); ++i) {
    set.insert(str[i]);
  }


  for (const auto& ch : set) {
    int cur_max = 0;
    size_t first = 0, second = 0, cnt = 0;
    
    for (size_t i = 0; i < str.size(); ++i) {
      tmp_str[i] = std::make_pair(str[i], false);
    }


    while (cnt != K) {
      if (tmp_str[second].first != ch) {
        ++cnt;
        tmp_str[second] = std::make_pair(ch, true);
      }
      ++second;
      while (second != str.size() && tmp_str[second].first == ch) {
        ++second;
      }
    }
    cur_max = second - first;

    while (second != str.size()) {
      if (tmp_str[first].second) {
        tmp_str[second] = std::make_pair(ch, true);
      	++second;
      }

      ++first;

      while (second != str.size() && tmp_str[second].first == ch) {
        ++second;
      }

      if (cur_max < (second - first)) {
        cur_max = second - first;
      }
    }
    if (cur_max > res_max) {
      res_max = cur_max;
    }
  }

  std::cout << res_max;
  return 0;
}