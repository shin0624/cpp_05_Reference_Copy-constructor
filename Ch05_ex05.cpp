#include <iostream>
using namespace std;

bool average(int a[], int size, int& avg) //����Ÿ���� bool�� �ϰ�, ��հ��� �����ϱ� ���� ���� �Ű����� �߰�
{
	if (size <= 0)
		return false;
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += a[i];
	avg = sum / size;//���� �Ű����� avg�� ��հ� ����
	return true;
}

int main() {
	int x[] = { 0,1,2,3,4,5 };
	int avg;
	if (average(x, 6, avg))
		cout << "����� " << avg << endl;//avg���� ����� ������,  average()�Լ��� true ����
	else
		cout << "�Ű����� ���� " << avg << endl;

	if (average(x, -2, avg))
		cout << "����� " << avg << endl;//size�� ���� �� ���� ������ avg���� �ǹ̰� ��������, average()�Լ��� false�� ����
	else
		cout << "�Ű����� ����! " << avg << endl;
}