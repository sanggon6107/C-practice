#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

int main()
{
	// std::this_thread namespace
	// 현재 이 줄이 돌고 있는 thread에 관한 네가지 전역 함수를 제공

	thread::id id = this_thread::get_id(); // thread의 id를 리턴.

	cout << id << endl;

	this_thread::sleep_for(3s);  // 현재 이 스레드를 인자 시간만큼 스레드를 재운다.
	this_thread::sleep_until(5s + chrono::system_clock::now()); // 현재 이 스레드를 특정 시점(time_point)까지 스레드를 재운다.

	this_thread::yield(); // 다른 스레드 스케쥴링. 즉, 현재 스레드의 남은 시간이 좀 있더라도 포기하고 다른 스레드 돌리게 해준다.
}