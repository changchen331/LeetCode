#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int answer = 0, size = arr.size();

        for (int i = 0; i < size - 2; i++)
            for (int j = i + 1; j < size - 1; j++)
                for (int k = j + 1; k < size; k++)
                    answer += abs(arr[i] - arr[j]) <= a &&
                              abs(arr[j] - arr[k]) <= b &&
                              abs(arr[k] - arr[i]) <= c;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> arr{3, 0, 1, 1, 9, 7};
    int a = 7;
    int b = 2;
    int c = 3;

    int answer = solution.countGoodTriplets(arr, a, b, c);
    cout << answer << endl;

    return 0;
}
