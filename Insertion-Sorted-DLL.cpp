/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data) {
    Node *n;
    n= new Node;
    n->data = data;
    if (head == NULL) {
        return n;
    }
    else if (data > head->data) {
        
        Node *temp;
        temp= SortedInsert(head->next, data);
        head->next = temp;
        temp->prev = head;
        return head;
    }
    else {
        n->next = head;
        head->prev = n;
        return n;
    }
}
