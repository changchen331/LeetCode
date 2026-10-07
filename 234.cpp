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
  bool isPalindrome(ListNode *head)
  {
    // 方法一
    // int len = 0;
    // ListNode *temp = head;
    // while (temp != nullptr)
    // {
    //   temp = temp->next;
    //   len++;
    // }
    // if (len == 1)
    // {
    //   return true;
    // }

    // ListNode *l = new ListNode(-1);
    // ListNode *r = new ListNode(1);
    // int count = 1;
    // ListNode *ttemp = head;
    // ListNode *pre = nullptr;
    // ListNode *nxt = nullptr;
    // while (count <= len / 2)
    // {
    //   nxt = ttemp->next;
    //   ttemp->next = pre;
    //   pre = ttemp;
    //   ttemp = nxt;
    //   if (count == len / 2)
    //   {
    //     l = pre;
    //     if (len % 2 == 0)
    //     {
    //       r = ttemp;
    //     }
    //     else
    //     {
    //       r = ttemp->next;
    //     }
    //   }
    //   count++;
    // }

    // for (int i = 0; i < len / 2; i++)
    // {
    //   if (l->val != r->val)
    //   {
    //     return false;
    //   }
    //   l = l->next;
    //   r = r->next;
    // }

    // 方法二（快慢指针）
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
    slow = slow->next;

    ListNode *pre = nullptr;
    ListNode *nxt = nullptr;
    while (slow != nullptr)
    {
      nxt = slow->next;
      slow->next = pre;
      pre = slow;
      slow = nxt;
    }

    while (pre != nullptr)
    {
      if (pre->val != head->val)
      {
        return false;
      }
      pre = pre->next;
      head = head->next;
    }

    return true;
  }
};

int main(int argc, char const *argv[])
{
  Solution solution;
  vector<int> values = {1};
  ListNode *head = new ListNode(values[0]);

  ListNode *temp = head;
  for (size_t i = 1; i < values.size(); i++)
  {
    temp->next = new ListNode(values[i]);
    temp = temp->next;
  }

  bool answer = solution.isPalindrome(head);
  cout << (answer ? "True" : "False") << endl;

  return 0;
}
