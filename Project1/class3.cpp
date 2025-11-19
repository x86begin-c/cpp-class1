#include<iostream>
using namespace std;
class Student {
    string name;
    int id;
public:
    // 默认构造函数（无参数）
    Student() {
        name = "未知";
        id = 0;
    }
    Student(string n, int i) {
        name = n;  
        id = i;
    }
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
    s.showInfo();                // 输出：姓名：未知，学号：0

    // 2. 堆上创建对象（指针）
    Student* p = new Student;
    p->setInfo("李四", 2023002);  // 用->访问成员函数
    p->showInfo();                // 输出：姓名：李四，学号：2023002

    // 堆上对象必须手动释放，否则内存泄漏
    delete p;
    p = nullptr;  // 避免野指针
    Student s1("王五", 2023003);  // 栈上对象：直接传参
    Student* p1 = new Student("赵六", 2023004);  // 堆上对象：new时传参
    s1.showInfo();
    p1->showInfo();
}