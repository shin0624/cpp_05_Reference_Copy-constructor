#include<iostream>
using namespace std;

//�迭 s�� index ���� ������ ���� ������ ����
char& find(char s[], int index) {
	return s[index];//s[index]������ ���� ����
}

int main() {
	char name[] = "Mike";//M, i, k, e, \0
	cout << name << endl;

	find(name, 0) = 'S';//M-->S
	cout << name << endl;

	char& ref = find(name, 2);//ref�� name[2]�� ���� ����.
	ref = 't';
	cout << name << endl;
}