//reverse_list.cpp
// Leetcode provblem: 

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
    ListNode* reverseList_iterative(ListNode* head) {
        //Initialization step
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr; 
        // O(1)
        while(curr){ // loop runs n times
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            // O(1)
        }
        return prev;
        // Running time complexity  is T(n) = O(n)
        // Space complexity S(n) = O(1)
        
    }

    ListNode* reverseList(ListNode* head) {
        if(!head || ! head->next){
            return head;
        }
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
        // Running time complexity is T(n) = O(n)
        // Space complexity S(n) = O(n) (maximum depth of call stack)
    }
};

// Run in leetcode