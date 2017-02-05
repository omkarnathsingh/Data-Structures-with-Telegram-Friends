/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
    Node *current,*tobeDeleted;
    current= head;  
    
    if( position == 0 ){
        tobeDeleted = head;
        head=head->next;
        delete(tobeDeleted);
        return head;
    }
    
    int counter = 0;
    while( ++counter < position ){
        current = current->next;
    }
        
    tobeDeleted = current->next;   
    current->next = tobeDeleted->next;
    delete(tobeDeleted);
    
    return head;
}
