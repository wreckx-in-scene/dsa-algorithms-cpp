#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  // constructor 1
  Node(int data, Node *next, Node *prev)
  {
    this->data = data;
    this->next = next;
    this->prev = prev;
  }

  // constructor 2
  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

Node *arrToDll(vector<int> &arr)
{
  int n = arr.size();
  Node *head = new Node(arr[0]);
  Node *prev = head;

  for (int i = 1; i < n; i++)
  {
    Node *temp = new Node(arr[i]);
    temp->prev = prev;
    prev->next = temp;

    prev = temp;
  }

  return head;
}

// inserting a node at head
Node *insertAtHead(Node *head, int x)
{
  Node *newNode = new Node(x);
  if (!head)
    return newNode;
  newNode->next = head;
  newNode->prev = nullptr;
  head->prev = newNode;
  head = newNode;
  return head;
}

// inserting a node in the end
Node *insertAtTail(Node *head, int x)
{
  Node *newNode = new Node(x);

  if (!head)
    return newNode;
  Node *temp = head;
  while (temp->next)
  {
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->prev = temp;
  newNode->next = nullptr;

  return head;
}

// inserting a node at kth pos
Node *insertAtPos(Node *head, int x, int k)
{
  if (k <= 0)
    return head;

  // Insert at head
  if (k == 1)
    return insertAtHead(head, x);

  Node *temp = head;
  int cnt = 1;

  // Reach the (k-1)th node
  while (temp && cnt < k - 1)
  {
    temp = temp->next;
    cnt++;
  }

  // Invalid position
  if (!temp)
    return head;

  // If inserting at the end
  if (temp->next == nullptr)
    return insertAtTail(head, x);

  Node *newNode = new Node(x);

  newNode->next = temp->next;
  newNode->prev = temp;

  temp->next->prev = newNode;
  temp->next = newNode;

  return head;
}

// delete head
Node *deleteHead(Node *head)
{
  if (!head)
    return nullptr;
  if (!head->next)
  {
    delete (head);
    return nullptr;
  }

  Node *prev = head;
  head = head->next;
  head->prev = nullptr;
  prev->next = nullptr;
  delete (prev);
  return head;
}

// delete tail
Node *deleteTail(Node *head)
{
  if (!head || !head->next)
    return nullptr;
  Node *temp = head;
  while (temp->next)
  {
    temp = temp->next;
  }

  temp->prev->next = nullptr;
  delete (temp);
  return head;
}

// delete at kth position
Node *deleteAtPos(Node *head, int k)
{
  if (!head)
    return nullptr;

  // traverse to the kth node
  Node *temp = head;
  int cnt = 0;
  while (temp && cnt < k)
  {
    temp = temp->next;
  }

  // if k is valid or not
  if (!temp)
    return head; // nothing to delete;

  if (temp->prev == nullptr)
  {
    return deleteHead(head);
  }
  else if (temp->next == nullptr)
  {
    return deleteTail(head);
  }
  else
  {
    Node *front = temp->next;
    Node *back = temp->prev;
    back->next = front;
    front->prev = back;

    temp->prev = nullptr;
    temp->next = nullptr;
    delete (temp);
  }

  return head;
}

// delete a given node
void deleteNode(Node *node)
{
  // edge case
  if (!node || !node->next)
    return;

  Node *temp = node->next;
  node->data = temp->data;
  node->next = temp->next;
  if (temp->next)
    temp->next->prev = node;

  delete (temp);
}
// print the dll
void printDll(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << "-";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  Node *head = arrToDll(arr);

  // printing the linkedList
  printDll(head);
  head = deleteHead(head);
  printDll(head);
  head = deleteTail(head);
  printDll(head);
  return 0;
}