#include <set>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class NumberContainers
{
    unordered_map<int, int> index_to_num;
    unordered_map<int, set<int>> num_to_index;

public:
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        // 移除旧数据
        auto it = index_to_num.find(index);
        if (it != index_to_num.end())
            num_to_index[it->second].erase(index);

        // 添加新数据
        index_to_num[index] = number;
        num_to_index[number].insert(index);
    }

    int find(int number)
    {
        auto it = num_to_index.find(number);
        return it == num_to_index.end() || it->second.empty() ? -1 : *it->second.begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

int main(int argc, char const *argv[])
{
    vector<string> commands = {"NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"};
    vector<vector<int>> values = {{}, {10}, {2, 10}, {1, 10}, {3, 10}, {5, 10}, {10}, {1, 20}, {10}};
    NumberContainers *obj;

    for (int i = 0; i < commands.size(); i++)
    {
        string command = commands[i];

        if (command == "NumberContainers")
            obj = new NumberContainers();
        else if (command == "change")
            obj->change(values[i][0], values[i][1]);
        else
            cout << obj->find(values[i][0]) << (i < commands.size() - 1 ? " " : "\n");
    }

    return 0;
}
