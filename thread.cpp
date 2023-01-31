#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void function()
{
	cout << "function" << endl;
	this_thread::sleep_for(5s);
}

void function_2(int& a, int b)
{
	a = 30;
}

int main()
{
	thread th1(&function);

	// 아래의 둘 중 하나의 함수는 호출해야 에러 뜨지 않음.
	th1.join(); // 이 줄에서 th1이 끝날 때 까지 대기
	//th1.detach(); // th1이 어떻게 돌든 놔두고 메인 스레드 진행. 다만, main()함수가 끝나면 프로세스가 끝나므로 function()도 중간에 끊길 수 있다.

	int arg_1 = 1;
	int arg_2 = 2;
	thread th2(&function_2, ref(arg_1), arg_2); // 스레드 실행법 1 : thread의 객체를 생성하면서, 함수의 주소와 인자를 thread의 생성자에 전달하면 된다. reference 타입은 ref()를 사용.



	th2.join();
	
}