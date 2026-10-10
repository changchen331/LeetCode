#include <vector>
#include <iostream>
#include <unordered_set>
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
  ListNode *detectCycle(ListNode *head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }

    // 方法一（未达题目要求）
    // unordered_set<ListNode *> s;
    // ListNode *cur = head->next;
    // s.insert(head);
    // while (cur != nullptr)
    // {
    //   if (s.find(cur) != s.end())
    //   {
    //     return cur;
    //   }
    //   s.insert(cur);
    //   cur = cur->next;
    // }

    // 方法二
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
        slow = head;
        while (slow != fast)
        {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }

    return nullptr;
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

  ListNode *answer = solution.detectCycle(head);
  cout << (answer != nullptr ? (answer->val) : -1) << endl;

  return 0;
}
