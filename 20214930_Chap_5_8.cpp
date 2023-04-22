#include<iostream>
using namespace std;

class MyIntStack {
	int* p;//스택 메모리로 사용할 포인터
	int size;//스택의 최대 크기
	int tos;//스택의 탑을 가리키는 인덱스
public:
	MyIntStack();//기본 생성자
	MyIntStack(int size);//매개변수 size(스택의 최대 크기)를 갖는 생성자
	MyIntStack(const MyIntStack& s);//복사 생성자
	~MyIntStack();//소멸자

	bool push(int n);//bool 타입의 push함수. 정수 n을 스택에 push한다.
	//스택이 꽉 차있으면 false를, 아니면 true를 리턴

	bool pop(int& n);//스택의 탑에 있는 값을 n에 pop. 
	//만일 스택이 비어있으면 false, 아니면 true를 리턴
};

bool MyIntStack::push(int n) {//push 함수 구현
	if (tos > size) {//만약 스택의 탑 tos가 스택 최대크기 이상일 때(꽉 차있을 때)
		return false;
	}
	else {	
		p[tos++] = n;//꽉 차있지 않을 때. 포인터가 가리키는 메모리[tos]를 ++
		return true;//true 리턴
	}
}
bool MyIntStack::pop(int& n) {//pop함수 구현. 참조자 사용
	if (tos < 0) {//tos값이 0 이하일 때(비어있을 때)
		return false;
	}
	else {
		n = p[--tos];//0이 아닐 때. tos를 하나하나 뺸다.
		return true;
	}
}

MyIntStack::MyIntStack() {
	size = 10;
}

MyIntStack::MyIntStack(int size) {
	this->size = size;//매개변수 size = a(10)
	p = new int[size];//10만큼 size를 할당한 메모리를 가리키는 p
	tos = 0;//탑의 인덱스 = 0
}
MyIntStack::~MyIntStack() {

	delete[] p;//소멸자 실행. 메모리 반환
}

MyIntStack::MyIntStack(const MyIntStack& src) {//복사생성자 구현
	this->size = src.size;//main()에서 b=a로 복사. a와 b는 각각 다른 메모리를 가리키며 각각 다른 변수공간을 할당받음
	this->p = new int[size];
	for (int i = 0; i < src.size; i++) {
		this->p[i] = src.p[i];
	}
}

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; // 복사 생성
	b.push(30);
	int n;
	a.pop(n); // 스택 a 팝
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n); // 스택 b 팝
	cout << "스택 b에서 팝한 값 " << n << endl;
}