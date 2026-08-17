#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        string answer = "";
        int size = nums.size();

        vector<string> num;
        for (int i = 0; i < size; i++)
        {
            num.push_back(to_string(nums[i]));
        }

        sort(num.begin(), num.end(), [](const string &a, const string &b)
             {
                // 错误方法
                // int la = a.length();
                // int lb = b.length();
                // for (int x = 0, y = 0; x < la || y < lb;) {
                //     char ca = a[x];
                //     char cb = b[y];

                //     if (ca == cb) {
                //         if (x + 1 == la && y + 1 == lb) {
                //             break;
                //         }
                //         x += (x == la - 1) ? 0 : 1;
                //         y += (y == lb - 1) ? 0 : 1;

                //         continue;
                //     }
                //     return ca > cb;
                // }
                // return false; 
                return a + b > b + a; });

        if (stoi(num[0]) == 0)
        {
            return "0";
        }
        for (auto &&n : num)
        {
            answer += n;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {34323, 3432};

    string answer = solution.largestNumber(nums);
    cout << answer << endl;

    return 0;
}
