#include <iostream>


int main()
{
	using namespace std;

	
	while (1)
	{
		char input_char;

		cin >> input_char;

		if (input_char == 'a')
			cout << "Move left" << endl;
		else if (input_char == 'd')
			cout << "Move right" << endl;
		//you defined 20 input key-commands combinations
		//만약 누가 이 키를 바꾸라고 하면 a,d 부분을 바꾸는데..
		//내가 이 코드를 수정하는게 아닌 script 를 줘서 하는거 
		// move_left a 
		// move_right d
		// 우리가 만든 기능을 사람이 사용한다는걸 생각해야함
	}
	return 0;

}













