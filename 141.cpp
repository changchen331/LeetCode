#include <vector>
#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    // 方法一（投机取巧）
    // while (head != nullptr)
    // {
    //   if (head->val == INT_MAX)
    //   {
    //     return true;
    //   }
    //   head->val = INT_MAX;
    //   head = head->next;
    // }

    // 方法二
    if (head == nullptr)
    {
      return false;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    do
    {
      slow = slow->next;

      if (fast->next != nullptr)
      {
        fast = fast->next->next;
      }
      else
      {
        fast = fast->next;
      }

      if (slow == fast)
      {
        if (slow == nullptr)
        {
          return false;
        }
        return true;
      }
    } while (fast != nullptr);

    return false;
  }
};

int main(int argc, char const *argv[])
{
  Solution solution;
  vector<int> nodes = {3, 2, 0, -4};
  int pos = 1;

  ListNode *head = new ListNode(nodes[0]);
  ListNode *cur = head;
  ListNode *cir = nullptr;
  for (size_t i = 1; i < nodes.size(); i++)
  {
    ListNode *temp = new ListNode(nodes[i]);
    if (i == pos)
    {
      cir = temp;
    }
    cur->next = temp;
    cur = cur->next;
  }
  cur->next = cir;

  bool answer = solution.hasCycle(head);
  cout << (answer ? "True" : "False") << endl;

  return 0;
}
