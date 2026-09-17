#include <iostream>
#include <random>

using namespace std;

// 通过指定范围生成随机数（闭区间整数 [lo, hi]，半开实数 [lo, hi)）。
class Random {
private:
  mt19937 mt;

public:
  // 默认构造：从真随机设备取种子，每次运行结果不同
  Random() {
    random_device rd;
    mt.seed(rd());
  }

  // 范围随机整数，[lo, hi] 含两端点
  int nextInt(int lo, int hi) {
    uniform_int_distribution<int> dist(lo, hi);
    return dist(mt);
  }
};

int main(int argc, char const *argv[]) {
  Random r;
  int low = 1;
  int high = 66;

  cout << r.nextInt(low, high) << endl;

  return 0;
}