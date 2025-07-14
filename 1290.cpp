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
    int getDecimalValue(ListNode *head)
    {
        int answer = 0;

        string binaryStr = "";
        while (head != nullptr)
        {
            binaryStr += to_string(head->val);
            head = head->next;
        }

        answer = stoi(binaryStr, nullptr, 2);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nodes = {1, 0, 1};

    ListNode *head = new ListNode(nodes[0]);
    ListNode *current = head;
    for (int i = 1; i < nodes.size(); i++)
    {
        current->next = new ListNode(nodes[i]);
        current = current->next;
    }

    int answer = solution.getDecimalValue(head);
    cout << answer << endl;

    return 0;
}
