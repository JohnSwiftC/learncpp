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

template <typename T> std::vector<T> merge_sort(const std::vector<T> &vec) {
  if (vec.size() == 1) {
    return vec;
  }

  auto half = vec.size() / 2;
  std::vector<T> first = std::vector<T>(vec.begin(), vec.begin() + half);
  std::vector<T> second = std::vector<T>(vec.begin() + half, vec.end());

  std::vector<T> first_sorted = merge_sort(first);
  std::vector<T> second_sorted = merge_sort(second);

  return merge(first_sorted, second_sorted);
}

int main() {
  std::vector<int> int_unsorted{0, -4, 20, 13, 62, -18, 999, 10, -12};

  std::vector<int> int_sorted = merge_sort(int_unsorted);

  for (int &val : int_sorted) {
    std::cout << val << " ";
  }

  return 0;
}
