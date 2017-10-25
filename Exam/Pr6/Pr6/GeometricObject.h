#pragma once
#include <iostream>

class GeometricObject
{
public:
	virtual void Draw() = 0;


	static GeometricObject* getGeometricObject(const std::string& name);
};
