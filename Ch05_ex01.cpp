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
	void setRadius(int radius) { this->radius = radius; }//�Ű������� ��������� ���� �̸��� ������ ������ this ���. this�����ͷ� ����Ų radius�� �������(private), �ٸ� �ϳ��� �Ű�����

};
Circle::Circle() {
	radius = 1;
	cout << " ������ ���� radius = " << radius << endl;//waffle�� c�� ����ǰ�, c�� ������ Circle()�� ����Ǹ�, ��ü c�� radius�� 1�� �ʱ�ȭ�ǹ����� ������ ������ ������ �ȵǴ� ��.
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << " ������ ���� radius = " << radius << endl;
}
Circle::~Circle() {
	cout << " �Ҹ��� ���� radius = " << radius << endl;
}
void increase(Circle c) {//�Ű����� : ��ü c --> ��ü�� �Ű������� ������ �����ڴ� ������� �ʰ� �Ҹ��ڸ� �����.
	int r = c.getRadius();//radius = waffle�� ���� 30�� ���
	c.setRadius(r + 1);//30+1 = 31�� �Ҹ��ڿ� ��µ� ��.
}

int main() {
	Circle waffle(30);//waffle�� ������ c�� �����.
	increase(waffle);
	cout << waffle.getRadius() << endl;
}