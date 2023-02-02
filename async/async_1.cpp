#include <future>
#include <string>
#include <thread>
#include <iostream>
using namespace std;

// async : thread, promise, future�� ���� ������ ���� ���ϰ� ������ �� �ִ�.
//		   ���� ���� ���� �ִ� �Լ��� ������� �����ϰ� ���� �� �ִ�.
// thread ��ü�� low level�� api�ӿ� ����, async �Լ��� high level api�̴�.

int main()
{
	int arg1 = 1;
	int arg2 = 2;
	future<int> f = async(launch::async, [](int a, int b)
		{
			this_thread::sleep_for(3s);
			return a + b;
		}, arg1, arg2);


	cout << f.get() << endl; // ���⼭ ���.
} // f.get() ���� �ʴ���, future ��ü�� �Ҹ��ڰ� get() �ҷ��ִ� ȿ��. ����, async ���� �Լ��� ���� ������ ��ٷ��ش�.