//Union of Two Linked Lists 

 #include<set>
struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    set<int,greater<int> >s;
    while(head1!=NULL){
        s.insert(head1->data);
        head1 = head1 ->next;
    }
    while(head2!=NULL){
        s.insert(head2->data);
        head2 = head2 ->next;
    }
    struct Node *ptr = NULL;
    set<int,  greater<int>>::iterator itr;
    for (itr = s.begin(); itr != s.end(); ++itr) 
    {
      Node *temp = new Node(*itr);
      temp->next = ptr;
      ptr = temp;
    }
    return ptr;
}


