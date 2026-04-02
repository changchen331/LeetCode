#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    struct Comparator
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            if (a.first != b.first)
            {
                return a.first < b.first;
            }

            return a.second < b.second;
        }
    };

public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<int> answer;
        int size = arr.size();

        vector<pair<int, int>> pairs;
        for (auto &&item : arr)
        {
            int temp = item, count = 0;
            while (temp > 0)
            {
                count += (temp & 1);
                temp >>= 1;
            }
            pairs.emplace_back(count, item);
        }
        sort(pairs.begin(), pairs.end(), Comparator());

        for (auto &&p : pairs)
        {
            answer.emplace_back(p.second);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    vector<int> answer = solution.sortByBits(arr);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
