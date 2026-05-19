#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size(), size2 = nums2.size();
        int answer = -1;

        int one = 0, two = 0;
        while (one < size1 && two < size2)
        {
            int num1 = nums1[one];
            int num2 = nums2[two];
            if (num1 < num2)
            {
                one++;
            }
            else if (num1 > num2)
            {
                two++;
            }
            else
            {
                answer = num1;
                break;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {1, 1, 3};
    vector<int> nums2 = {2, 4};

    int answer = solution.getCommon(nums1, nums2);
    cout << answer << endl;

    return 0;
}
