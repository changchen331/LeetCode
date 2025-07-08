#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class FindSumPairs
{
private:
    vector<int> arr1, arr2;
    unordered_map<int, int> counts;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        arr1 = nums1;
        arr2 = nums2;

        for (auto &&num : nums2)
            counts[num]++;
    }

    void add(int index, int val)
    {
        counts[arr2[index]]--;
        arr2[index] += val;
        counts[arr2[index]]++;
    }

    int count(int tot)
    {
        int response = 0;

        for (auto &&a1 : arr1)
            response += counts.find(tot - a1) != counts.end() ? counts[tot - a1] : 0;

        return response;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main(int argc, char const *argv[])
{
    vector<int> nums1{1, 1, 2, 2, 2, 3};
    vector<int> nums2{1, 4, 5, 2, 5, 4};
    FindSumPairs findSumPairs(nums1, nums2);
    cout << "null ";

    vector<string> commands{"count", "add", "count", "count", "add", "add", "count"};
    vector<vector<int>> values{{7}, {3, 2}, {8}, {4}, {0, 1}, {1, 1}, {7}};
    for (int i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "count")
            cout << findSumPairs.count(values[i][0]) << " ";
        else if (commands[i] == "add")
        {
            findSumPairs.add(values[i][0], values[i][1]);
            cout << "null ";
        }
    }
    cout << endl;

    return 0;
}
