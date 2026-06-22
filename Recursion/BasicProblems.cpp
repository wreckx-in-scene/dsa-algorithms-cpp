#include <bits/stdc++.h>
using namespace std;

// Print the name n times
void printName(int n)
{
  // base case
  if (n == 0)
    return;
  cout << "Amogh" << endl;
  printName(n - 1);
}

// print 1 to n
void printN(int n)
{
  if (n == 0)
    return;
  printN(n - 1);
  cout << n << endl;
}

// Print n to 1
void PrintNReverse(int n)
{
  if (n == 0)
    return;
  cout << n << endl;
  PrintNReverse(n - 1);
}

// get the sum of first n numbers
int sumN(int n)
{
  if (n == 0)
    return 0;
  return sumN(n - 1) + n;
}

// get the factorial of n numbers
int fact(int n)
{
  // base case
  if (n == 0)
    return 1;
  return n * fact(n - 1);
}

int main()
{
  int n;
  cin >> n;

  // printName(n);
  // printN(n);
  // PrintNReverse(n);
  cout << sumN(n) << endl;
  cout << fact(n) << endl;
  return 0;
}