#include<iostream>
using namespace std;

int main() {
	cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
	int i = 1, n = 2, & refn = n;//�������� refn ����

	n = 4;
	refn++;//refn = 5, n=5
	cout << i << '\t' << n << '\t' << refn << endl;

	refn = i;
	refn++;//refn =2, n=2
	cout << i << '\t' << n << '\t' << refn << endl;

	int* p = &refn;//p�� refn�� �ּҸ� ����. p�� n�� �ּ�
	*p = 20;
	cout << i << '\t' << n << '\t' << refn << endl;
}