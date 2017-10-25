#include "GeometricObject.h"

#include "Box.h"
#include "Circle.h"

GeometricObject* GeometricObject::getGeometricObject(const std::string& name)
{
	if (name == "Box")
		return new Box;
	else if (name == "Circle")
		return new Circle;
	else
		return nullptr;

}