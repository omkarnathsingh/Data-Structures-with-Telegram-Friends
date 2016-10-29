/*
Author: Omkar Nath Singh

#DS Day 2: Problem Statement
Part I.
Implement working of Stack (LIFO) using Array

Part II.
Extend above program with functions-
1. to check whether given string is palindrome or not that uses a stack to determine whether a string is a palindrome.
2. to remove spaces and punctuation in string, convert all the Characters to lowercase, and then call above Palindrome checking function to check for a palindrome.
3. to print string in reverse order using stack.

*/

#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
#define MAX 50

class Stack  {
private:
  char data[MAX],str[MAX];
  int top,length,count;
  
  void pushData(char);
  char popData();

public:
  Stack() {
    top=-1;
    length=0;
    count=0;
  }
  void getString();
  void checkPalindrome();
  void extractString();
};

int main()  {
  Stack obj;
  obj.getString();
  obj.extractString();
  obj.checkPalindrome();
  return 0;
}

void Stack::getString() {
  cout<<"\n Enter a String: ";
  cin.getline(str,MAX);

  length=strlen(str);
}

void Stack::extractString() {
  char temp[MAX];
  int i,j;
  for(i=0; i<length; i++) {
    temp[i]=str[i];
  }
  j=0;
  for(i=0; i<length; i++ )  {
    if(isalpha(temp[i]))  {
      str[j]=tolower(temp[i]);
      j++;
    }
  }

  length=j;   //update length with new str length

}

void Stack::checkPalindrome() {
  for(int i=0; i<length; i++)
    pushData(str[i]);

  for(int i=0; i<length; i++) {
    if(str[i]==popData())
      count++;
  }

  if(count==length) {
    cout<<"\n Entered string is a Palindrome. \n";
  }
  else  cout<<"\n Entered string is not a Palindrome. \n";
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
