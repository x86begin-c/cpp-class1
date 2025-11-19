#include <iostream>
#include <string>
using namespace std;

// 类的声明：包含成员变量和成员函数的原型
class Student {
    // 成员变量（默认private，仅类内可访问）
    string name;  // 姓名
    int id;       // 学号

public:  // 公开接口：类外可访问
    // 成员函数声明（类内）
    void setInfo(string n, int i);  // 设置学生信息
    void showInfo();                // 显示学生信息
};

// 成员函数定义（类外，需用Student::限定）
void Student::setInfo(string n, int i) {
    name = n;  // 访问类内成员变量，无需额外限定
    id = i;
}

void Student::showInfo() {
    cout << "姓名：" << name << "，学号：" << id << endl;
}

int main() {
    // 1. 栈上创建对象
    Student s;
    s.setInfo("张三", 2023001);  // 用.访问成员函数
    s.showInfo();                // 输出：姓名：张三，学号：2023001

    // 2. 堆上创建对象（指针）
    Student* p = new Student;
    p->setInfo("李四", 2023002);  // 用->访问成员函数
    p->showInfo();                // 输出：姓名：李四，学号：2023002

    // 堆上对象必须手动释放，否则内存泄漏
    delete p;
    p = nullptr;  // 避免野指针

    return 0;
}