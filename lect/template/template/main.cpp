#include <iostream>




class Geo
{
public:
	
};
class Box
{
public:
	void doSomething() const
	{
		std::cout << "imebox" << std::endl;
	}
};


class Circle
{
public:
	void doSomething() const
	{
		std::cout << "im Circle" << std::endl;
	}
};

class Worker
{
public:
	template <class T_TYPE>//�� ttype�� ���� ���� �𸣴ϱ� ����� �ϱⰡ ����??
	void doSomething(const T_TYPE& v)//���� �־ ���������ϴϱ�.
	{
		v.doSomething();

	}
};



template <class T_TYPE>
class Vector2
{
public:
	T_TYPE x, y;

	static float z;//��� �ν��Ͻ� ������ ���� �ϳ������路���̰��ϳ���
	//���� �޸𸮸� �� .. ! (�׷��� static�̷�)
	//static�� ������ ���÷� �������� (��Ƽ �����带 ����Ѵٸ� .??)
	//(�ΰ� �̻��ǽ����尡 �긦 ���ÿ� �ǵ帲 �״ϱ� �̰� ��� �ν��Ͻ������������ ������ �츮�� static ���� ������ �ϴ���
	//�츮����ξȴ�ٴµ� �����δٴµ� ������������ �߸𸣰����� �������� �˰Ե� ���̿�����
	//��ư static�� �⺻������ ������ ���� ���� ���ϱ�����

	//const �����Ϸ��� �ٲٴ°� ������
	//�ٸ� Ȥ�� ���� �̰� �ٲٴ°� ��������
	
	//�Լ��� declar �ڿ��� const �� ������.. int get() const {return x;}

	//		const int& get(){return x;} �̷��� ���縦 ���ϰ� ���������ϳ��� �� �Ƴ��ٰ�? �� ���������� x�� �Լ��� ����������� �����¼��� ���� �޸� ���ư��ϱ� reference �� ����.?


	//		const int& get() const{return x;}
	
	Vector2 operator + (const Vector2& param)
	{
		Vector2 temp;
		temp.x = x + param.x;
		temp.y = y + param.y;
		return temp;
	}
	Vector2 operator + (const float& param)
	{
		Vector2 temp;
		temp.x = x + param;
		temp.y = y + param;
		return temp;
	}
	
	//���� ���۷����� �������??

	void print() {
		std::cout << x << "," << y << std::endl;
	}

	void assign(const T_TYPE& v) {
		x = v;
		y = v;

	}
};





int main(void)
{

	Box my_box;
	Circle my_circle;

	Worker my_worker;
	my_worker.doSomething<Circle>(my_circle);





/*
	vector2<float> a = { 1.0,2.0 };
	vector2<float> b = { 3.0,5.0 };
	vector2<float> c = a + b;
	vector2<float> d = a + 2.0f;

	c.z = 1.0;

	vector2<float>::z = 3.0;

	c.print();
	d.print();


	vector2<int> inv;
	inv.x = 1;
	vector2<vector2<float>> ven;
*/



	return 0;


}