#include <iostream>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int size1 = version1.size(), size2 = version2.size();

        string record1 = "0", record2 = "0";
        int position1 = 0, position2 = 0;
        while (position1 < size1 || position2 < size2)
        {
            // version 1
            if (position1 < size1)
            {
                for (; position1 < size1; position1++)
                {
                    char current = version1[position1];
                    if (current == '.')
                    {
                        position1++;
                        break;
                    }
                    record1.push_back(current);
                }
            }

            // version 2
            if (position2 < size2)
            {
                for (; position2 < size2; position2++)
                {
                    char current = version2[position2];
                    if (current == '.')
                    {
                        position2++;
                        break;
                    }
                    record2.push_back(current);
                }
            }

            int temp1 = stoi(record1), temp2 = stoi(record2);
            if (temp1 > temp2)
                return 1;
            else if (temp1 < temp2)
                return -1;

            record1 = "0";
            record2 = "0";
        }

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string version1 = "1.2";
    string version2 = "1.10";

    int answer = solution.compareVersion(version1, version2);
    cout << answer << endl;

    return 0;
}
