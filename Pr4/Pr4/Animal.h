#pragma once
#include<iostream>
#include <string>
using namespace std;

class Animal
{
public:
	virtual void speak()=0 ;
	//나는 이 포인터 위치에 speak가 들어올꺼야앙
	//이자리에서 찾으면 된다 @@@ 라고하는거임
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