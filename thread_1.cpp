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

	// �Ʒ��� �� �� �ϳ��� �Լ��� ȣ���ؾ� ���� ���� ����.
	th1.join(); // �� �ٿ��� th1�� ���� �� ���� ���
	//th1.detach(); // th1�� ��� ���� ���ΰ� ���� ������ ����. �ٸ�, main()�Լ��� ������ ���μ����� �����Ƿ� function()�� �߰��� ���� �� �ִ�.

	int arg_1 = 1;
	int arg_2 = 2;
	thread th2(&Function2, ref(arg_1), arg_2); // ������ ����� 1 : thread�� ��ü�� �����ϸ鼭, �Լ��� �ּҿ� ���ڸ� thread�� �����ڿ� �����ϸ� �ȴ�. reference Ÿ���� ref()�� ���.
	
	// ��ü�� ��� �Լ�
	Class c_1();
	thread th3(&Class::MemberFunc);

	// ���ٽ�(ĸ�� ����� ��� �����ϴ°�?)
	thread th4([](int a, int b) {cout << a + b << endl; }, 1, 2);

	thread th5(bind(&Function3, 1, 2) );

	if (th2.joinable()) { th2.join(); }
	if (th3.joinable()) { th3.join(); }
	if (th4.joinable()) { th4.join(); }
	if (th5.joinable()) { th5.join(); }
}