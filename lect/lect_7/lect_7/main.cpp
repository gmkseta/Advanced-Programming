#include <iostream>

using namespace std;

class Animal
{
public:
	virtual void speak() = 0;
	//���� �� ������ ��ġ�� speak�� ���ò��߾�
	//���ڸ����� ã���� �ȴ� @@@ ����ϴ°���
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
	//Animal�� �������� arr

	//� Ŭ������ �ּҸ� �������� ����ؾ���
	//���� �̸��� �Լ��� ����ִ��� Ŭ�������� �ٸ����ֱ⶧����,
	//Ŭ���� ������ ��� ���� �ּҰ� �����ϸ� �� (����ּҷ�? )
	animal_arr[0] = new Dog;
	animal_arr[1] = new Elephant;
	animal_arr[2] = new Human;

	for (int i = 0; i < 3; i++)
		animal_arr[i]->speak();


	return 0;
}