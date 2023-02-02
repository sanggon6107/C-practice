#include <iostream>
#include <thread>
#include <future>

using namespace std;


void Plus(int a, int b, promise<int>& p)
{
	cout << "a : " << a << ", b : " << b << endl;
	p.set_value(a + b);
	this_thread::sleep_for(10s);
	cout << "Plus end" << endl;
}


int main()
{
	promise<int> p; // int를 받는다는 약속 객체.
	future<int> f = p.get_future(); // 미래에 발생할 리턴값을 f가 보관한다.

	thread th1(&Plus, 1, 2, ref(p)); // p는 참조 또는 포인터로 받아야 한다.

	cout << f.get() << endl; // 이 줄에서 "p에 값이 들어갈때까지, 즉 set_value가 될 때 까지" 기다린다.

	cout << "between f.get() and th1.join()" << endl;

	th1.join();

	cout << "join() called" << endl;
}