#include <iostream>


template<class T>
class VectorND
{
public:
	int size;
	T *value;

	VectorND(int _n):size(_n)
	{
		value = new T[_n];
		for (int i = 0; i < size; i++)
			value[i] = T();
	}
	VectorND() {}
	void init(int _n)
	{
		size = _n;
		value = new T[_n];
		for (int i = 0; i < size; i++)
			value[i] = T();
	}
	void assignValue(int x, T v)
	{
		value[x] = v;
	}
	T getValue(int x) const
	{
		return value[x];
	}	
};

template<class T>
std::ostream& operator<<(std::ostream& strm, const VectorND<T>& vec)
{
	for (int i = 0; i < vec.size; i++)
	{
		strm << vec.getValue(i) << ' ';
	}
	return strm;
}

template<class T>
class MatrixMN
{
public:
	VectorND<T> *value;
	int x_length, y_length;//
	//행 열로 들오면
	MatrixMN(int x_l,int y_l):x_length(x_l),y_length(y_l)
	{
		value = new VectorND<T>[y_length];
		for (int i = 0; i < y_length; i++)
			value[i].init(x_length);
	}

	//
	void assgnValue(int x,int y, float v)
	{
		value[y].assignValue(x, v);// = v;
	}
	T getValue(int x,int y) const
	{
		return value[y].getValue(x);
	}

	VectorND<T> operator*(const VectorND<T>& ve)
	{
		if (ve.size != y_length)
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
					sum += ve.value[y] * this->getValue(x,y);
				}
				result.assignValue(x, sum);
			}
			return result;
		}
	}

	
};


template <class T>
std::ostream& operator<<(std::ostream& strm,const MatrixMN<T>& mat)
{
	for (int i = 0; i < mat.y_length; i++)
	{
		strm <<mat.value[i]<< std::endl;
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

	cout << my_vec << endl;
	cout << my_mat << endl;

	return 0;
}