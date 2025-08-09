// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false
 

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9
 

// Follow up: Could you do it in O(n) time and O(1) space?

#include <algorithm>
#include <vector>
#include <iterator> 
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    static ListNode *Reverse(ListNode *head)
    {
        ListNode    *result = nullptr;
        ListNode    *current = head;
        ListNode    *next;
        while (current)
        {
            next = current->next;
            current->next = result;
            result = current;
            current = next;
        }
        return result;
    }
    bool isPalindrome(ListNode* head) {
        ListNode    *slow = head;
        ListNode    *fast = head;
        ListNode    *top = head;
        while (fast)
        {
            if (fast->next == nullptr)
                break ;
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *tmp = Reverse(slow);
        while (tmp)
        {
            if (tmp->val != top->val)
                return false;
                 tmp = tmp->next;
                 top = top->next;
        }
        return true;
    }
};