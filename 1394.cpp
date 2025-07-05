#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int answer = -1, size = arr.size();
        sort(arr.begin(), arr.end());
        arr.push_back(-1);

        int count = 0, maximum = 0;
        for (int i = 0; i < size; i++)
        {
            count++;

            if (arr[i] != arr[i + 1])
            {
                if (count == arr[i] && maximum <= count)
                {
                    answer = arr[i];
                    maximum = count;
                }
                count = 0;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> arr = {19, 12, 11, 14, 18, 8, 6, 6, 13, 9, 8, 3, 10, 10, 1, 10, 5, 12, 13, 13, 9};

    int answer = solution.findLucky(arr);
    cout << answer << endl;

    return 0;
}
