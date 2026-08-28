#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string lexGreaterPermutation(string s, string target)
    {
        string answer = s;
        int len = s.length();

        int right = 0;
        vector<int> cnt(26, 0);
        for (int i = 0; i < len; i++)
        {
            cnt[s[i] - 'a']++;
            right = max(right, s[i] - 'a');
        }

        // 确认是否有解
        string maxi = "";
        for (int i = right; i > -1; i--)
        {
            int count = cnt[i];
            for (int j = 0; j < count; j++)
            {
                maxi.push_back('a' + i);
            }
        }
        if (maxi <= target)
        {
            return "";
        }

        // 找到最右边的不同点
        int p = len - 1;
        for (int i = 0; i < len; i++)
        {
            char cur = target[i];
            if (cnt[cur - 'a'] > 0)
            {
                answer[i] = cur;
                cnt[cur - 'a']--;
            }
            else
            {
                p = i;
                cnt[answer[p] - 'a']--;
                break;
            }
        }

        // 从右到左
        for (; p > -1; p--)
        {
            cnt[answer[p] - 'a']++;

            bool find = false;
            for (int i = target[p] - 'a' + 1; i <= right; i++)
            {
                if (cnt[i] > 0)
                {
                    answer[p] = 'a' + i;
                    find = true;
                    cnt[i]--;
                    break;
                }
            }
            if (find)
            {
                break;
            }
        }

        // 开始填充后续字符串
        int left = 0;
        for (int i = p + 1; i < len; i++)
        {
            for (; left <= right;)
            {
                if (cnt[left] == 0)
                {
                    left++;
                    continue;
                }
                else
                {
                    answer[i] = 'a' + left;
                    cnt[left]--;
                    break;
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "abc";
    string target = "bba";

    string answer = solution.lexGreaterPermutation(s, target);
    cout << answer << endl;

    return 0;
}
