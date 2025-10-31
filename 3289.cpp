#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        vector<int> answer;

        unordered_set<int> database;
        for (auto &&num : nums)
        {
            if (database.find(num) != database.end())
                answer.emplace_back(num);
            if (answer.size() == 2)
                break;
            database.insert(num);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2};

    vector<int> answer = solution.getSneakyNumbers(nums);
    cout << answer[0] << " " << answer[1] << endl;

    return 0;
}
