#include <future>
#include <string>
#include <thread>
#include <iostream>
using namespace std;

// async : thread, promise, future�� ���� ������ ���� ���ϰ� ������ �� �ִ�.
//		   ���� ���� ���� �ִ� �Լ��� ������� �����ϰ� ���� �� �ִ�.
// thread ��ü�� low level�� api�ӿ� ����, async �Լ��� high level api�̴�.

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

	future<int> f_2 = async(launch::deferred, &Func1, 1, 2); // ������ ����. get()�� ȣ���� �� �� �����带 ����


	future<int> f_3 = async(launch::async | launch::deferred, &Func2, 1, 2); // ������ �ٷ� ����. ������ ��Ƽ������ �������� �ʴ� �ý��ۿ����� ������ �������� get()���� ����.
	
	// async(launch::async | launch::deferred, &Func2, 1, 2); // ���� future��ü�� ���� �ʴ´ٸ�, async�� �����ϴ� ���� �ӽ� ��ü�̹Ƿ� ������ ��(';')���� get()�̵� �� ���� ���. ��, ������ �ϰ� ����ȴ�.

	cout << f_3.get() << endl;

	cout << f_2.get() << endl; // �� �ٿ��� ������ ����, Func1 ȣ��.

	cout << f_1.get() << endl; // ���⼭ ���.
	// f.get() ���� �ʴ���, future ��ü�� �Ҹ��ڰ� get() �ҷ��ִ� ȿ��. ����, async ���� �Լ��� ���� ������ ��ٷ��ش�.
} 