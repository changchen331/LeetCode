#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        int size = prices.size();
        long long answer = size;

        for (int left = 0, right = 1; left < size - 1; left = right++)
        {
            if (prices[left] - 1 == prices[right])
            {
                while (right < size && prices[right] == (prices[right - 1] - 1))
                    right++;
                answer += 1L * (right - left) * (right - left - 1) / 2;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> prices = {3, 2, 1, 4};

    long long answer = solution.getDescentPeriods(prices);
    cout << answer << endl;

    return 0;
}
