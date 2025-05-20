#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int size = arr.size();

        for (int i = 0, count = 0; i < size; i++)
        {
            if (arr[i] % 2)
                count++;
            else
                count = 0;

            if (count == 3)
                return true;
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> arr{1, 2, 34, 3, 4, 5, 7, 23, 11};

    bool answer = solution.threeConsecutiveOdds(arr);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
