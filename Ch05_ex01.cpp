#include<iostream>
using namespace std;

class Circle {
private:
	int radius;
		
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }//매개변수와 멤버변수가 같은 이름을 가지기 때문에 this 사용. this포인터로 가리킨 radius는 멤버변수(private), 다른 하나는 매개변수

};
Circle::Circle() {
	radius = 1;
	cout << " 생성자 실행 radius = " << radius << endl;//waffle이 c에 복사되고, c의 생성자 Circle()이 실행되면, 객체 c의 radius가 1로 초기화되버리기 때문에 생성자 실행이 안되는 것.
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << " 생성자 실행 radius = " << radius << endl;
}
Circle::~Circle() {
	cout << " 소멸자 실행 radius = " << radius << endl;
}
void increase(Circle c) {//매개변수 : 객체 c --> 객체를 매개변수로 가지면 생성자는 실행되지 않고 소멸자만 실행됨.
	int r = c.getRadius();//radius = waffle의 값인 30이 출력
	c.setRadius(r + 1);//30+1 = 31이 소멸자에 출력될 것.
}

int main() {
	Circle waffle(30);//waffle의 내용이 c로 복사됨.
	increase(waffle);
	cout << waffle.getRadius() << endl;
}