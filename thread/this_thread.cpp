#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

int main()
{
	// std::this_thread namespace
	// ���� �� ���� ���� �ִ� thread�� ���� �װ��� ���� �Լ��� ����

	thread::id id = this_thread::get_id(); // thread�� id�� ����.

	cout << id << endl;

	this_thread::sleep_for(3s);  // ���� �� �����带 ���� �ð���ŭ �����带 ����.
	this_thread::sleep_until(5s + chrono::system_clock::now()); // ���� �� �����带 Ư�� ����(time_point)���� �����带 ����.

	this_thread::yield(); // �ٸ� ������ �����층. ��, ���� �������� ���� �ð��� �� �ִ��� �����ϰ� �ٸ� ������ ������ ���ش�.
}