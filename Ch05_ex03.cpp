#include<iostream>
using namespace std;

int main() {
	cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
	int i = 1, n = 2, & refn = n;//참조변수 refn 선언

	n = 4;
	refn++;//refn = 5, n=5
	cout << i << '\t' << n << '\t' << refn << endl;

	refn = i;
	refn++;//refn =2, n=2
	cout << i << '\t' << n << '\t' << refn << endl;

	int* p = &refn;//p는 refn의 주소를 저장. p는 n의 주소
	*p = 20;
	cout << i << '\t' << n << '\t' << refn << endl;
}