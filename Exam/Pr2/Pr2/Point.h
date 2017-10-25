#ifndef __POINT_H_
#define __POINT_H_

class Point
{
private:
	int x;
	int y;
public:
	Point(const int &xpos, const int &ypos);
	int GetX() const;
	int GetY() const;
	bool setX(int xpos);
	bool setY(int ypos);
};
#endif // !__POINT_H_
