#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> answer;
        int size = nums.size();
        vector<int> numbers(size + 1);

        int count = -1;
        for (auto &&num : nums)
        {
            int &number = numbers[num];
            if (number <= count)
                answer[number].push_back(num);
            else
            {
                answer.push_back({num});
                count++;
            }
            number++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 3, 4, 1, 2, 3, 1};

    vector<vector<int>> answer = solution.findMatrix(nums);
    for (auto &&ans : answer)
    {
        for (auto &&a : ans)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
