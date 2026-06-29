#include <bits/stdc++.h>
using namespace std;

class Stack
{
  int topIndex;
  static const int MAX = 100;
  int arr[MAX];

public:
  Stack()
  {
    topIndex = -1;
  }

  void push(int x)
  {
    if (topIndex == MAX - 1)
    {
      cout << "Stack Overflow\n";
      return;
    }

    arr[++topIndex] = x;
  }

  void pop()
  {
    if (topIndex == -1)
    {
      cout << "Stack Underflow\n";
      return;
    }

    topIndex--;
  }

  int top()
  {
    if (topIndex == -1)
    {
      cout << "Stack is empty\n";
      return -1;
    }

    return arr[topIndex];
  }

  int size()
  {
    return topIndex + 1;
  }

  bool empty()
  {
    return topIndex == -1;
  }
};