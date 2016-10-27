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

class Node  {
public:
  int data;
  Node *previous;
};

class Stack  {
private:
  Node *top;
protected:
public:
  Stack()  {
    top=NULL;
  }
  Node *createNode();
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

Node* Stack::createNode() {
  Node *newptr;
  newptr=new Node;
  int data;
  cout<<"\nEnter data: ";
  cin>>data;
  newptr->data=data;
  newptr->previous=NULL;
  return newptr;
}

void Stack::getData() {
  Node *newnode;
  newnode=createNode();

  if(top==NULL){
    top=newnode;
  }
  else{
    newnode->previous=top;
    top=newnode;
  }
}

void Stack::showData()  {
  if(top==NULL){
    cout<<"\n Empty Stack !!!";
    return;
  }
  Node *temp;
  temp=top;
  while(temp->previous) {
    cout<<"\n"<<temp->data;
    temp=temp->previous;
  }
    cout<<"\n"<<temp->data;
}

void Stack::popData() {
  if(top==NULL){
    cout<<"\n Empty Stack! Nothing to POP";
    return;
  }
  else if(top->previous==NULL)  {
    Node *temp;
    temp=top;
    delete(temp);
    top=NULL;
  }
  else  {
    Node *temp;
    temp=top;
    top=top->previous;
    delete(temp);
  }
}
