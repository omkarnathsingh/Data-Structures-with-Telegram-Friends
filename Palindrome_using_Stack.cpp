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
#include<string.h>

using namespace std;
#define MAX 50

class Stack  {
private:
  char data[MAX];
  int top;
  void pushData(char);
  char popData();
public:
  Stack() {
    top=-1;
  }

  void checkPalindrome();
};

int main()  {
  Stack obj;
  obj.checkPalindrome();
  return 0;
}

void Stack::checkPalindrome() {
  char str[MAX];
  cout<<"\n Enter a String: ";
  cin.getline(str,MAX);

  int length,i,count;
  length=strlen(str);
  count=0;

  for(i=0; i<length; i++)
    pushData(str[i]);

  for(i=0; i<length; i++) {
    if(str[i]==popData())
      count++;
  }

  if(count==length) {
    cout<<"\n Entered string is a Palindrome.";
  }
  else  cout<<"\n Entered string is not a Palindrome";
}

void Stack::pushData(char temp) {

  if(top==MAX-1)  {
    cout<<"\n Stack Overflow!!!";
    return;
  }
  top++;
  data[top]=temp;

}

char Stack::popData() {
  if(top==-1)  {
    cout<<"\n Stack Underflow!!!";
    char ch='\n';
    return ch;
  }
  char temp=data[top];
  top--;
  return temp;
}
