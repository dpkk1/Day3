//Merge 2 sorted linked list in reverse order 

 void *reverse(Node **reshead){
    Node *curr=*reshead;
    Node *prev=NULL;
    Node *nextnode=*reshead;
    while(nextnode!=NULL){
        nextnode=nextnode->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    *reshead=prev;
}

struct Node * mergeResult(Node *node1,Node *node2)
{
    // your code goes here
    Node *res=NULL;
    Node *temp1=node1;
    Node *temp2=node2;
    Node *reshead=NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data <= temp2->data){
            if(reshead==NULL){
                res=temp1;
                reshead=res;
                temp1=temp1->next;
            }
            else{
                res->next=temp1;
                res=res->next;
                temp1=temp1->next;
            }
        }
        else{
            if(reshead==NULL){
                res=temp2;
                reshead=res;
                temp2=temp2->next;
            }
            else{
                res->next=temp2;
                res=res->next;
                temp2=temp2->next;
            }
        }
    }
    if(temp1!=NULL){
        res->next=temp1;
    }
    else if(temp2!=NULL){
        res->next=temp2;
    }
    reverse(&reshead);
    return reshead;
}
