#include <iostream>
#include "GeometricObject.h"
#include <vector>

using namespace std;



int main(void)
{

	vector <GeometricObject*> object_list;


	object_list.push_back(GeometricObject::getGeometricObject("Box"));
	object_list.push_back(GeometricObject::getGeometricObject("Circle"));

	//for (int i = 0; i < object_list.size(); i++)
	//	object_list[i]->Draw();


	//for (vector<geometricobject*>::iterator itr = object_list.begin();
	//	itr != object_list.end(); itr++)
	//	(*itr)->draw();


	for (auto itr : object_list)
		itr->Draw();

	for (auto itr : object_list)
		delete itr;

	
	return 0;

}