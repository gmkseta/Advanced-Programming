#include <iostream>
#include <fstream>

using namespace std;

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
	
};

int main()
{
	const int num_data = 20;
	const float hours[] = { 0.50, 0.75, 1.00, 1.25, 1.50, 1.75, 1.75, 2.00, 2.25, 2.50, 2.75, 3.00, 3.25, 3.50,
		4.00, 4.25, 4.50, 4.75, 5.00, 5.50 };
	const float pass[] = { 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1 };

	Logistic lh;

	const float lr = 0.01 / (float)num_data;

	for (int itr = 0; itr < 50000; ++itr)
	{
		float de_da_sum = 0.0;
		float de_db_sum = 0.0;
		float sqr_error_sum = 0.0;

		for (int d = 0; d < num_data; ++d)
		{
			const float x = hours[d];
			const float y_target = pass[d];

			//const float error = y_target - lh.getY(x);
			//const float sqr_error = error * error * 0.5;
			//const float de_da = -error*lh.getY(x)*(1 - lh.getY(x))*x;
			//const float de_db = -error*lh.getY(x)*(1 - lh.getY(x));
			//de_da_sum += de_da;
			//de_db_sum += de_db;
			//sqr_error_sum += sqr_error;
			
			const float Ece = -y_target*log(lh.getY(x)) - (1.0 - y_target)*log(1.0 - lh.getY(x));
			const float dEce_dy = (lh.getY(x) - y_target) / (lh.getY(x)*(1 - lh.getY(x)));
			const float de_da = dEce_dy*lh.getY(x)*(1 - lh.getY(x))*x;
			const float de_db = dEce_dy*lh.getY(x)*(1 - lh.getY(x));

			de_da_sum += de_da;
			de_db_sum += de_db;
			sqr_error_sum += Ece;
			
		}

		lh.a -= lr * de_da_sum;
		lh.b -= lr * de_db_sum;

		if (itr % 100 == 0) cout << sqr_error_sum << endl;
	}

	cout << lh.a << " " << lh.b << endl;

	ofstream output_file("out.txt");

	for (int d = 0; d < num_data; ++d)
	{
		output_file << hours[d] << " , " << pass[d] << " , " << lh.getY(hours[d]) << endl;
	}

	output_file.close();

	return 0;
}
