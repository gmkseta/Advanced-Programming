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
	Myclass my_class2(123);//defalut constructor ������� �ٵ� ����ó��
	//���� �־��ִ°ŷ� �ϳ�������ָ� defalut constructor�� �����
	//�׷��� ������ �����ٻ���.
	//�ȸ���� �Ѵپ�������

	return 0;
	//�̷��� �ٲ��ٰ� �ĺ�
}