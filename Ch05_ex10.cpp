#include <iostream>
#include <cstring>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name);//생성자. --> 컴파일러에 의해 자동으로 디폴트 복사생성자 삽입
	~Person();//소멸자
	void changeName(const char* name);//객체의 이름을 바꾸기 위한 함수
	void show() { cout << id << ',' << name << endl; }//id와 이름을 출력하기위한 함수
};

Person::Person(int id, const char* name) {//생성자 구현
	this->id = id;
	int len = strlen(name);//name의 문자열 개수를len에 저장
	this->name = new char[len + 1];//name 문자열 공간 할당. null을 포함하기에 +1
	strcpy(this->name, name);//name에 문자열 복사.
}

Person::~Person() {//소멸자 구현
	if (name)
		delete[] name;
}//만일 name에 동적 할당 배열이 있으면 소멸자 실행 시 동적할당메모리(name) 소멸

void Person::changeName(const char* name) {//객체 이름 변경.
	if (strlen(name) > strlen(this->name))//현재  name에 할당된 메모리 > 바꾸려는 이름의 메모리일 떄
		return;//현재 name에 할당된 메모리보다 긴 이름으로 바꿀 수 없다.
	strcpy(this->name, name);//현재 name에 할당된 메모리 이하의 이름으로는 바꿀 수 있다.

}

int main() {
	Person father(1, "kitae");//father 객체 생성.
	Person daughter(father);//father를 복사한 daughter 객체 생성. 복사생성자를 호출한다.

	cout << "daughter 객체 생성 직후 ----" << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace");//복사된 객체 daughter의 name을 바꾼다.-->얕은 복사이기 때문에, father과 daughter에서 *name이 가리키는 kitae는 두 객체가 공유중이다.
	cout << "daughter 이름을 Grace로 변경한 후 ---- " << endl;
	father.show();
	daughter.show();

	return 0;//위의 두 객체가 가리키는 name 의 메모리는 두 객체 간 공유되는 메모리이기에, 소멸자 실행 시 daughter가 먼저 name메모리를 반환해버린다. father가 소멸될 때는 이미 반환된 메모리를 다시 반환하게 되므로, 오류발생
}