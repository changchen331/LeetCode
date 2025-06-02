#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int answer = 0, size = ratings.size();

        vector<int> lefts(size, 1);
        for (int i = 1; i < size; i++)
            if (ratings[i] > ratings[i - 1])
                lefts[i] = lefts[i - 1] + 1;

        vector<int> rights(size, 1);
        for (int i = size - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                rights[i] = rights[i + 1] + 1;
            answer += max(lefts[i], rights[i]);
        }

        return answer + max(lefts[size - 1], rights[size - 1]);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> ratings{0, 1, 2, 5, 3, 2, 7};

    int answer = solution.candy(ratings);
    cout << answer << endl;

    return 0;
}
