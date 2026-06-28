#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int answer = 1;

        sort(arr.begin(), arr.end());
        int size = arr.size();
        arr[0] = 1;
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > arr[i - 1] + 1)
            {
                arr[i] = arr[i - 1] + 1;
            }
        }

        answer = arr.back();
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> arr = {9, 9, 9, 9, 9};

    int answer = solution.maximumElementAfterDecrementingAndRearranging(arr);
    cout << answer << endl;

    return 0;
}
