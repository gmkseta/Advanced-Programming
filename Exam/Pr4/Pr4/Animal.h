#pragma once
#include<iostream>
#include <string>
using namespace std;

class Animal
{
public:
	virtual void speak()=0 ;
	//���� �� ������ ��ġ�� speak�� ���ò��߾�
	//���ڸ����� ã���� �ȴ� @@@ ����ϴ°���
	static Animal* Animal::divide(string name);


};
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "Bow" << endl;
//	}
//
//};
//class Duck :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "Mooo" << endl;
//	}
//};