#include <iostream>
#include <cmath>


class Linear
{
public:
	float a = 0, b = 0;

	float getY(const float& x)
	{
		return a*x + b;
	}
};
void li()
{
	const int num_data = 5;
	const float x_input[] = { 1,2,3,4,5 };
	const float y_target[] = { 1,2,3,2,1 };

	float de_da_sum = 0;
	float de_db_sum = 0;
	float sqr_error_sum = 0;
	Linear li;

	const float lr = 0.01;

	for (int itr = 0; itr < 100000; ++itr) {
		for (int d = 0; d < num_data; d++)
		{
			const float x = x_input[d];
			const float y = y_target[d];

			const float error = y - li.getY(x);
			const float sqr_error = error*error*0.5;

			const float de_da = -error *x;
			const float de_db = -error * 1;

			de_da_sum += de_da;
			de_db_sum += de_db;

			sqr_error_sum += sqr_error;
		}
		li.a -= lr*de_da_sum;
		li.b -= lr*de_db_sum;
	//	if (itr % 100 == 0)std::cout << sqr_error_sum << std::endl;

	}
	std::cout << li.a << " " << li.b << std::endl;

	for (int d = 0; d < num_data; d++)
	{
		std::cout << li.a*x_input[d] + li.b << std::endl;
	}
}




class Quadratic
{
public:
	float a = 0, b = 0, c = 0;

	float getY(const float& x)
	{
		return a*x*x + b*x + c;
	}
};
void qua()
{
	const int num_data = 5;
	const float x_input[] = { 1,2,3,4,5 };
	const float y_target[] = { 1,2,3,2,1 };

	float de_da_sum = 0;
	float de_db_sum = 0;
	float de_dc_sum = 0;
	float sqr_error_sum = 0;
	Quadratic qua;

	const float lr = 0.001;

	for (int itr = 0; itr < 10000; ++itr) {
		for (int d = 0; d < num_data; d++)
		{
			const float x = x_input[d];
			const float y = y_target[d];

			const float error = y - qua.getY(x);
			const float sqr_error = error*error*0.5;

			const float de_da = -error *x*x;
			const float de_db = -error *x;
			const float de_dc = -error * 1;

			
			de_da_sum += de_da;
			de_db_sum += de_db;
			de_dc_sum += de_dc;

			sqr_error_sum += sqr_error;
			//std::cout << error<< std::endl;
		}
		qua.a -= lr*de_da_sum;
		qua.b -= lr*de_db_sum;
		qua.c -= lr*de_dc_sum;
	

	}
	std::cout << qua.a << " " << qua.b << " "<<qua.c<<std::endl;

	for (int d = 0; d < num_data; d++)
	{
		std::cout << qua.a*x_input[d] + qua.b << std::endl;
	}
}


class Logistic
{
public:
	float a = 0.0, b = 0.0;

	float getY(const float& x)
	{
		const float t = a*x + b;

		return 1.0 / (1.0 + exp(-t));

		//return a * x + b;
	}
	float getResult(const float& x)
	{
		return a*x + b;
	}

};

void lo()
{
	const int num_data = 5;
	const float x_input[] = { -2,-1,0,1,2 };
	const float y_target[] = { 0,0,0.5,1,1 };

	float de_da_sum = 0;
	float de_db_sum = 0;
	
	float sqr_error_sum = 0;
	Logistic lo;


	const float lr = 0.001;

	for (int itr = 0; itr < 100; ++itr) {
		for (int d = 0; d < num_data; d++)
		{
			const float x = x_input[d];
			const float y = y_target[d];

			const float error = y - lo.getY(x);
			const float sqr_error = error*error*0.5;

			const float de_da = -error *x*lo.getY(x)*(1-lo.getY(x));
			const float de_db = -error *1.0*lo.getY(x)*(1 - lo.getY(x));
			


			de_da_sum += de_da;
			de_db_sum += de_db;
			

			sqr_error_sum += sqr_error;
			//std::cout << error<< std::endl;
		}
		lo.a -= lr*de_da_sum;
		lo.b -= lr*de_db_sum;
		


	}
	std::cout << lo.a << " " << lo.b << std::endl;

	for (int d = 0; d < num_data; d++)
	{
		std::cout << lo.getY(x_input[d]) << std::endl;
	}
}



int main()
{
	li();
	qua();
	lo();
}