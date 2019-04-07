#include <iostream>

template <size_t M, size_t N>
void print(int (&array)[M][N]) {
  for (size_t j = 0; j < M; j++)
    for (size_t i = 0; i < N; i++) {
      std::cout << array[j][i] << std::endl;
    }
}

int main() {
  int array[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  print(array);
  return 0;
}