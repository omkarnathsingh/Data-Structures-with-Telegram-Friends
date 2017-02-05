/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
    
    Node *newNode;
    newNode= new Node;
    newNode->data = data;
    Node *current;
    current= head;  
    
    if( position == 0 ){
        newNode->next = head;
        return newNode;
    }
    
    int counter = 0;
    while( ++counter < position ){
        current = current->next;
    }
        
    newNode->next = current->next;   
    current->next = newNode;   
    
    return head;
}

