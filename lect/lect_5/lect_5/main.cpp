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

//���
class Object
{
public:
	void draw() {}
	void rotate() {}
	void del() {}
	void move() {}
};


class Circle : public Object
{
public:
};
class Square : public Object
{
public:
};
class Line : public Object
{
};

int main(void)
{
	Line line;
	line.move();
	line.del();
	


	//Myclass my_class;
	Myclass my_class2(123);//defalut constructor ������� �ٵ� ����ó��
	//���� �־��ִ°ŷ� �ϳ�������ָ� defalut constructor�� �����
	//�׷��� ������ �����ٻ���.
	//�ȸ���� �Ѵپ�������

	return 0;
	//�̷��� �ٲ��ٰ� �ĺ�
}