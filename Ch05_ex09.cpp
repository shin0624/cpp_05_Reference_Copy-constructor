#include<iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(const Circle& c);//복사 생성자 선언.  자기 클래스에 대한 참조로 선언
	Circle() { radius = 1; }//일반 생성자
	Circle(int radius) { this->radius = radius; }//매개변수가 있는 생성자.
	double getArea() { return 3.14 * radius * radius; }//면적을 리턴하는 함수
};

Circle::Circle(const Circle& c) {//복사 생성자 구현
	this->radius = c.radius;//circle클래스의 멤버변수 radius = 매개변수 radius(&c가 가리키는 주소값인 radius)
	cout << "복사 생성자 실행 radius = " << radius << endl;
}

int main() {
	Circle src(30);//src 객체의 보통 생성자 호출
	Circle dest(src);//dest 객체의 복사 생성자 호출. dest는 src 객체를 복사한 객체. 30의 값이 들어간다.

	cout << "원본의 면적 = " << src.getArea() << endl;
	cout << "사본의 면적 = " << dest.getArea() << endl;
}