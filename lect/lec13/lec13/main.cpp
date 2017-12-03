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
}//���ÿ� ������ �ϱ⶧���� ���÷��� ����ϴ°ŵ� 
//���ÿ� ����Ϸ��ؼ� Do something Do something 10 �̷������� �����°���
//�ٵ� �̰� ������  ���� ������ ��Ű���� �ϴ°Ŵϱ�!
//printf�� �ϸ� �̻ڰԴ� ����

void makeSum(const long long i_start, const long long i_end,long long *sum_return)
{
	long long sum = 0;
	for (long long i = i_start; i < i_end; ++i )
		sum += i;

	*sum_return = sum;
}


//���� �� �Լ��� �����
//�Լ��� �� �� ���������� �ϰ�
//���ε��� ������
//����� �ʿ��� ��쿡�� �������;�����

int main()
{
	cout << "Number Of Core" << thread::hardware_concurrency() << endl;; // so pc�� �����ִ� �ھ��

	const int num_thread = 10;


	vector <thread> th;
	th.resize(num_thread);
	vector <long long> sum_th;
	sum_th.resize(num_thread);


//	thread th[2];//���� ���� �ȿ� �ھ� ����?

	long long max = 100000000;

	long long max_per_thread = max/num_thread;
	for (int i = 0; i < th.size(); ++i)
	{//return �� �ޱ� ����� �����ͷ� �� 
		long long i_start=i*max_per_thread;
		long long i_end = (i + 1)*max_per_thread;

		th[i] = thread(&makeSum, i_start,i_end,sum_th[i]);
	}
	for (int i = 0; i < th.size(); ++i)
		th[i].join();

	

	//const auto start = chrono::system_clock::now();

	//th[0] = thread(&do_something,0);//�ڱⰡ �ϳ��� ���μ����ΰ� ó�� ���ư�. 

	//th[1] = thread(&do_something,1);//
	
	//�� �����尡? ���μ����� ���� �� �ϱ�����
	//���μ����� ���������ϱ� join�� �������� ��Ÿ�ӿ����� �����
	//�ڱⰡ ���ϰ��ִµ� �θ� �����ϱ� ..�� 
	//th[0].join();//�갡 ���������� ��ٷ��ִ°���
	//thread �� �ڱ� �� �� ���� �����ٰ� �ٽ� �շ��ϴ°Ŷ�� �����ϸ��
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
