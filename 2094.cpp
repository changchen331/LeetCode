#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        vector<int> answer;

        vector<int> records(10, 0);
        for (auto &&digit : digits)
            records[digit]++;

        for (int i = 100; i < 1000; i++)
        {
            if (i % 2)
                continue;

            vector<int> temp = records;
            bool flag = true;
            for (int j = 0, current = i; j < 3; j++, current /= 10)
                if (!(flag &= temp[current % 10]-- > 0))
                    break;
            if (flag)
                answer.emplace_back(i);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> digits{2, 1, 3, 0};

    vector<int> answer = solution.findEvenNumbers(digits);
    for (auto &&ans : answer)
        cout << ans << " ";

    return 0;
}
