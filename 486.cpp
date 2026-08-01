#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int size;
    vector<int> Nums;
    vector<vector<int>> mem;

    int dp(int l, int r)
    {
        if (l > r)
        {
            return 0;
        }

        int &resp = mem[l][r];
        if (resp != INT_MIN)
        {
            return resp;
        }

        resp = max(Nums[l] - dp(l + 1, r), Nums[r] - dp(l, r - 1));
        return resp;
    }

public:
    bool predictTheWinner(vector<int> &nums)
    {
        bool answer = false;
        Nums = nums;
        size = nums.size();
        mem.resize(size, vector<int>(size, INT_MIN));

        int resp = dp(0, size - 1);
        answer = resp >= 0;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 5, 233, 7};

    bool answer = solution.predictTheWinner(nums);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
