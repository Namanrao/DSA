/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) {
            return NULL;
        }
        if(k == 0){
            return head;
        }
        ListNode* temp = head;
        int n = 0 ;
        while(temp->next!=NULL){
            n++;
            temp  =temp ->next;
        }
        ListNode* originalEnd = temp;
        n+=1;
        k = k%n;
        int cnt = 0 ;
        while(cnt< n-k){
            ListNode * newTemp = new ListNode(-1);
            temp ->next= newTemp;
            temp =newTemp;
            cnt++;
        } 
        temp = head; 
        cnt=0 ;
        originalEnd = originalEnd->next;
        while(cnt<n-k){
            ListNode* todelete = temp;
            int data = temp ->val;
            originalEnd->val = data;
            temp = temp->next;
            originalEnd = originalEnd->next;
            cnt++;
            delete(todelete);
        }
        return temp;
    }
};