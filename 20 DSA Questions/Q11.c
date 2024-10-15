#include <stdio.h>
// Function to calculate the GCD of two numbers using Euclid's algorithm
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main() {
  int num1, num2;
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);
  int result = gcd(num1, num2);
  printf("GCD of %d and %d = %d\n", num1, num2, result);
  return 0;
}
