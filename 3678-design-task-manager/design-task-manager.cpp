#include <bits/stdc++.h>
using namespace std;

struct Task {
    int userId;
    int taskId;
    int priority;
};

struct Cmp {
    bool operator()(const Task &a, const Task &b) const {
        if (a.priority != b.priority) return a.priority > b.priority;
        return a.taskId > b.taskId;
    }
};

class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            add(t[0], t[1], t[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        Task t{userId, taskId, priority};
        taskMap[taskId] = t;
        taskSet.insert(t);
    }
    
    void edit(int taskId, int newPriority) {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end()) return;
        Task old = it->second;
        taskSet.erase(old);
        Task nw{old.userId, taskId, newPriority};
        taskMap[taskId] = nw;
        taskSet.insert(nw);
    }
    
    void rmv(int taskId) {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end()) return;
        Task old = it->second;
        taskSet.erase(old);
        taskMap.erase(it);
    }
    
    int execTop() {
        if (taskSet.empty()) return -1;
        auto it = taskSet.begin();
        Task t = *it;
        taskSet.erase(it);
        taskMap.erase(t.taskId);
        return t.userId;
    }

private:
    unordered_map<int, Task> taskMap;  // key = taskId
    set<Task, Cmp> taskSet;
};