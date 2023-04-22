#include <iostream>
#include <cstring>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name);//생성자. --> 컴파일러에 의해 자동으로 디폴트 복사생성자 삽입
	~Person();//소멸자
	Person(const Person& person);//복사 생성자 선언.
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

Person::Person(const Person& person) {//복사 생성자 구현. 복사 생성자를 호출한 객체의 id와 name을  this->로 받고 각 person 클래스 객체마다 고유한 값을 갖도록함.
	this->id = person.id;//id값 복사
	int len = strlen(person.name);//name의 문자 개수. 
	this->name = new char[len + 1];//name을 위한 공간 할당.
	strcpy(this->name, person.name);//name의 문자열 복사
	cout << "복사 생성자 실행. 원본 객체의 이름 " << this->name << endl;
}

int main() {
	Person father(1, "kitae");//father 객체 생성.
	Person daughter(father);//father를 복사한 daughter 객체 생성. 복사생성자를 호출한다.

	cout << "daughter 객체 생성 직후 ----" << endl;
	father.show();
	daughter.show();//father의 name 공간이 daughter에게 복사됨. 하지만 복사생성자를 구현해놓았기에, 공유된 메모리공간을 공유하지 않고 각각 별개의 공간을 갖게된다. 초기값은 kitae

	daughter.changeName("Grace");//복사된 객체 daughter의 name을 바꾼다.-->깊은 복사이기 떄문에, father과 daughter는 서로 다른 메모리를 가리키므로 daughter가 change되어도 father는 변화 X
	cout << "daughter 이름을 Grace로 변경한 후 ---- " << endl;
	father.show();
	daughter.show();

	return 0;//-->얕은 복사와 달리 daughter의 name 메모리공간 반환 후 father의 name 메모리공간이 반환된다. 정상작동
}