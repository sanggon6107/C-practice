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
	promise<int> p; // int�� �޴´ٴ� ��� ��ü.
	future<int> f = p.get_future(); // �̷��� �߻��� ���ϰ��� f�� �����Ѵ�.

	thread th1(&Plus, 1, 2, ref(p)); // p�� ���� �Ǵ� �����ͷ� �޾ƾ� �Ѵ�.

	cout << f.get() << endl; // �� �ٿ��� "p�� ���� ��������, �� set_value�� �� �� ����" ��ٸ���.

	cout << "between f.get() and th1.join()" << endl;

	th1.join();

	cout << "join() called" << endl;
}