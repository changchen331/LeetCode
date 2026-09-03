#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        bool eve = true, odd = true;
        sort(nums1.begin(), nums1.end());

        int size = nums1.size();
        bool has_odd = false;
        for (int i = 0; i < size; i++)
        {
            if (!eve && !odd)
            {
                break;
            }

            int cur = nums1[i] % 2;

            eve &= (cur == 0) || has_odd;
            odd &= (cur == 1) || has_odd;

            if (!has_odd && cur == 1)
            {
                has_odd = true;
            }
        }

        return eve || odd;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {1, 4, 7};

    bool answer = solution.uniformArray(nums1);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
