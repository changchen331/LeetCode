#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    int binary_search(vector<string> str, char target)
    {
        int left = 0, right = str.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (str[mid][0] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }

public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        int size1 = arr1.size();
        int size2 = arr2.size();
        int answer = 0;

        // 超时
        // vector<string> str1(size1), str2(size2);
        // for (int i = 0; i < size1; i++)
        // {
        //     str1[i] = to_string(arr1[i]);
        // }
        // sort(str1.begin(), str1.end());
        // for (int i = 0; i < size2; i++)
        // {
        //     str2[i] = to_string(arr2[i]);
        // }
        // sort(str2.begin(), str2.end());

        // for (auto &&s1 : str1)
        // {
        //     int i2 = binary_search(str2, s1[0]);
        //     for (; i2 < size2; i2++)
        //     {
        //         string s2 = str2[i2];
        //         if (s2[0] < s1[0])
        //         {
        //             continue;
        //         }
        //         else if (s2[0] > s1[0])
        //         {
        //             break;
        //         }
        //         else
        //         {
        //             int length1 = s1.length();
        //             int length2 = s2.length();
        //             int count = 1;
        //             for (int i = 1; i < length1 && i < length2; i++)
        //             {
        //                 if (s1[i] != s2[i])
        //                 {
        //                     break;
        //                 }
        //                 count++;
        //             }
        //             answer = max(answer, count);
        //         }
        //     }
        // }

        // 题解
        unordered_set<string> counts;
        for (auto &&arr : arr2)
        {
            string s = to_string(arr);
            for (int i = 1; i <= s.length(); i++)
            {
                counts.insert(s.substr(0, i));
            }
        }

        for (auto &&arr : arr1)
        {
            string s = to_string(arr);
            for (int i = 1; i <= s.length(); i++)
            {
                if (counts.find(s.substr(0, i)) == counts.end())
                {
                    break;
                }
                answer = max(answer, i);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {1000};

    int answer = solution.longestCommonPrefix(arr1, arr2);
    cout << answer << endl;

    return 0;
}
