//Add 1 to a number represented as linked list 

 Node *reverse(Node **head){
    Node *currnode=*head;
    Node *prevnode=NULL;
    Node *nextnode=*head;
    while(nextnode!=NULL){
        nextnode=nextnode->next;
        currnode->next=prevnode;
        prevnode=currnode;
        currnode=nextnode;
    }
    *head=prevnode;
}

Node* addOne(Node *head) 
{
    // Your Code here
    // return head of list after adding one
    reverse(&head);
    //cout<<head->next->next->data<<endl;
    int carry=1;
    Node *temp=head;
    while(temp!=NULL){
        int num=temp->data;
        temp->data=(num+carry)%10;
        carry=(num+carry)/10;
        if(carry==0)
        break;
        temp=temp->next;
    }
    if(carry!=0){
        Node *new_node=new Node(carry);
        reverse(&head);
        new_node->next=head;
        head=new_node;
    }
    else
    reverse(&head);
    return head;
}
