#include <set>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class TaskManager
{
private:
    unordered_map<int, pair<int, int>> t_p_u;
    set<pair<int, int>> p_t;

public:
    TaskManager(vector<vector<int>> &tasks)
    {
        for (auto &&task : tasks)
        {
            t_p_u[task[1]] = {task[2], task[0]};
            p_t.insert({task[2], task[1]});
        }
    }

    void add(int userId, int taskId, int priority)
    {
        t_p_u[taskId] = {priority, userId};
        p_t.insert({priority, taskId});
    }

    void edit(int taskId, int newPriority)
    {
        pair<int, int> &temp = t_p_u[taskId];
        p_t.erase({temp.first, taskId});
        p_t.insert({newPriority, taskId});
        temp.first = newPriority;
    }

    void rmv(int taskId)
    {
        p_t.erase({t_p_u[taskId].first, taskId});
        t_p_u.erase(taskId);
    }

    int execTop()
    {
        int response = -1;
        if (p_t.size() == 0)
            return response;

        pair<int, int> temp = *p_t.rbegin();
        response = t_p_u[temp.second].second;
        t_p_u.erase(temp.second);
        p_t.erase(temp);
        return response;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

int main(int argc, char const *argv[])
{
    TaskManager *obj;
    vector<string> commands = {"TaskManager", "add", "edit", "execTop", "rmv", "add", "execTop"};
    vector<vector<vector<int>>> values = {{{1, 101, 10}, {2, 102, 20}, {3, 103, 15}}, {{4, 104, 5}}, {{102, 8}}, {{}}, {{101}}, {{5, 105, 15}}, {{}}};

    for (int i = 0; i < commands.size(); i++)
    {
        string command = commands[i];
        if (command == "TaskManager")
        {
            obj = new TaskManager(values[i]);
            cout << "null" << " ";
        }
        else if (command == "add")
        {
            obj->add(values[i][0][0], values[i][0][1], values[i][0][2]);
            cout << "null" << " ";
        }
        else if (command == "edit")
        {
            obj->edit(values[i][0][0], values[i][0][1]);
            cout << "null" << " ";
        }
        else if (command == "rmv")
        {
            obj->rmv(values[i][0][0]);
            cout << "null" << " ";
        }
        else
            cout << obj->execTop() << " ";
    }
    cout << endl;

    return 0;
}
