#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

using namespace std;

class Class
{
public :
	void MemberFunc() {}
};



void Function1()
{
	cout << "function" << endl;
	this_thread::sleep_for(5s);
}

void Function2(int& a, int b)
{
	a = 30;
}

void Function3(int a, int b)
{
	cout << "function_3" << endl;
}


int main()
{
	thread th1(&Function1);

	// 아래의 둘 중 하나의 함수는 호출해야 에러 뜨지 않음.
	th1.join(); // 이 줄에서 th1이 끝날 때 까지 대기
	//th1.detach(); // th1이 어떻게 돌든 놔두고 메인 스레드 진행. 다만, main()함수가 끝나면 프로세스가 끝나므로 function()도 중간에 끊길 수 있다.

	int arg_1 = 1;
	int arg_2 = 2;
	thread th2(&Function2, ref(arg_1), arg_2); // 스레드 실행법 1 : thread의 객체를 생성하면서, 함수의 주소와 인자를 thread의 생성자에 전달하면 된다. reference 타입은 ref()를 사용.
	
	// 객체의 멤버 함수
	Class c_1();
	thread th3(&Class::MemberFunc);

	// 람다식(캡쳐 등등은 어떻게 동작하는가?)
	thread th4([](int a, int b) {cout << a + b << endl; }, 1, 2);

	thread th5(bind(&Function3, 1, 2) );

	if (th2.joinable()) { th2.join(); }
	if (th3.joinable()) { th3.join(); }
	if (th4.joinable()) { th4.join(); }
	if (th5.joinable()) { th5.join(); }
}