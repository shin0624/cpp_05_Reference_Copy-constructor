#include<iostream>
using namespace std;

class Circle {
private:
	int radius;

public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	
	double getArea() { return 3.14 * radius * radius; }
	

};

Circle getCircle() {
	Circle tmp(30);
	return tmp;//객체 tmp를 리턴. return 문 실행 시 tmp의 복사본 생성->이 복사본이 getCircle을 호출한 곳으로 전달됨.
}
int main() {
	Circle c;//객체 c생성, radius = 1로 초기화
	cout << c.getArea() << endl;

	c = getCircle();//tmp객체가 c에 복사. c의 radius는 30이 됨
	cout << c.getArea() << endl;
}