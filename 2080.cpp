#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class RangeFreqQuery
{
private:
    unordered_map<int, vector<int>> value_positions;

    int binary_search(vector<int> &positions, int value)
    {
        int left = 0, right = positions.size() - 1;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (positions[middle] >= value)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return left;
    }

public:
    RangeFreqQuery(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
            value_positions[arr[i]].push_back(i);
    }

    int query(int left, int right, int value)
    {
        auto temp = value_positions.find(value);
        if (temp == value_positions.end())
            return 0;
        vector<int> &positons = temp->second;
        return binary_search(positons, right + 1) -
               binary_search(positons, left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main(int argc, char const *argv[])
{
    vector<int> arr{1, 1, 1, 2, 2};
    RangeFreqQuery *obj = new RangeFreqQuery(arr);
    int left = 0;
    int right = 1;
    int value = 2;

    int answer = obj->query(left, right, value);
    cout << answer << endl;

    return 0;
}
