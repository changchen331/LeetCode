#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minSumOfLengths(vector<int> &arr, int target)
    {
        int answer = -1;
        int size = arr.size();

        vector<int> suf(size, INT_MAX);
        for (int l = 0, r = 0, sum = 0; r < size; r++)
        {
            int right = arr[r];
            sum += right;
            int last = r == 0 ? INT_MAX : suf[r - 1];
            if (sum == target)
            {
                suf[r] = min(last, r - l + 1);
            }
            else
            {
                if (sum > target)
                {
                    while (l < r && sum > target)
                    {
                        int left = arr[l++];
                        sum -= left;
                    }
                }

                if (sum == target)
                {
                    suf[r] = min(last, r - l + 1);
                    continue;
                }
                suf[r] = last;
            }
        }

        vector<int> pre(size, INT_MAX);
        for (int l = size - 1, r = size - 1, sum = 0; r > -1; r--)
        {
            int right = arr[r];
            sum += right;
            int last = r == size - 1 ? INT_MAX : pre[r + 1];
            if (sum == target)
            {
                pre[r] = min(last, l - r + 1);
            }
            else
            {
                if (sum > target)
                {
                    while (r < l && sum > target)
                    {
                        int left = arr[l--];
                        sum -= left;
                    }
                }

                if (sum == target)
                {
                    pre[r] = min(last, l - r + 1);
                    continue;
                }
                pre[r] = last;
            }
        }

        long long temp = INT_MAX;
        for (int i = 1; i < size; i++)
        {
            temp = min(temp, (long long)suf[i - 1] + pre[i]);
        }
        answer = temp < INT_MAX ? temp : -1;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> arr = {1, 2, 2, 3, 2, 6, 7, 2, 1, 4, 8};
    int target = 5;

    int answer = solution.minSumOfLengths(arr, target);
    cout << answer << endl;

    return 0;
}
