#include<iostream>
using namespace std;
class Circle {
	//������ ���� �а� ��Ŭ ��ü�� �������� �����ϴ� readradius�Լ� �ۼ�
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

void readRadius(Circle& c) {
	int r;
	cout << "������ ���� ������ �Է� : ";
	cin >> r;//������ �Է�
	c.setRadius(r);//������ ����. r�� �Է¹����� &c->r�� ����Ű��, setradius�Լ��� radius�� �ּҰ� ���޵�
}
int main() {
	Circle Donut;
	readRadius(Donut);
	cout << "Donut�� ���� = " << Donut.getArea() << endl;
}