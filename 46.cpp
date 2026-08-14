#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<vector<int>> answer;
    vector<int> Nums;
    vector<bool> mem;
    vector<int> cur;
    int size;

    void dfs(int pos)
    {
        if (pos == size)
        {
            answer.push_back(cur);
            return;
        }

        for (int i = 0; i < size; i++)
        {
            int temp = Nums[i];
            if (mem[temp + 10])
            {
                continue;
            }

            cur.push_back(temp);
            mem[temp + 10] = true;
            dfs(pos + 1);
            mem[temp + 10] = false;
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        Nums = nums;
        size = nums.size();
        mem = vector<bool>(21, false);

        dfs(0);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> answer = solution.permute(nums);
    for (auto &&ans : answer)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            int a = ans[i];
            cout << a;
            if (i < ans.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
