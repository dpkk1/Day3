//Split a Circular Linked List into two halves 

   void splitList(Node *head, Node **head1, Node **head2)
    {
      Node *slow = head, *fast = head;
      while(fast -> next != head && fast ->next->next != head){
          slow = slow->next;
          fast = fast -> next -> next;
      }
      *head1 = head;
      *head2 = slow->next;
      
      if(fast->next == head){
         fast -> next = *head2;
      }
      else{
          fast -> next -> next = *head2;
      }
      slow->next = head;
    }


