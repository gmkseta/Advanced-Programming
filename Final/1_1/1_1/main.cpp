#include <iostream>
#include <iomanip>
using namespace std;
template <class T>
class VectorND
{
public:
	T* value;
	int size;

	VectorND(int n) :size(n)
	{
		value = new T[size];
		for (int i = 0; i < size; i++)
			value[i] = T();
	}
	VectorND() {}
	void init(int n)
	{
		size = n;
		value = new T[size];
		for (int i = 0; i < size; i++)
			value[i] = T();
	}

	void assignValue(int x, T v)
	{
		value[x] = v;
	}
	T getValue(int x)
	{
		return value[x];
	}

};

template<class T>
class MatrixMN
{
public:
	VectorND<T>* value;
	int x_l, y_l;
	MatrixMN(int x_length, int y_length) :x_l(x_length), y_l(y_length)
	{
		value = new VectorND<T>[y_l];

		for (int i = 0; i < y_l; i++)
		{
			value[i].init(x_l);
		}
	}

	void assignValue(int x, int y, T v)
	{
		value[y].assignValue(x, v);
	}
	T getValue(int x, int y)
	{
		return value[y].getValue(x);
	}

	VectorND<T> operator*(VectorND<T> vec)
	{
		//x*y행렬 곱하기 y*1 은 x*1로 나오는 vec임 .
		VectorND<T> ret_vec(x_l);

		for (int x = 0; x < x_l; x++)
		{
			T sum = T();
			for (int y = 0; y < y_l; y++)
				sum += vec.getValue(y)*value[y].getValue(x);
			ret_vec.assignValue(x, sum);
		}
		return ret_vec;

	}
};

template<class T>
ostream& operator<<(ostream& strm, VectorND<T> vec)
{
	for (int i = 0; i < vec.size; i++)
	{
		strm << setw(10) << vec.getValue(i);
	}
	strm << endl;
	return strm;
}

template<class T>
ostream& operator<<(ostream& strm, MatrixMN<T> mat)
{
	for (int i = 0; i < mat.y_l; i++)
	{
		strm << mat.value[i];
	}
	strm << endl;
	return strm;
}

int main()
{
	VectorND<float> my_vec(10);
	MatrixMN<float> my_mat(15, 10);
	for (int i = 0; i < 10; i++)
	{
		my_vec.assignValue(i, i*0.14f);
		for (int j = 0; j < 15; j++)
			my_mat.assignValue(j, i, i*0.4f + j*0.5f);
	}



	cout << my_mat << endl;
	cout << "X" << endl;
	cout << my_vec << endl;
	cout << "=" << endl;
	cout << my_mat*my_vec << endl;
	return 0;
}