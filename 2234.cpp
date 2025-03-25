#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maximumBeauty(vector<int> &flowers, long long newFlowers, int target, int full, int partial)
    {
        int size = flowers.size();

        long long left = newFlowers - 1LL * target * size;
        for (auto &&flower : flowers)
        {
            flower = min(flower, target);
            left += flower;
        }
        if (left == newFlowers)
            return 1LL * size * full;
        if (left >= 0)
            return max(1LL * size * full, 1LL * (target - 1) * partial + 1LL * (size - 1) * full);

        sort(flowers.begin(), flowers.end());

        long long answer = 0L, pre_sum = 0L;
        for (int i = 1, j = 0; i <= size; i++)
        {
            left += target - flowers[i - 1];
            if (left < 0)
                continue;

            while (j < i && 1LL * flowers[j] * j <= (pre_sum + left))
                pre_sum += flowers[j++];

            long long average = (pre_sum + left) / j;
            long long temp = average * partial + 1LL * (size - i) * full;
            answer = max(answer, temp);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> flowers{1, 3, 1, 1};
    long long newFlowers = 7;
    int target = 6;
    int full = 12;
    int partial = 1;

    long long answer = solution.maximumBeauty(flowers, newFlowers, target, full, partial);
    cout << answer << endl;

    return 0;
}
