#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        bool eve = true;
        int size = nums1.size();

        bool has_odd = false;
        for (int i = 0; i < size; i++)
        {
            int cur = nums1[i] % 2;

            eve &= (cur == 0);

            if (!has_odd && cur == 1)
            {
                has_odd = true;
                break;
            }
        }

        return eve || has_odd;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {4, 6};

    bool answer = solution.uniformArray(nums1);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
