#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

class Action
{
public:
	virtual void doSomething() = 0;
};

class MovingLeft :public Action
{
public:
	void doSomething() 
	{
		cout << "move left" << endl;
	}
};


void moveLeft()
{
	cout << "move left" << endl;
}
void moveRight()
{
	cout << "move right" << endl;
}

//factory pattern
Action* getAction(const string& actStr) {

	if (actStr == "Moving_left")
		return new MovingLeft;

}
int main()
{
	
	//let's assume that you read 'key_binding_script.txt'
	//move_left a
	//move_right b

	////////////////////////////////////////////////////////////
	//map<string, char> command_key_binding;


	//command_key_binding["move_left"] = 'a';//read script
	//command_key_binding["move_right"] = 'd';//read script


	//cout << command_key_binding["move_left"] << endl;
	//system("pause");
	/////////////////////////////////////////////////////////////
	map<char, void(*)()> key_command_binding;
	key_command_binding['a'] = &moveLeft;
	key_command_binding['d'] = &moveRight;

	map<char, std::function<void()>>key_command_bi;
	key_command_bi['a'] = [] {cout << "Move Left" << endl; };
	//여기서 함수를 씀??
	//위에그럼 다필요없음
	//재활용 안하는 코드는 람다로 그냥 꽂아버리는게 유행이래
	//요즘에 이렇게 짜기때문에
	//뭐 게임프로그래밍을 할때 space를 누르면 총알이 나간다 하면
	//if문으로 space 받았을때~ 이런식으로 하는걸 찾아가서 보는데
	//요즘은 이런식이라 저런게없음
	
	
	//만약 코드가 복잡해져서 굳이 객체지향을 써야한다면

	map<char, Action*> key_co;
	key_co['a'] = new MovingLeft;
	key_co['d'] = getAction("Moving_left");




	while (1)
	{
		char input_char;

		cin >> input_char;
		


		key_command_binding[input_char]();

		key_command_bi[input_char]();

		key_co[input_char]->doSomething();
		// ㄴ void (*func_ptr)() = key_command_binding[input_char];
		//	func_ptr(); 하고 같은거임.

		
	//	if (input_char == command_key_binding["move_left"])
	//		moveLeft();
	//	else if (input_char == command_key_binding["move_right"])
	//		moveRight();


		//map<string, char>::iterator itr; //(for int i; ...)

		//for (itr = command_key_binding.begin();//for (i = 0..;
		//	itr != command_key_binding.end();//for ( .. ;i<num
		//	itr++)
		//{
		//	cout << (*itr).first <<" "<<(*itr).second<< endl;
		//}

	//	for (auto itr : command_key_binding)
	//	{
	//		cout << itr.first << " " << itr.second << endl;

			//여기에 키 입력 if 문 넣을꺼니?
			//
//		}



		//if (input_char == 'a')
		//	cout << "Move left" << endl;
		//else if (input_char == 'd')
		//	cout << "Move right" << endl;

		//you defined 20 input key-commands combinations
//만약 누가 이 키를 바꾸라고 하면 a,d 부분을 바꾸는데..
		//내가 이 코드를 수정하는게 아닌 script 를 줘서 하는거 
		// move_left a 
		// move_right d
		// 우리가 만든 기능을 사람이 사용한다는걸 생각해야함
       //그래서 위와 같이 스크립트에서 읽어서 오는거로


//이번엔 또 기능을 추가하고싶다고 하면?
		//map으로 for문 돌리면됨
		
		//기능 넣는거도 





	}
	return 0;

}

//처음 설계할때 아예 패턴을 써서 추상화 시켜서 짜놓으면
//좋음
//연구를 하든 뭘하든
//초반에 하드코딩 하는데.ㅇㅅㅇ;
//
//
//
//
//
//ㅇㅅㅇ