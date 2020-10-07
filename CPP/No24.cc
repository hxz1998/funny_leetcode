/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *first_node = head;
        ListNode *second_node = head->next;

        first_node->next = swapPairs(second_node->next);
        second_node->next = first_node;

        return second_node;
    }
};

int main(int argc, char *args[])
{
    Solution s;

    ListNode *l = new ListNode{1};
    l->next = new ListNode{2};
    l->next->next = new ListNode{3};
    l->next->next->next = new ListNode{4};
    ListNode *ans = s.swapPairs(l);

    while (ans)
    {
        printf("%d - ", ans->val);
        ans = ans->next;
    }
    
}