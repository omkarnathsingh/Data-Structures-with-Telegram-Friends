/*
Author: Omkar Nath Singh

#DS Day 2: Problem Statement
Part I.
Implement working of Stack (LIFO) using
1. Array
2. Linked List
Try to have most of the functions which are supported by Stack.

Part II.
Extend above program with functions-
1. to check whether given string is palindrome or not that uses a stack to determine whether a string is a palindrome.
2. to remove spaces and punctuation in string, convert all the Characters to lowercase, and then call above Palindrome checking function to check for a palindrome.
3. to print string in reverse order using stack.

*/

#include<iostream>

using namespace std;
#define MAX 50
class Stack  {
private:
  int data[MAX];
  int top;
public:
  Stack() {
    top=-1;
  }
  void getData();
  void showData();
  void popData();
};

int main()  {
  Stack obj;
  int choice;
  while(1)  {
    cout<<"\n Menu"
        <<"\n 1. Push"
        <<"\n 2. Display Stack contents"
        <<"\n 3. Pop"
        <<"\n 0. Exit"
        <<"\n Enter your choice: ";
    cin>>choice;

    switch (choice) {
      case 1: obj.getData();
              break;
      case 2: obj.showData();
              break;
      case 3: obj.popData();
              break;
      case 0: exit(0);
      default: cout<<"\n Invalid choice entered!!!";
    }
  }
  return 0;
}



void Stack::getData() {
  int temp;
  if(top==MAX-1)  {
    cout<<"\n Stack Overflow!!!";
    return;
  }
  cout<<"\n Enter data: ";
  cin>>temp;
  top++;
  data[top]=temp;

}

void Stack::showData()  {
  if(top==-1)  {
    cout<<"\n Stack Underflow!!!";
    return;
  }
  for(int i=0;i<=top;i++)
    cout<<data[i]<<"\t";

}

void Stack::popData() {
  if(top==-1)  {
    cout<<"\n Stack Underflow!!!";
    return;
  }
  top--;
}
