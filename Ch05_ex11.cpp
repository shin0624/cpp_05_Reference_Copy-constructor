#include <iostream>
#include <cstring>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name);//������. --> �����Ϸ��� ���� �ڵ����� ����Ʈ ��������� ����
	~Person();//�Ҹ���
	Person(const Person& person);//���� ������ ����.
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

Person::Person(const Person& person) {//���� ������ ����. ���� �����ڸ� ȣ���� ��ü�� id�� name��  this->�� �ް� �� person Ŭ���� ��ü���� ������ ���� ��������.
	this->id = person.id;//id�� ����
	int len = strlen(person.name);//name�� ���� ����. 
	this->name = new char[len + 1];//name�� ���� ���� �Ҵ�.
	strcpy(this->name, person.name);//name�� ���ڿ� ����
	cout << "���� ������ ����. ���� ��ü�� �̸� " << this->name << endl;
}

int main() {
	Person father(1, "kitae");//father ��ü ����.
	Person daughter(father);//father�� ������ daughter ��ü ����. ��������ڸ� ȣ���Ѵ�.

	cout << "daughter ��ü ���� ���� ----" << endl;
	father.show();
	daughter.show();//father�� name ������ daughter���� �����. ������ ��������ڸ� �����س��ұ⿡, ������ �޸𸮰����� �������� �ʰ� ���� ������ ������ ���Եȴ�. �ʱⰪ�� kitae

	daughter.changeName("Grace");//����� ��ü daughter�� name�� �ٲ۴�.-->���� �����̱� ������, father�� daughter�� ���� �ٸ� �޸𸮸� ����Ű�Ƿ� daughter�� change�Ǿ father�� ��ȭ X
	cout << "daughter �̸��� Grace�� ������ �� ---- " << endl;
	father.show();
	daughter.show();

	return 0;//-->���� ����� �޸� daughter�� name �޸𸮰��� ��ȯ �� father�� name �޸𸮰����� ��ȯ�ȴ�. �����۵�
}