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
	template <class T_TYPE>//이 ttype에 뭐가 들어갈지 모르니까 디버깅 하기가 힘듬??
	void doSomething(const T_TYPE& v)//직접 넣어서 돌려봐야하니까.
	{
		v.doSomething();

	}
};



template <class T_TYPE>
class Vector2
{
public:
	T_TYPE x, y;

	static float z;//얘는 인스턴스 여러개 마들어도 하나만사용댐ㅇㅇ이거하나러
	//같은 메모리를 씀 .. ! (그래서 static이래)
	//static은 가급적 로컬로 쓰지마셈 (멀티 스레드를 고려한다면 .??)
	//(두개 이상의스레드가 얘를 동시에 건드림 그니까 이게 몇번 인스턴스만들어졌는지 보려고 우리가 static 으로 선언을 하더라도
	//우리맘대로안댄다는데 뭐꼬인다는데 무슨말인지는 잘모르겠지만 언젠가는 알게될 날이오겠지
	//무튼 static은 기본적으로 밖으로 뺴셈 존나 잘하기전에

	//const 컴파일러가 바꾸는걸 막아줌
	//다른 혹은 내가 이걸 바꾸는걸 제어해주
	
	//함수의 declar 뒤에서 const 를 넣으면.. int get() const {return x;}

	//		const int& get(){return x;} 이러면 복사를 안하고 이케이케하나봄 뭐 아낀다고? 단 주의할점은 x가 함수의 지역변수라면 나오는순간 저거 메모리 날아가니까 reference 음 ㅇㅇ.?


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
	
	//대입 오퍼레이터 만들어보라고??

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