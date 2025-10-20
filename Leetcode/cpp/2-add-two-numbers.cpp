class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode l = NULL;
        int sum =0;
        int size = 0;
        ListNode *l3=NULL;
        ListNode **node=&l3;
        while(l1 != NULL || l2  != NULL || sum > 0){
            if(l1 != NULL){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            int rem = sum % 10;
            sum = sum/10;
             *node = new ListNode(rem);
             node = &((*node) -> next);
        }
        
        
        return l3;
        
 
        
    }
};
