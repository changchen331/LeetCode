#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int answer = 0;
        int size1 = nums1.size(), size2 = nums2.size();

        // 超时
        // for (int i = 0; i < size1; i++)
        // {
        //     int num1 = nums1[i];
        //     for (int j = size2 - 1; j >= i; j--)
        //     {
        //         int num2 = nums2[j];
        //         if (num1 <= num2)
        //         {
        //             answer = max(answer, j - i);
        //             break;
        //         }
        //     }
        // }

        // 方法二
        int left = 0, right = 1;
        for (; left < size1 && right < size2;)
        {
            int numL = nums1[left];
            int numR = nums2[right];
            if (numL > numR)
            {
                answer = max(answer, right - left - 1);
                right = max(right, ++left);
            }
            else
            {
                right++;
            }
        }

        answer = max(answer, right - left - 1);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {30, 29, 19, 5};
    vector<int> nums2 = {25, 25, 25, 25, 25};

    int answer = solution.maxDistance(nums1, nums2);
    cout << answer << endl;

    return 0;
}
