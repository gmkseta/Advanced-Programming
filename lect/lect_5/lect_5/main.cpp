#include <iostream>

class Myclass
{
public:
	int a;
	int *my_ptr = nullptr;

	Myclass(const int& _a)
		:a(_a)
	{
		std::cout << __FUNCTION__ << std::endl;

	}

	~Myclass()
	{
		
	}

};

int main(void)
{
	//Myclass my_class;
	Myclass my_class2(123);//defalut constructor 만들어줘 근데 위에처럼
	//값을 넣어주는거로 하나만들어주면 defalut constructor가 사라짐
	//그래서 위에꺼 빨간줄생김.
	//안만들면 둘다쓸수있음

	return 0;
	//이렇ㄱ 바껏다고 쳐봐
}