#include<iostream>
using namespace std;

//배열 s의 index 원소 공간에 대한 참조를 리턴
char& find(char s[], int index) {
	return s[index];//s[index]공간의 참조 리턴
}

int main() {
	char name[] = "Mike";//M, i, k, e, \0
	cout << name << endl;

	find(name, 0) = 'S';//M-->S
	cout << name << endl;

	char& ref = find(name, 2);//ref는 name[2]에 대한 별명.
	ref = 't';
	cout << name << endl;
}