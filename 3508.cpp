#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Router
{
private:
    // 自定义哈希函数
    struct PairHash
    {
        size_t operator()(const std::pair<int, int> &p) const
        {
            size_t seed = 0;
            // 组合第一个整数的哈希
            seed ^= std::hash<int>{}(p.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            // 组合第二个整数的哈希
            seed ^= std::hash<int>{}(p.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };

    struct TupleHash
    {
        template <typename T>
        static void hash_combine(size_t &seed, const T &v)
        {
            // 参考 boost::hash_combine
            seed ^= hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }

        size_t operator()(const tuple<int, int, int> &t) const
        {
            auto &[a, b, c] = t;
            size_t seed = 0;
            hash_combine(seed, a);
            hash_combine(seed, b);
            hash_combine(seed, c);
            return seed;
        }
    };

    int memory_limit;
    queue<pair<int, int>> sources;
    unordered_map<pair<int, int>, vector<int>, PairHash> packets;
    unordered_map<int, vector<int>> destinations;

    queue<tuple<int, int, int>> packet_q; // packet 队列
    // 注：如果不想手写 TupleHash，可以用 set
    unordered_set<tuple<int, int, int>, TupleHash> packet_set; // packet 集合
    // deque 支持随机访问，方便二分
    unordered_map<int, deque<int>> dest_to_timestamps; // destination -> [timestamp]

public:
    Router(int memoryLimit)
    {
        memory_limit = memoryLimit;
    }

    // 我的解法（超时）
    // bool addPacket(int source, int destination, int timestamp)
    // {
    //     bool response = true;
    //     pair<int, int> index = {source, destination};
    //     vector<int> &packet = packets[index];
    //     if (find(packet.begin(), packet.end(), timestamp) == packet.end())
    //     {
    //         sources.push(index);
    //         if (packet.size() == 0)
    //             destinations[destination].push_back(source);
    //         packets[index].push_back(timestamp);

    //         if (sources.size() > memory_limit)
    //             forwardPacket();
    //     }
    //     else
    //         response = false;
    //     return response;
    // }

    // vector<int> forwardPacket()
    // {
    //     if (sources.size() == 0)
    //         return {};
    //     // sources
    //     pair<int, int> source = sources.front();
    //     sources.pop();
    //     // packets
    //     int time = packets[source].front();
    //     packets[source].erase(packets[source].begin());
    //     // destinations
    //     vector<int> &packet = packets[source];
    //     if (packet.size() == 0)
    //     {
    //         vector<int> &d_s = destinations[source.second];
    //         d_s.erase(find(d_s.begin(), d_s.end(), source.first));
    //     }
    //     return {source.first, source.second, time};
    // }

    // int getCount(int destination, int startTime, int endTime)
    // {
    //     int response = 0;
    //     vector<int> &d_s = destinations[destination];
    //     for (auto &&s : d_s)
    //     {
    //         if (s == -1)
    //             continue;
    //         vector<int> &time = packets[{s, destination}];
    //         for (auto &&t : time)
    //             response += ((startTime <= t) && (t <= endTime));
    //     }
    //     return response;
    // }

    // 官解
    bool addPacket(int source, int destination, int timestamp)
    {
        auto packet = tuple(source, destination, timestamp);
        if (!packet_set.insert(packet).second)
            return false; // packet 在 packet_set 中

        if (packet_q.size() == memory_limit)
            forwardPacket(); // 太多了

        packet_q.push(packet); // 入队
        dest_to_timestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket()
    {
        if (packet_q.empty())
            return {};

        auto packet = packet_q.front(); // 出队
        packet_q.pop();
        packet_set.erase(packet);
        auto [source, destination, timestamp] = packet;
        dest_to_timestamps[destination].pop_front();
        return {source, destination, timestamp};
    }

    int getCount(int destination, int startTime, int endTime)
    {
        auto &timestamps = dest_to_timestamps[destination];
        auto left = lower_bound(timestamps.begin(), timestamps.end(), startTime);
        auto right = upper_bound(timestamps.begin(), timestamps.end(), endTime);
        return right - left;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

int main(int argc, char const *argv[])
{
    Router *obj;

    // vector<string> commands = {"Router", "addPacket", "addPacket", "addPacket", "addPacket", "addPacket", "forwardPacket", "addPacket", "getCount"};
    // vector<vector<int>> values = {{3}, {1, 4, 90}, {2, 5, 90}, {1, 4, 90}, {3, 5, 95}, {4, 5, 105}, {}, {5, 2, 110}, {5, 100, 110}};
    vector<string> commands = {"Router", "addPacket", "getCount"};
    vector<vector<int>> values = {{5}, {2, 4, 4}, {4, 3, 4}};

    for (int i = 0; i < commands.size(); i++)
    {
        string command = commands[i];
        auto value = values[i];

        if (command == "Router")
        {
            obj = new Router(value[0]);
            cout << "null" << " ";
        }
        else if (command == "addPacket")
        {
            auto flag = obj->addPacket(value[0], value[1], value[2]);
            cout << (flag ? "true" : "false") << " ";
        }
        else if (command == "forwardPacket")
        {
            auto temp = obj->forwardPacket();
            cout << "[" << temp[0] << ", " << temp[1] << ", " << temp[2] << "] ";
        }
        else if (command == "getCount")
            cout << obj->getCount(value[0], value[1], value[2]) << " ";
    }
    cout << endl;

    return 0;
}
