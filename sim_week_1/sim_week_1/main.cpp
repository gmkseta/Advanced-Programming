//first main function 
#include <stdio.h>
#include <iostream>

namespace Vector2D {
	int x;
	int y;

	void print()
	{
		printf("%d %d", x, y);
	}
}


void main()
{
	Vector2D::x = 1;
	Vector2D::y = 2;
	//Vector2D::print();
	/*printf("THis is c Style\n");
	std::cout << "This is c++ style"<<std::endl;
*/
	using namespace std;
	using namespace Vector2D;

	cout << x << " , " << y << endl;

}