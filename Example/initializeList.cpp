#include <iostream>

using namespace std;

class Widgettest {
public:
	int a = 2;

public:
	Widgettest() = default;
	Widgettest(int i, bool b) {
		cout << "1번 생성자 " << endl;
	}
	Widgettest(int i, double d) { // 2번 생성자라고 하자
		cout << "2번 생성자" << endl;
	}
	Widgettest(std::initializer_list<long double> il) { // 3번 생성자라고 하자
		cout << "3번 생성자" << endl;
	}
	Widgettest(const Widgettest& rhs) {
		cout << "복사 생성자 호출" << endl;
	}
	Widgettest(Widgettest&& rhs) {
		cout << "move constructor 호출" << endl;
	}
	Widgettest& operator=(const Widgettest& rhs) {
		cout << "복사 대입 연산자 호출 " << endl;
	}
	void print() {
		cout << "Widgettest" << endl;
	}
};

int main() {
    Widgettest w1(10, true); // 1번 생성자 호출

	Widgettest w2{ 10, true }; // 10과 true를 long double형으로 바꾸면서 
						   // 3번 생성자 호출(3번 생성자가 없었다면 1번 호출)

	Widgettest w3(10, 5.0);  // 2번 생성자 호출

	Widgettest w4{ 10, 5.0 };  // 10번과 5.0을 long double형으로 바꾸면서
						   // 3번 생성자 호출(3번 생성자가 없었다면 2번 호출)

	Widgettest w5(w4); // uses parens, calls copy ctor
	Widgettest w6{ w4 }; // uses braces, calls
					 // std::initializer_list ctor
					 // (w4 converts to float, and float
					 // converts to long double)

	Widgettest w7(std::move(w4)); // uses parens, calls move ctor
	Widgettest w8{ std::move(w4) }; // uses braces, calls
								// std::initializer_list ctor
								// (for same reason as w6)
}