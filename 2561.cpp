#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        long long answer = 0;
        int size = basket1.size();

        unordered_map<int, int> count;
        for (int i = 0; i < size; i++)
        {
            count[basket1[i]]++;
            count[basket2[i]]--;
        }

        vector<int> a, b;
        int minimum = INT_MAX;
        for (auto &&[x, c] : count)
        {
            if (c % 2 != 0)
                return -1;

            minimum = min(minimum, x);
            if (c > 0)
                for (int i = 0; i < (c / 2); i++)
                    a.push_back(x);
            else
                for (int i = 0; i < (-c / 2); i++)
                    b.push_back(x);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());

        for (int i = 0; i < a.size(); i++)
            answer += min({a[i], b[i], minimum * 2});

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> basket1{4, 2, 2, 2};
    vector<int> basket2{1, 4, 1, 2};

    long long answer = solution.minCost(basket1, basket2);
    cout << answer << endl;

    return 0;
}
