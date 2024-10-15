#include <stdio.h>
// Function to calculate the factorial of a number
long long factorial(int n) {
  if (n < 0) {
    printf("Error: Factorial is not defined for negative numbers\n");
    return -1;
  } else if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}
int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  long long result = factorial(num);
  if (result != -1) {
    printf("Factorial of %d = %lld\n", num, result);
  }
  return 0;
}
