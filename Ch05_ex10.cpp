#include <iostream>
#include <cstring>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name);//������. --> �����Ϸ��� ���� �ڵ����� ����Ʈ ��������� ����
	~Person();//�Ҹ���
	void changeName(const char* name);//��ü�� �̸��� �ٲٱ� ���� �Լ�
	void show() { cout << id << ',' << name << endl; }//id�� �̸��� ����ϱ����� �Լ�
};

Person::Person(int id, const char* name) {//������ ����
	this->id = id;
	int len = strlen(name);//name�� ���ڿ� ������len�� ����
	this->name = new char[len + 1];//name ���ڿ� ���� �Ҵ�. null�� �����ϱ⿡ +1
	strcpy(this->name, name);//name�� ���ڿ� ����.
}

Person::~Person() {//�Ҹ��� ����
	if (name)
		delete[] name;
}//���� name�� ���� �Ҵ� �迭�� ������ �Ҹ��� ���� �� �����Ҵ�޸�(name) �Ҹ�

void Person::changeName(const char* name) {//��ü �̸� ����.
	if (strlen(name) > strlen(this->name))//����  name�� �Ҵ�� �޸� > �ٲٷ��� �̸��� �޸��� ��
		return;//���� name�� �Ҵ�� �޸𸮺��� �� �̸����� �ٲ� �� ����.
	strcpy(this->name, name);//���� name�� �Ҵ�� �޸� ������ �̸����δ� �ٲ� �� �ִ�.

}

int main() {
	Person father(1, "kitae");//father ��ü ����.
	Person daughter(father);//father�� ������ daughter ��ü ����. ��������ڸ� ȣ���Ѵ�.

	cout << "daughter ��ü ���� ���� ----" << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace");//����� ��ü daughter�� name�� �ٲ۴�.-->���� �����̱� ������, father�� daughter���� *name�� ����Ű�� kitae�� �� ��ü�� �������̴�.
	cout << "daughter �̸��� Grace�� ������ �� ---- " << endl;
	father.show();
	daughter.show();

	return 0;//���� �� ��ü�� ����Ű�� name �� �޸𸮴� �� ��ü �� �����Ǵ� �޸��̱⿡, �Ҹ��� ���� �� daughter�� ���� name�޸𸮸� ��ȯ�ع�����. father�� �Ҹ�� ���� �̹� ��ȯ�� �޸𸮸� �ٽ� ��ȯ�ϰ� �ǹǷ�, �����߻�
}