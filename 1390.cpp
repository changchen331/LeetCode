#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    int count_divisor(int num)
    {
        vector<int> record;
        int sum = 0;
        for (int i = 1; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                if (i * i != num)
                    record.emplace_back(num / i);
                record.emplace_back(i);

                sum += i + (num / i);
            }
            if (record.size() > 4)
                return 0;
        }

        if (record.size() == 4)
            return sum;
        return 0;
    }

public:
    int sumFourDivisors(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        unordered_map<int, int> memories;
        for (int i = 0; i < size; i++)
        {
            int &num = nums[i];

            if (memories.find(num) != memories.end())
                answer += memories[num];
            else
                answer += memories[num] = count_divisor(num);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {21, 4, 7};

    int answer = solution.sumFourDivisors(nums);
    cout << answer << endl;

    return 0;
}
