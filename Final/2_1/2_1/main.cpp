#include <iostream>
#include <cmath>
class Linear
{
public:
	float a, b;

	Linear() :a(0), b(0)
	{
	}
	float getY(float x)
	{
		return a*x + b;

	}
};



void li()
{
	Linear li;



	const int data_num = 5;

	const float x_input[data_num] = { 1,2,3,4,5 };
	const float y_target[data_num] = { 1,2,3,2,1 };

	const float learning_rate = 0.001;


	for (int n = 0; n < 10000; n++) {
		float de_da_sum = 0.0f, de_db_sum = 0.0f, sqr_error_sum = 0.0f;

		for (int i = 0; i < data_num; i++)
		{
			const float x = x_input[i];
			const float y = y_target[i];


			const float error = y - li.getY(x);
			const float sqr_error = 0.5*error*error;

			const float de_da = -error*x;
			const float de_db = -error*1.0f;

			de_da_sum += de_da;
			de_db_sum += de_db;

			sqr_error_sum += sqr_error;
		}

		li.a -= learning_rate*de_da_sum;
		li.b -= learning_rate*de_db_sum;

		if (n % 1000 == 0)
			std::cout << sqr_error_sum << " ";
	}
	std::cout << std::endl;
	std::cout << li.a << " " << li.b << std::endl;
	for (int i = 0; i < data_num; i++)
		std::cout << li.getY(x_input[i]) << " " << std::endl;
	std::cout << std::endl;





}


class Quadratic
{
public:
	float a, b, c;

	Quadratic() :a(0), b(0), c(0)
	{
	}
	float getY(float x)
	{
		return a*x*x + b*x + c;

	}
};



void qu()
{
	Quadratic qu;



	const int data_num = 5;

	const float x_input[data_num] = { 1,2,3,4,5 };
	const float y_target[data_num] = { 1,2,3,2,1 };

	const float learning_rate = 0.001;


	for (int n = 0; n < 10000; n++) {
		float de_da_sum = 0.0f, de_db_sum = 0.0f, de_dc_sum = 0.0f, sqr_error_sum = 0.0f;

		for (int i = 0; i < data_num; i++)
		{
			const float x = x_input[i];
			const float y = y_target[i];


			const float error = y - qu.getY(x);
			const float sqr_error = 0.5*error*error;

			const float de_da = -error*x*x;
			const float de_db = -error*x;
			const float de_dc = -error*1.0f;

			de_da_sum += de_da;
			de_db_sum += de_db;
			de_dc_sum += de_dc;

			sqr_error_sum += sqr_error;
		}

		qu.a -= learning_rate*de_da_sum;
		qu.b -= learning_rate*de_db_sum;
		qu.c -= learning_rate*de_dc_sum;

		if (n % 1000 == 0)
			std::cout << sqr_error_sum << " ";
	}

	std::cout << std::endl;
	std::cout << qu.a << " " << qu.b << " " << qu.c << std::endl;
	for (int i = 0; i < data_num; i++)
		std::cout << qu.getY(x_input[i]) << " " << std::endl;
	std::cout << std::endl;





}



class Logistic
{
public:
	float a, b;

	Logistic() :a(0), b(0)
	{
	}
	float getY(float x)
	{
		const float t = a*x + b;
		return 1 / (1 + exp(-t));

	}
};



void lo()
{
	Logistic lo;



	const int data_num = 5;

	const float x_input[data_num] = { -2,-1,0,1,2 };
	const float y_target[data_num] = { 0,0,0.5,1,1 };

	const float learning_rate = 0.001;


	for (int n = 0; n < 100000; n++) {
		float de_da_sum = 0.0f, de_db_sum = 0.0f, sqr_error_sum = 0.0f;

		for (int i = 0; i < data_num; i++)
		{
			const float x = x_input[i];
			const float y = y_target[i];


			const float error = y - lo.getY(x);
			const float sqr_error = 0.5*error*error;

			const float de_da = error*x*lo.getY(x)*(1 - lo.getY(x));
			const float de_db = error*1.0f*lo.getY(x)*(1 - lo.getY(x));

			de_da_sum += de_da;
			de_db_sum += de_db;

			sqr_error_sum += sqr_error;
		}

		lo.a += learning_rate*de_da_sum;
		lo.b += learning_rate*de_db_sum;

		if (n % 10000 == 0)
			std::cout << sqr_error_sum << " ";
	}
	std::cout << std::endl;
	std::cout << lo.a << " " << lo.b << std::endl;
	for (int i = 0; i < data_num; i++)
		std::cout << lo.getY(x_input[i]) << " " << std::endl;
	std::cout << std::endl;





}



int main(void)
{
	li();
	qu();
	lo();
	return 0;
}