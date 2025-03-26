#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int size = arr.size();
        if (size == 1)
            return {-1};

        // 方法 1（慢）
        // int max = *max_element(arr.begin() + 1, arr.end());
        // arr[0] = max;

        // for (int i = 1; i < arr.size() - 2; i++)
        // {
        //     if (arr[i] == max)
        //         max = *max_element(arr.begin() + i + 1, arr.end());
        //     arr[i] = max;
        // }
        // arr[size - 2] = arr[size - 1];
        // arr[size - 1] = -1;
        // return arr;

        // 方法 2
        int maximum = -1, temp;
        for (int i = size - 1; i >= 0; i--)
        {
            temp = arr[i];
            arr[i] = maximum;
            maximum = max(temp, maximum);
        }
        return arr;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> arr{17, 18, 5, 4, 6, 1};

    vector<int> answer = solution.replaceElements(arr);
    for (auto &&a : answer)
        cout << a << "\t";
    cout << endl;

    return 0;
}
