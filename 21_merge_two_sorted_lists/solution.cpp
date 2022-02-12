class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode result(INT_MIN);
        ListNode *tmp = &result;
        
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                tmp->next = list1;
                list1 = list1->next;
            } else {
                tmp->next = list2;
                list2 = list2->next;
            }
            
            tmp = tmp->next;
        }
        
        tmp->next = list1 ? list1 : list2;
        
        return result.next;
    }
};
