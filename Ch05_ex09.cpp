#include<iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(const Circle& c);//���� ������ ����.  �ڱ� Ŭ������ ���� ������ ����
	Circle() { radius = 1; }//�Ϲ� ������
	Circle(int radius) { this->radius = radius; }//�Ű������� �ִ� ������.
	double getArea() { return 3.14 * radius * radius; }//������ �����ϴ� �Լ�
};

Circle::Circle(const Circle& c) {//���� ������ ����
	this->radius = c.radius;//circleŬ������ ������� radius = �Ű����� radius(&c�� ����Ű�� �ּҰ��� radius)
	cout << "���� ������ ���� radius = " << radius << endl;
}

int main() {
	Circle src(30);//src ��ü�� ���� ������ ȣ��
	Circle dest(src);//dest ��ü�� ���� ������ ȣ��. dest�� src ��ü�� ������ ��ü. 30�� ���� ����.

	cout << "������ ���� = " << src.getArea() << endl;
	cout << "�纻�� ���� = " << dest.getArea() << endl;
}