/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>

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
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if ((!a) || (!b))
            return a ? a : b;

        ListNode head{0}, *tail = &head, *a_ptr = a, *b_ptr = b;
        while (a_ptr && b_ptr)
        {
            if (a_ptr->val < b_ptr->val)
            {
                tail->next = a_ptr;
                a_ptr = a_ptr->next;
            }
            else
            {
                tail->next = b_ptr;
                b_ptr = b_ptr->next;
            }
            tail = tail->next;
        }
        tail->next = (a_ptr ? a_ptr : b_ptr);
        return head.next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ans = nullptr;
        for (int i = 0; i < lists.size(); i++)
        {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};

int main()
{
    // int a[] = {1, 4, 5};    
    // int b[] = {1, 3, 4};
    // int c[] = {2, 6};

    ListNode *a = new ListNode{1};
    a->next = new ListNode{4};
    a->next->next = new ListNode{5};
    a->next->next->next = nullptr;

    ListNode *b = new ListNode{1};
    b->next = new ListNode{3};
    b->next->next = new ListNode{4};
    b->next->next->next = nullptr;

    ListNode *c = new ListNode{2};
    c->next = new ListNode{6};
    c->next->next = nullptr;

    vector<ListNode *> lists = {a, b, c};

    Solution s;
    ListNode *res = s.mergeKLists(lists);
    while(res)
    {
        printf("%d - ", res->val);
        res = res->next;
    }
}