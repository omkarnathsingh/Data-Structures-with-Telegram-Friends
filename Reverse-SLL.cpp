/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* nextNode = head->next;
    head->next = NULL;
    Node* newHead = Reverse(nextNode);
    
    nextNode->next = head;
    return newHead;
}

