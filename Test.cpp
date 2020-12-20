#include <iostream>
using namespace std;
 
int main() {
   int n = 20;
   int factorial = 1;
 
   // n! = 1*2*3...*n
   for (int i = 1; i <= n; i++) {
      factorial *= i;
   }
   cout << "The Factorial of " << n << " is " << factorial << endl;
   return 0;
}
