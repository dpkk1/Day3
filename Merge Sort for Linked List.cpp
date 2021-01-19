//Merge sort for linked list

Node* Merge_List(Node *first,Node* second){
  Node *result = NULL;
  if(first == NULL){
      return second;
  }
   if(second == NULL){
      return first;
  }
  if(first->data <= second->data){
      result = first;
      result -> next = Merge_List(first->next,second);
  }
  else{
      result = second;
      result -> next = Merge_List(first, second->next);
  }
  return result;
}
   
   
Node *Find_Middle_List(Node* head){
    Node*temp1 = head,*temp2 = head;
    while(temp2->next && temp2->next->next){
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }
    return temp1;
}
   
Node* mergeSort(Node* head) {
   if(head == NULL || head->next == NULL){
       return head;
   }
   Node *middle = Find_Middle_List(head);
   Node *middle_next = middle->next;
   
   middle -> next = NULL;
   
   Node *first = mergeSort(head);
   Node *second = mergeSort(middle_next);
   
   Node *sorted_List = Merge_List(first, second);
   return sorted_List;
}

