//template
#include <iostream>


//template<class T_CLASS>
//
//void print(const T_CLASS& i)
//{
//	std::cout << i <<std::endl;
//}


class Test
{
public:
	void(Test::*callback_)(const int& a) = 0;

	//pure virtual function

	void exec()
	{
		if(callback_!=nullptr)
			(this->*callback_)(123);

	}
	void drawCircle(const int& a)
	{
		std::cout << "Circle" << std::endl;
	}
	void drawBox(const int& a)
	{
		std::cout << "Box" << std::endl;
	}


};
int main()
{
	Test my_circle;

	my_circle.callback_ = &Test::drawCircle;

	Test my_box;

	my_box.callback_ = &Test::drawBox;

	my_box.exec();


	return 0;

	

}