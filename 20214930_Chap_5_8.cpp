#include<iostream>
using namespace std;

class MyIntStack {
	int* p;//���� �޸𸮷� ����� ������
	int size;//������ �ִ� ũ��
	int tos;//������ ž�� ����Ű�� �ε���
public:
	MyIntStack();//�⺻ ������
	MyIntStack(int size);//�Ű����� size(������ �ִ� ũ��)�� ���� ������
	MyIntStack(const MyIntStack& s);//���� ������
	~MyIntStack();//�Ҹ���

	bool push(int n);//bool Ÿ���� push�Լ�. ���� n�� ���ÿ� push�Ѵ�.
	//������ �� �������� false��, �ƴϸ� true�� ����

	bool pop(int& n);//������ ž�� �ִ� ���� n�� pop. 
	//���� ������ ��������� false, �ƴϸ� true�� ����
};

bool MyIntStack::push(int n) {//push �Լ� ����
	if (tos > size) {//���� ������ ž tos�� ���� �ִ�ũ�� �̻��� ��(�� ������ ��)
		return false;
	}
	else {	
		p[tos++] = n;//�� ������ ���� ��. �����Ͱ� ����Ű�� �޸�[tos]�� ++
		return true;//true ����
	}
}
bool MyIntStack::pop(int& n) {//pop�Լ� ����. ������ ���
	if (tos < 0) {//tos���� 0 ������ ��(������� ��)
		return false;
	}
	else {
		n = p[--tos];//0�� �ƴ� ��. tos�� �ϳ��ϳ� �A��.
		return true;
	}
}

MyIntStack::MyIntStack() {
	size = 10;
}

MyIntStack::MyIntStack(int size) {
	this->size = size;//�Ű����� size = a(10)
	p = new int[size];//10��ŭ size�� �Ҵ��� �޸𸮸� ����Ű�� p
	tos = 0;//ž�� �ε��� = 0
}
MyIntStack::~MyIntStack() {

	delete[] p;//�Ҹ��� ����. �޸� ��ȯ
}

MyIntStack::MyIntStack(const MyIntStack& src) {//��������� ����
	this->size = src.size;//main()���� b=a�� ����. a�� b�� ���� �ٸ� �޸𸮸� ����Ű�� ���� �ٸ� ���������� �Ҵ����
	this->p = new int[size];
	for (int i = 0; i < src.size; i++) {
		this->p[i] = src.p[i];
	}
}

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; // ���� ����
	b.push(30);
	int n;
	a.pop(n); // ���� a ��
	cout << "���� a���� ���� �� " << n << endl;
	b.pop(n); // ���� b ��
	cout << "���� b���� ���� �� " << n << endl;
}