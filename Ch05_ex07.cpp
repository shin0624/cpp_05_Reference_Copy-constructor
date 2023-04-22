#include<iostream>
using namespace std;
class Circle {
	//반지름 값을 읽고 서클 객체에 반지름을 설정하는 readradius함수 작성
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

void readRadius(Circle& c) {
	int r;
	cout << "반지름 값을 정수로 입력 : ";
	cin >> r;//반지름 입력
	c.setRadius(r);//반지름 설정. r을 입력받으면 &c->r을 가리키고, setradius함수의 radius로 주소가 전달됨
}
int main() {
	Circle Donut;
	readRadius(Donut);
	cout << "Donut의 면적 = " << Donut.getArea() << endl;
}