#include <future>
#include <string>
#include <thread>
#include <iostream>
using namespace std;

// async : thread, promise, future를 쓰는 과정을 좀더 편하게 구현할 수 있다.
//		   따라서 리턴 값이 있는 함수를 스레드로 수월하게 돌릴 수 있다.
// thread 객체는 low level의 api임에 비해, async 함수는 high level api이다.

int main()
{
	int arg1 = 1;
	int arg2 = 2;
	future<int> f = async(launch::async, [](int a, int b)
		{
			this_thread::sleep_for(3s);
			return a + b;
		}, arg1, arg2);


	cout << f.get() << endl; // 여기서 대기.
} // f.get() 하지 않더라도, future 객체의 소멸자가 get() 불러주는 효과. 따라서, async 속의 함수가 끝날 때까지 기다려준다.