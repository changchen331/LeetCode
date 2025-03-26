#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int size = arr.size();
        if (size == 1)
            return arr[0];

        bool flag = size % 4 == 0;
        int count = 1, limit = (size - 1) / 4 + 1;
        for (int i = 1; i < size; i++)
        {
            if (arr[i] == arr[i - 1])
                count++;
            else
                count = 1;

            if (flag && count > limit || !flag && count >= limit)
                return arr[i];
        }

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> arr{1, 2, 3, 3};

    int answer = solution.findSpecialInteger(arr);
    cout << answer << endl;

    return 0;
}
