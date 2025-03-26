#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool check(vector<int> &price, int k, int difference)
    {
        int last = price[0], count = 1;
        for (int i = 1; i < price.size(); i++)
            if (price[i] - last >= difference)
            {
                last = price[i];
                if (++count == k)
                    break;
            }
        return count == k;
    }

public:
    int maximumTastiness(vector<int> &price, int k)
    {
        sort(price.begin(), price.end());

        int left = 0;
        int right = (price.back() - price[0]) / (k - 1) + 1;
        if (k == 2)
            return right - 1;

        while (left + 1 < right)
        {
            int middle = left + (right - left) / 2;

            if (check(price, k, middle))
                left = middle;
            else
                right = middle;
        }

        return left;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> price{13, 5, 1, 8, 21, 2};
    int k = 3;

    int answer = solution.maximumTastiness(price, k);
    cout << answer << endl;

    return 0;
}
