#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;  // 姓名（private）
    int id;       // 学号（private）
    int* scores;  // 成绩数组（动态分配，需释放）
    int numScores;// 成绩数量

public:
    // 1. 默认构造函数
    Student() : name("未知"), id(0), scores(nullptr), numScores(0) {
        cout << "默认构造函数被调用" << endl;
    }

    // 2. 带参构造函数（初始化列表）
    Student(string n, int i, int num) : name(n), id(i), numScores(num) {
        scores = new int[numScores];  // 分配成绩数组
        cout << "带参构造函数被调用，分配了" << numScores << "个成绩的内存" << endl;
    }

    // 3. 拷贝构造函数（深拷贝，避免浅拷贝导致的重复释放）
    Student(const Student& other) : name(other.name), id(other.id), numScores(other.numScores) {
        // 深拷贝：重新分配内存并复制数据（而非直接复制指针）
        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = other.scores[i];
        }
        cout << "拷贝构造函数被调用（深拷贝）" << endl;
    }

    // 4. 析构函数（释放资源）
    ~Student() {
        if (scores != nullptr) {
            delete[] scores;
            scores = nullptr;
            cout << "析构函数被调用，释放了成绩数组内存" << endl;
        }
    }

    // 成员函数：设置成绩
    void setScores(int* arr) {
        for (int i = 0; i < numScores; i++) {
            scores[i] = arr[i];
        }
    }

    // 成员函数：显示信息
    void showInfo() {
        cout << "姓名：" << name << "，学号：" << id << endl;
        cout << "成绩：";
        for (int i = 0; i < numScores; i++) {
            cout << scores[i] << " ";
        }
        cout << endl;
    }
};

// 主函数测试
int main() {
    // 测试带参构造
    int scores1[] = { 90, 85, 95 };
    Student s1("张三", 2023001, 3);
    s1.setScores(scores1);
    s1.showInfo();

    // 测试拷贝构造
    Student s2 = s1;  // 用s1初始化s2
    s2.showInfo();

    // 测试默认构造
    Student s3;
    s3.showInfo();  // 姓名：未知，学号：0（成绩未分配）

    return 0;  // 离开作用域，s1、s2、s3的析构函数依次被调用
}