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
	return tmp;//��ü tmp�� ����. return �� ���� �� tmp�� ���纻 ����->�� ���纻�� getCircle�� ȣ���� ������ ���޵�.
}
int main() {
	Circle c;//��ü c����, radius = 1�� �ʱ�ȭ
	cout << c.getArea() << endl;

	c = getCircle();//tmp��ü�� c�� ����. c�� radius�� 30�� ��
	cout << c.getArea() << endl;
}