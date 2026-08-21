#include <vector>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *answer = new ListNode();
        ListNode *temp = answer;

        int num = l1->val + l2->val;
        temp->val = (num) % 10;
        bool jinwei = num > 9;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr || l2 != nullptr)
        {
            int n1 = 0, n2 = 0;
            if (l1 != nullptr)
            {
                n1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                n2 = l2->val;
                l2 = l2->next;
            }

            int sum = n1 + n2 + jinwei;
            jinwei = sum > 9;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        if (jinwei)
        {
            temp->next = new ListNode(1);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> v1 = {9, 9, 9, 9, 9, 9, 9};
    vector<int> v2 = {9, 9, 9, 9};

    ListNode *l1 = new ListNode();
    ListNode *t1 = l1;
    for (int i = 0; i < v1.size(); i++)
    {
        int cur = v1[i];
        if (i == 0)
        {
            t1->val = cur;
            continue;
        }
        t1->next = new ListNode(cur);
        t1 = t1->next;
    }

    ListNode *l2 = new ListNode();
    ListNode *t2 = l2;
    for (int i = 0; i < v2.size(); i++)
    {
        int cur = v2[i];
        if (i == 0)
        {
            t2->val = cur;
            continue;
        }
        t2->next = new ListNode(cur);
        t2 = t2->next;
    }

    ListNode *answer = solution.addTwoNumbers(l1, l2);
    while (answer != nullptr)
    {
        cout << answer->val;
        if (answer->next != nullptr)
        {
            cout << " ";
        }
        answer = answer->next;
    }
    cout << endl;

    return 0;
}
