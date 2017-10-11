#include <iostream>

using namespace std;

class Animal
{
public:
	virtual void speak() = 0;
	//나는 이 포인터 위치에 speak가 들어올꺼야앙
	//이자리에서 찾으면 된다 @@@ 라고하는거임
};
class Dog:public Animal
{
public:
	void speak()
	{
		cout << "Bow" << endl;
	}

};
class Elephant :public Animal
{
public:
	void speak()
	{
		cout << "Mooo" << endl;
	}
};
class Human :public Animal
{
public:
	void speak()
	{
		cout << "da" << endl;

	}
};
int main()
{
	Animal *my_dog = new Dog;
	Animal *my_ele = new Elephant;
	Animal *my_human = new Human;

	Animal **animal_arr = new Animal*[3];
	//Animal의 포인터의 arr

	//어떤 클래스의 주소를 받을껀지 명시해야함
	//같은 이름의 함수라도 어디있는지 클래스마다 다를수있기때문에,
	//클래스 시작점 대비 얘의 주소가 일정하면 됨 (상대주소로? )
	animal_arr[0] = new Dog;
	animal_arr[1] = new Elephant;
	animal_arr[2] = new Human;

	for (int i = 0; i < 3; i++)
		animal_arr[i]->speak();


	return 0;
}