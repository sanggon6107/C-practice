#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
// thread의 동기화 : mutex의 lock, unlock을 날 것으로 쓰지 말고, lock_guard<mutex>를 쓰자.

int global_value = 0;
mutex m; // m.lock(), m.unlock() 을 통해 다른 스레드가 들어오지 못하게 한다.



void Func1()
{
	m.lock();
	global_value = 1; // 한 스레드가 도중에 예외가 나게 되면, unlock()하지 못한 채 나가게 되어 데드락 발생.
	global_value += 1;
	m.unlock();
}

void Func2()
{
	lock_guard<mutex> lg(m); // 객체의 생성자에서 lock(), destructor에서 unlock() 해준다. RAII의 대표적인 예. 아래 도중에
							// 예외가 발생하더라도 catch로 가게 되면서 소멸자가 호출되므로 다른 스레드가 Func2에 진입할 수 있다.
	global_value = 1;
	global_value += 1;
}



int main()
{
	thread th1(&Func1);
	thread th2(&Func1);

	th1.join();
	th2.join();

	thread th3(&Func2);
	thread th4(&Func2);
	
	th3.join();
	th4.join();

	cout << "done" << endl;
}
