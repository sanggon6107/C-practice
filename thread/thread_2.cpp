#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
// thread�� ����ȭ : mutex�� lock, unlock�� �� ������ ���� ����, lock_guard<mutex>�� ����.

int global_value = 0;
mutex m; // m.lock(), m.unlock() �� ���� �ٸ� �����尡 ������ ���ϰ� �Ѵ�.



void Func1()
{
	m.lock();
	global_value = 1; // �� �����尡 ���߿� ���ܰ� ���� �Ǹ�, unlock()���� ���� ä ������ �Ǿ� ����� �߻�.
	global_value += 1;
	m.unlock();
}

void Func2()
{
	lock_guard<mutex> lg(m); // ��ü�� �����ڿ��� lock(), destructor���� unlock() ���ش�. RAII�� ��ǥ���� ��. �Ʒ� ���߿�
							// ���ܰ� �߻��ϴ��� catch�� ���� �Ǹ鼭 �Ҹ��ڰ� ȣ��ǹǷ� �ٸ� �����尡 Func2�� ������ �� �ִ�.
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
