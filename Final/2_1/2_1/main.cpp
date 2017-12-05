#include <iostream>



class Linear 
{
public:
	float a = 0, b = 0;

	float getY(const int& x)
	{
		return a*x + b;
	}
};
int main()
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
		if (itr % 100 == 0)std::cout << sqr_error_sum << std::endl;

	}
	std::cout << li.a << " " << li.b << std::endl;

	for (int d = 0; d < num_data; d++)
	{
		std::cout << li.a*x_input[d] + li.b << std::endl;
	}
	

}