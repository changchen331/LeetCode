#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int answer = 0;
        int size = height.size();

        // 方法 1（超时）
        // for (int i = 0; i < size; i++)
        // {
        //     int left = height[i];
        //     for (int j = size - 1; j > i; j--)
        //     {
        //         int right = height[j];
        //         int temp = min(left, right) * (j - i);
        //         answer = max(answer, temp);
        //     }
        // }

        // 方法 2
        int left = 0, right = size - 1;
        for (; left < size && right > -1;)
        {
            int l = height[left];
            int r = height[right];
            int temp = min(l, r) * (right - left);
            answer = max(answer, temp);
            if (l < r)
            {
                left++;
            }
            else if (l > r)
            {
                right--;
            }
            else
            {
                // left++;
                right--;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int answer = solution.maxArea(height);
    cout << answer << endl;

    return 0;
}
