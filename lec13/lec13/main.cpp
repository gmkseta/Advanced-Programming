#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <vector>
using namespace std;

//double do_something()
//{
//	double temp = 1.0;
//
//	for (int i = 0; i < 100000000; ++i)
//		temp += rand();
//
//	return temp;
//}

void do_something(const int num)
{
	cout << "Do Something " << num << endl;
}//동시에 실행을 하기때문에 디스플레이 출력하는거도 
//동시에 출력하려해서 Do something Do something 10 이런식으로 나오는거임
//근데 이게 정상임  원래 각자일 시키려고 하는거니까!
//printf로 하면 이쁘게는 나옴

void makeSum(const long long i_start, const long long i_end,long long *sum_return)
{
	long long sum = 0;
	for (long long i = i_start; i < i_end; ++i )
		sum += i;

	*sum_return = sum;
}


//일을 할 함수를 만들고
//함수가 일 할 범위설정을 하고
//따로따로 어저구
//결과를 필요할 경우에는 합쳐져ㅝ야하죠

int main()
{
	cout << "Number Of Core" << thread::hardware_concurrency() << endl;; // so pc가 갖고있는 코어갯수

	const int num_thread = 10;


	vector <thread> th;
	th.resize(num_thread);
	vector <long long> sum_th;
	sum_th.resize(num_thread);


//	thread th[2];//보통 여기 안에 코어 갯수?

	long long max = 100000000;

	long long max_per_thread = max/num_thread;
	for (int i = 0; i < th.size(); ++i)
	{//return 을 받기 힘드니 포인터로 함 
		long long i_start=i*max_per_thread;
		long long i_end = (i + 1)*max_per_thread;

		th[i] = thread(&makeSum, i_start,i_end,sum_th[i]);
	}
	for (int i = 0; i < th.size(); ++i)
		th[i].join();

	

	//const auto start = chrono::system_clock::now();

	//th[0] = thread(&do_something,0);//자기가 하나의 프로세스인거 처럼 돌아감. 

	//th[1] = thread(&do_something,1);//
	
	//이 스레드가? 프로세스가 일을 다 하기전에
	//프로세스가 꺼져버리니까 join을 안했을때 런타임에러가 뜬거임
	//자기가 일하고있는데 부모가 꺼지니까 ..음 
	//th[0].join();//얘가 끝나기전에 기다려주는거임
	//thread 가 자기 할 일 갖고 떠났다가 다시 합류하는거라고 생각하면댐
	//th[1].join();

	////const auto out = do_something();

	//long long sum = 0;
	//for (long long i = 0; i < 100000000; i++)
	//	sum += i;


	//const auto end = chrono::system_clock::now();

	////cout << out << endl;
	//cout << sum << endl;
	//const chrono::duration<double> elapsed_time = end - start;

	//const auto milisecond = chrono::duration_cast<chrono::milliseconds>(elapsed_time);

	//cout << "elapsed time: " << milisecond.count() << " ms\n";

	//return 0;
	return 0;


}
