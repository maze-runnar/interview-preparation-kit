int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {


           SinglyLinkedListNode  *curr, *current1 = head1, *temp1=head1; 
       SinglyLinkedListNode *current2 = head2,  *temp2=head2;

       int c1=0,c2=0,d;

       while(temp1!=NULL)
        {
            c1++;
            temp1=temp1->next;
        }

       while(temp2!=NULL)
       {
           c2++;
           temp2=temp2->next;
       }

       if(c1>c2)
       {
           d=c1-c2;
       }
       else
       {
           d=c2-c1;
           curr=current1;
           current1=current2;
           current2=curr;
       }

  

    for (int i = 0; i < d; i++) { 
        current1 = current1->next; 
    } 
   
    while (current1 != NULL && current2 != NULL) { 
        if (current1 == current2) 
            return current1->data; 
  

        current1 = current1->next; 
        current2 = current2->next; 
    } 
  

  return -1;

}
