#include <iostream>


template<class T>
class VectorND
{
public:
	T *vec;
	int n;
	VectorND(int _n):n(_n)
	{
		vec = new T[_n];
		for (int i = 0; i < n; i++)
			vec[i] = 0.0f;
	}
	VectorND() {}
	void init(int _n)
	{
		n = _n;
		vec = new T[_n];
		for (int i = 0; i < n; i++)
			vec[i] = 0.0f;
	}
	void assignValue(int x, float v)
	{
		vec[x] = v;
	}
	T getValue(int x)
	{
		return vec[x];
	}


	
};

template<class T>
std::ostream& operator<<(std::ostream& strm, const VectorND<T>& a)
{
	for (int i = 0; i < a.n; i++)
	{
		strm << a.vec[i] << ' ';
	}

	return strm;
}



template<class T>
class MatrixMN
{
public:
	VectorND<T> *vec;
	int x_length, y_length;//
	//행 열로 들오면
	MatrixMN(int x_l,int y_l):x_length(x_l),y_length(y_l)
	{
		vec = new VectorND<T>[y_length];
		for (int i = 0; i < y_length; i++)
			vec[i].init(x_length);
	}

	//
	void assgnValue(int x,int y, float v)
	{
		vec[y].assignValue(x, v);// = v;
	}
	T getValue(int x,int y)
	{
		return vec[y].getValue(x);
	}

	VectorND<T> operator*(const VectorND<T>& ve)
	{
		if (ve.n != y_length)
		{
			std::cout << "계산 할 수 없는 행렬의 크기 입니다" << std::endl;
		}
		else
		{
			VectorND<T>result(x_length);
			for (int x = 0; x < x_length; x++)
			{
				T sum = T();
				for (int y = 0; y < y_length; y++)
				{
					sum += ve.vec[y] * this->getValue(x,y);
				}
				result.assignValue(x, sum);
			}
			return result;
		}
	}

	
};

template <class T>
std::ostream& operator<<(std::ostream& strm,const MatrixMN<T>& a)
{
	for (int i = 0; i < a.y_length; i++)
	{
		strm << a.vec[i] << std::endl;
	}

	return strm;
}






int main(void)
{
	using namespace std;;
	VectorND<float> my_vec(10);
	my_vec.assignValue(3, 10.1f);
	cout << my_vec.getValue(3)<<endl;

	MatrixMN<float> my_mat(15, 10);
	my_mat.assgnValue(4, 5, 3.14f);
	cout << my_mat.getValue(4, 5) << endl;

	cout << "ㅡㅡㅡㅡMulㅡㅡㅡㅡ"<<endl;


	VectorND<float> mul_vec(20);
	MatrixMN<float> mul_mat(15, 20);

	for (int i = 0; i < 20; i++)
	{
		mul_vec.assignValue(i, 10.0f+(float)i*0.103f);
		for (int j = 0; j < 15; j++)
		{
			mul_mat.assgnValue(j, i,  (float)i*0.103f + (float)j*0.131f);
		}
	}

	cout << mul_vec << endl;

	cout << mul_mat << endl;

	VectorND<float> resu = mul_mat*mul_vec;

	cout << resu << endl;

	return 0;
}