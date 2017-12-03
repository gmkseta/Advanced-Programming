#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <cmath>
// 1 -> 1, 2->2 , 

struct MyData
{
	float size, price;

};

class LinearHypothesis//linear regression
{
public:
	//y=ax+b;
	float a, b;

	LinearHypothesis()
	{
		a = 0.0;
		b = 0.0;
	}
	float getY(const float& x)
	{
		return a*x + b;

	}
};


int main()
{
	using namespace std;

	ifstream fin("size_price_examples.txt",ios::in);

	vector<MyData> size_price_data;
	size_price_data.reserve(1000);

	//vector<tuple<float, float>>size_price_data;
	//get<0>(size_price_data[0]);





	float size, price;


	while (!fin.eof())
	{
	
		MyData read_data;
		fin >> read_data.size >> read_data.price;

		size_price_data.push_back(read_data);
	}

	for (const auto& itr : size_price_data)
	{
//cout << itr.size << " " << itr.price << endl;
	}


	LinearHypothesis my_hypothesis;
	
	//e = yt-yc = yt-(ax+b)
	//-(ax+b)를 ? -> de/da = -x  , de/db = -1
	//미분음 위아래 저거 어케대는거였지 뭘 뭐로 미분?
	//e = yt-y,               de/da , de/db
	//de/da = de/dy * dy/da chain rule?
	//= -1 * d(ax+b)/da = -x
	// de/db = -1 * d(ax+b)/db = -1
	// neurons network 는 입력이 여러개인 것들에 대해 잘어쩌구?

	for (int i = 0; i < 10; i++) {
		for (const auto& itr : size_price_data)
		{
			const float size_from_data = itr.size;
			const float price_from_hypo = my_hypothesis.getY(itr.size);

			const float error = sqrt((itr.price - price_from_hypo)*(itr.price - price_from_hypo));
			const float de_da = size_from_data*size_from_data+2* size_from_data-2* size_from_data*itr.price;
			const float de_db = 1.0f;
			
			const float learnig_rate = 0.000001f;

			my_hypothesis.a = my_hypothesis.a - de_da*learnig_rate;

			my_hypothesis.b = my_hypothesis.b - de_db*learnig_rate;

			const float error_after = sqrt((itr.price - my_hypothesis.getY(itr.size))*(itr.price - my_hypothesis.getY(itr.size)));

			{
				cout << error << "=>" << error_after << endl;
				cout << itr.price << " " << price_from_hypo << endl;
			}


		}
	}
	


	return 0;
}