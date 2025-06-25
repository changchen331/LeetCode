#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool check(long long mx, vector<int> &nums1, vector<int> &nums2, long long k)
    {
        long long count = 0;
        int size1 = nums1.size(), size2 = nums2.size();

        int i0 = lower_bound(nums1.begin(), nums1.end(), 0) - nums1.begin(); // 四个区域的水平分界线
        int j0 = lower_bound(nums2.begin(), nums2.end(), 0) - nums2.begin(); // 四个区域的垂直分界线

        if (mx < 0)
        {
            // 右上区域
            int i = 0, j = j0;
            while (i < i0 && j < size2)
            {
                if ((1LL * nums1[i] * nums2[j]) > mx)
                    j++;
                else
                {
                    count += size2 - j;
                    i++;
                }
            }

            // 左下区域
            i = i0;
            j = 0;
            while (i < size1 && j < j0)
            {
                if ((1LL * nums1[i] * nums2[j]) > mx)
                    i++;
                else
                {
                    count += size1 - i;
                    j++;
                }
            }
        }
        else
        {
            // 右上区域和左下区域的所有数都 <= 0 <= mx
            count = (1LL * i0 * (size2 - j0)) + (1LL * (size1 - i0) * j0);

            // 左上区域
            int i = 0, j = j0 - 1;
            while (i < i0 && j >= 0)
            {
                if ((1LL * nums1[i] * nums2[j]) > mx)
                    i++;
                else
                {
                    count += i0 - i;
                    j--;
                }
            }

            // 右下区域
            i = i0;
            j = size2 - 1;
            while (i < size1 && j >= j0)
            {
                if ((1LL * nums1[i] * nums2[j]) > mx)
                    j--;
                else
                {
                    count += j - j0 + 1;
                    i++;
                }
            }
        }

        return count >= k;
    }

public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        int size1 = nums1.size(), size2 = nums2.size();

        vector<long long> corners = {1LL * nums1[0] * nums2[0],
                                     1LL * nums1[0] * nums2[size2 - 1],
                                     1LL * nums1[size1 - 1] * nums2[0],
                                     1LL * nums1[size1 - 1] * nums2[size2 - 1]};
        auto minmax_pair = minmax_element(corners.begin(), corners.end());
        long long left = *minmax_pair.first;
        long long right = *minmax_pair.second;
        left--;
        while (left + 1 < right)
        {
            long long mid = left + (right - left) / 2;
            (check(mid, nums1, nums2, k) ? right : left) = mid;
        }

        return right;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1{2, 5};
    vector<int> nums2{3, 4};
    long long k = 2;

    long long answer = solution.kthSmallestProduct(nums1, nums2, k);
    cout << answer << endl;

    return 0;
}
