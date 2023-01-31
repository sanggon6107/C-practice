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

	// �Ʒ��� �� �� �ϳ��� �Լ��� ȣ���ؾ� ���� ���� ����.
	th1.join(); // �� �ٿ��� th1�� ���� �� ���� ���
	//th1.detach(); // th1�� ��� ���� ���ΰ� ���� ������ ����. �ٸ�, main()�Լ��� ������ ���μ����� �����Ƿ� function()�� �߰��� ���� �� �ִ�.

	int arg_1 = 1;
	int arg_2 = 2;
	thread th2(&function_2, ref(arg_1), arg_2); // ������ ����� 1 : thread�� ��ü�� �����ϸ鼭, �Լ��� �ּҿ� ���ڸ� thread�� �����ڿ� �����ϸ� �ȴ�. reference Ÿ���� ref()�� ���.



	th2.join();
	
}