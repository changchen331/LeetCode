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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> answer = {-1, -1};
        ListNode *node = head;

        int left = -1, right = -2; // 最左边的机制点坐标
        int last = node->val;      // 上一个节点的 val
        int cnt = 1;               // 节点下标
        node = node->next;
        for (; node->next != nullptr; node = node->next, cnt++)
        {
            int cur = node->val;
            int next = node->next->val;
            if ((last < cur && cur > next) ||
                (last > cur && cur < next))
            {
                if (left == -1)
                {
                    left = cnt;
                }
                else if (right == -2)
                {
                    answer[0] = cnt - left;
                    right = cnt;
                }
                else
                {
                    answer[0] = min(answer[0], cnt - right);
                    right = cnt;
                }
            }
            last = cur;
        }

        if (right > 0)
        {
            answer[1] = right - left;
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nodes = {1, 3, 2};
    ListNode *head = new ListNode();
    ListNode *temp = head;
    temp->val = nodes[0];
    for (int i = 1; i < nodes.size(); temp = temp->next, i++)
    {
        int cur = nodes[i];
        temp->next = new ListNode(cur);
    }

    vector<int> answer = solution.nodesBetweenCriticalPoints(head);
    cout << answer[0] << " " << answer[1] << endl;

    return 0;
}
