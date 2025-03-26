#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Allocator
{
private:
    vector<int> nums;

public:
    Allocator(int n)
    {
        nums.resize(n);
    }

    int allocate(int size, int mID)
    {
        int start = -1, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                start = i;
                count = 0;
                continue;
            }
            count++;
            if (count == size)
            {
                for (int i = 1; i <= size; i++)
                    nums[start + i] = mID;
                return start + 1;
            }
        }
        return -1;
    }

    int freeMemory(int mID)
    {
        int count = 0;
        for (auto &&num : nums)
        {
            if (num == mID)
            {
                num = 0;
                count++;
            }
        }
        return count;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */

int main(int argc, char const *argv[])
{
    Allocator *allocator;
    vector<string> commands{"Allocator", "allocate", "allocate", "allocate", "freeMemory", "allocate", "allocate", "allocate", "freeMemory", "allocate", "freeMemory"};
    vector<vector<int>> values{{10}, {1, 1}, {1, 2}, {1, 3}, {2}, {3, 4}, {1, 1}, {1, 1}, {1}, {10, 2}, {7}};

    for (int i = 0; i < commands.size(); i++)
    {
        string command = commands[i];
        vector<int> value = values[i];
        if (command == "Allocator")
        {
            allocator = new Allocator(value[0]);
            cout << "null";
        }
        else if (command == "allocate")
            cout << allocator->allocate(value[0], value[1]);
        else
            cout << allocator->freeMemory(value[0]);
        cout << (i < commands.size() - 1 ? ", " : "");
    }

    return 0;
}
