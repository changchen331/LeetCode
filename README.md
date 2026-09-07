# LeetCode 刷题记录

个人 LeetCode 刷题仓库，C++ 实现。共 476 道题。

## 项目结构

```
仓库根/
├── 1.cpp, 2.cpp, ..., 3968.cpp     # 各题源码（按 LeetCode 题号命名）
├── 1.exe, 2.exe, ...               # 对应编译产物
├── algorithms.cpp / tools.cpp      # 学习笔记与个人小工具
├── digital_dp_template_*.cpp       # 模板笔记
├── test/                           # 临时实验目录
├── WORKBUDDY.md                    # AI 行为契约（详见）
└── README.md                       # 本文件
```

## 编译 & 运行

环境：Windows + g++ (MinGW) 或 MSVC。

```bash
# 单题编译（标准 C++17）
g++ -std=c++17 -O2 42.cpp -o 42.exe

# 运行
./42.exe
```

## 代码模板

每道题统一遵循下述模板，详见 [`WORKBUDDY.md`](./WORKBUDDY.md)：

```cpp
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 核心算法
};

int main(int argc, char const *argv[]) {
    Solution solution;
    // 测试用例
    return 0;
}
```

## AI 协作

本仓库使用 AI 助手按"算法老师"角色协作——**引导思考而非直接给答案**。完整行为契约、禁止/鼓励条款、AC 后审阅流程见 [`WORKBUDDY.md`](./WORKBUDDY.md)。

agent 私有产物（AI 长期记忆、每日日志、AC 审阅 skill 等）位于 `.workbuddy/` 目录，**不在版本控制内**，仅本地存在。

## 已完成题目索引

完整题解记录（题号 / 题目 / 算法类型 / 难度）见本地 `.workbuddy/memory/MEMORY.md`，不在 GitHub 上。

## 偏好与历史

- 临时文件一律放 `.workbuddy/`，不污染仓库根
- agent 目录（`.workbuddy/`、`.codebuddy/`、`.claude/`）已被 `.gitignore` 排除
- 重要偏好与历史教训记录在 `.workbuddy/memory/MEMORY.md`「重要教训」段
