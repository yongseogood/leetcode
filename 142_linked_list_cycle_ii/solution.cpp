/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        
        ListNode *s = head;
        ListNode *f = head;
        ListNode *e = head;
        
        while(f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
            
            if(s == f) {
                while(s != e) {
                    s = s->next;
                    e = e->next;
                }
                
                return e;
            }
        }
        
        return nullptr;
        
    }
};
