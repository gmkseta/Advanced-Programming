#include <iostream>
#include <vector>
#include <thread>
#include <ctime>
#include <chrono>
using namespace std;

void doSomething(const long long start,const long long end,long long* sum_ret)
{
	long long sum = 0;
	for (long long i = start; i <= end; ++i)
		sum += i;

	*sum_ret = sum;

}

int main()
{
	
	
	const long long max = 1000000000;


	{
		const int num_thread = 10;
		long long per_thread = max / num_thread;

		vector<thread> th;
		vector<long long> th_sum;
		th.resize(num_thread);
		th_sum.resize(num_thread);
		const auto start = chrono::system_clock::now();

		for (int i = 0; i < th.size(); ++i)
			th[i] = thread(&doSomething, 1 + i*per_thread, (i + 1)*per_thread, &th_sum[i]);

		for (int i = 0; i < th.size(); ++i)
			th[i].join();

		long long sum_all = 0;
		for (int i = 0; i < th.size(); ++i)
		{
			sum_all += th_sum[i];
		}


		const auto end = chrono::system_clock::now();

		const chrono::duration<double> elasped_time = end - start;
		const auto milisecond = chrono::duration_cast<chrono::milliseconds>(elasped_time);

		cout << "elapsed time: " << milisecond.count() << "ms\n";
		cout << sum_all << endl;
		
	}
	
	

	return 0;

}
