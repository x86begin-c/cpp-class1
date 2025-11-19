#include<iostream>
using namespace std;
class foo {
	 int x, y;
public:
    void print() {
		printf("%d %d", x, y);
	}
}; 
int main() {
	foo a;
	a.print();
}