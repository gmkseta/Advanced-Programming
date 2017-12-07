#include <iostream>
#include <ostream>
#include <string>
using namespace std;

string dec_to_bi(int num, const int& n)
{
	string rt_str;

	for (int i = n - 1; i >= 0; i--)
	{
		if (num % 2 == 1)
			rt_str.insert(0, "# ");
		else
			rt_str.insert(0, "  ");
		num /= 2;
	}

	return rt_str;
}

int* decoding(const int & n, int *arr1, int *arr2)
{
	int* result_int = new int(n);
	for (int i = 0; i < n; i++)
	{
		result_int[i] = arr1[i] | arr2[i];
	}
	return result_int;
}

string* arr_to_map(const int &n, int *arr)
{
	string* rt_str = new string[n];
	for (int i = 0; i < n; i++)
	{
		rt_str[i] = dec_to_bi(arr[i], n);
	}
	return rt_str;
}

ostream& operator<<(ostream& strm, string* str)
{
	for (int i = 0; i < str->size() / 2; i++)
	{
		strm << str[i] << endl;
	}

	return strm;
}

int main()
{
	const int n = 5;
	int f_ans_1[n] = { 9,20,28,18,11 };
	int f_ans_2[n] = { 30,1,21,17,28 };

	int* f_result = decoding(n, f_ans_1, f_ans_2);
	cout << "first_map" << endl;
	cout << arr_to_map(n, f_ans_1) << endl;
	cout << "second_map" << endl;
	cout << arr_to_map(n, f_ans_2) << endl;
	cout << "result_map" << endl;
	cout << arr_to_map(n, f_result) << endl;
	cout << "天天天天天天天天天天天" << endl;;

	const int n2 = 6;

	int s_ans_1[n2] = { 46,33,33,22,31,50 };
	int s_ans_2[n2] = { 27,56,19,14,14,10 };

	int* s_result = decoding(n2, s_ans_1, s_ans_2);
	cout << "first_map" << endl;
	cout << arr_to_map(n2, s_ans_1) << endl;
	cout << "second_map" << endl;
	cout << arr_to_map(n2, s_ans_2) << endl;
	cout << "result_map" << endl;
	cout << arr_to_map(n2, s_result) << endl;
	cout << "天天天天天天天天天天天" << endl;;


	return 0;
}