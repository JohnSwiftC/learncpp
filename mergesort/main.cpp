#include <iostream>
#include <vector>

// Writing a merge sort

template <typename T>
std::vector<T> merge(const std::vector<T> &first,
                     const std::vector<T> &second) {
  auto f = 0;
  auto s = 0;
  auto curr = 0;
  auto f_size = first.size();
  auto s_size = second.size();

  std::vector<T> result = std::vector<T>(f_size + s_size);

  for (;;) {
    if ((f + s) == (f_size + s_size)) {
      break;
    }

    if ((f < f_size) && (s < s_size)) {
      if (first[f] < second[s]) {
        result[curr] = first[f];
        ++f;
        ++curr;
      } else {
        result[curr] = second[s];
        ++s;
        ++curr;
      }

      continue;
    }

    if (f < f_size) {
      result[curr] = first[f];
      ++f;
      ++curr;
      continue;
    }

    result[curr] = second[s];
    ++s;
    ++curr;
  }

  return result;
}

int main() {
  std::vector<int> first{1, 3, 3, 18, 20};
  std::vector<int> second{-1, 4, 19};

  std::vector<int> merged = merge(first, second);

  for (auto &n : merged) {
    std::cout << n << " ";
  }

  return 0;
}
