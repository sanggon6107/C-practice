#include <future>
#include <string>
#include <thread>
#include <iostream>
using namespace std;

// async : thread, promise, future를 쓰는 과정을 좀더 편하게 구현할 수 있다.
//		   따라서 리턴 값이 있는 함수를 스레드로 수월하게 돌릴 수 있다.
// thread 객체는 low level의 api임에 비해, async 함수는 high level api이다.

int Func1(int a, int b)
{
	cout << "Func1. thread id : " << this_thread::get_id() << endl;
	return a + b;
}

int Func2(int c, int d)
{
	cout << "Func2. thread id : " << this_thread::get_id() << endl;
	return c - d;
}

int main()
{
	int arg1 = 1;
	int arg2 = 2;
	future<int> f_1 = async(launch::async, [](int a, int b)
		{
			this_thread::sleep_for(3s);
			return a + b;
		}, arg1, arg2);

	future<int> f_2 = async(launch::deferred, &Func1, 1, 2); // 지연된 실행. get()을 호출할 때 이 스레드를 실행


	future<int> f_3 = async(launch::async | launch::deferred, &Func2, 1, 2); // 스레드 바로 실행. 하지만 멀티스레딩 지원되지 않는 시스템에서는 지연된 실행으로 get()에서 실행.
	
	// async(launch::async | launch::deferred, &Func2, 1, 2); // 만약 future객체로 받지 않는다면, async가 리턴하는 것은 임시 객체이므로 문장의 끝(';')에서 get()이될 때 까지 대기. 즉, 시퀀셜 하게 진행된다.

	cout << f_3.get() << endl;

	cout << f_2.get() << endl; // 이 줄에서 스레드 생성, Func1 호출.

	cout << f_1.get() << endl; // 여기서 대기.
	// f.get() 하지 않더라도, future 객체의 소멸자가 get() 불러주는 효과. 따라서, async 속의 함수가 끝날 때까지 기다려준다.
} 