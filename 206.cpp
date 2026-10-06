#include <stack>
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
  ListNode *reverseList(ListNode *head)
  {
    ListNode *answer = head;

    // 方法一(未达题目要求)
    // ListNode *temp = head;
    // stack<int> s;
    // while (temp != nullptr)
    // {
    //   s.push(temp->val);
    //   temp = temp->next;
    // }

    // ListNode *ttemp = answer;
    // while (ttemp != nullptr)
    // {
    //   ttemp->val = s.top();
    //   s.pop();
    //   ttemp = ttemp->next;
    // }

    // 方案二
    ListNode *pre = nullptr;
    ListNode *nxt = nullptr;
    while (head != nullptr)
    {
      nxt = head->next;
      head->next = pre;
      pre = head;
      head = nxt;
    }

    answer = pre;
    return answer;
  }
};

int main(int argc, char const *argv[])
{
  Solution solution;
  vector<int> values = {1, 2, 3, 4, 5};

  ListNode *head = new ListNode(values[0]);
  ListNode *cur = head;
  for (size_t i = 1; i < values.size(); i++)
  {
    int v = values[i];
    ListNode *temp = new ListNode(v);
    cur->next = temp;
    cur = cur->next;
  }

  ListNode *answer = solution.reverseList(head);
  for (size_t i = 0; i < values.size(); i++)
  {
    cout << answer->val;
    if (i < values.size() - 1)
    {
      cout << " ";
    }
    answer = answer->next;
  }
  cout << endl;

  return 0;
}
