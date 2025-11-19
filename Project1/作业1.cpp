//此代码仅作很简单的参考

#include<iostream>
using namespace std;
class Array {
public:
	int* data;
	size_t size;
	Array(){
		data = nullptr;
		size = 0;
	}
	Array(int n):size(n) {
		if (n > 0) {
			data = new int[n];
		}
	}
	Array(Array& temp) {
		size = temp.size;
		if (size != 0) {
			data = new int[size];
			for (int i = 0; i < size;i++) {
				data[i] = temp.data[i];
			}
		}
	}
	~Array() {
		delete(data);
		data = nullptr;
		size = 0;
	}
	void set(int index, int value);
	void print();
};
void Array::set(int index, int value) {
	data[index] = value;
}
void Array::print() {
	printf("%0llx:\n", (unsigned long long)data);
	//printf("%0x:\n", data);
	for (size_t i = 0; i < size; i++) {
		printf("%03d:%3d  ", i,data[i]);
	}
	printf("\n");
}
int main() {
	Array arr(10);
	for (int i = 0; i < 10; i++) {
		arr.set(i,100+i);
	}
	arr.print();
	Array arr1(arr);
	arr1.print();

}

