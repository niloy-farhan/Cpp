#include <iostream>
#include <thread>

int main (int argc, char *argv[]) {
  int allowed_threads = std::thread::hardware_concurrency();
  printf("Allowed thread count in my divice : %d \n", allowed_threads);
  return 0;
}
