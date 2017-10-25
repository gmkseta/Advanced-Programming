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
	//���⼭ �Լ��� ��??
	//�����׷� ���ʿ����
	//��Ȱ�� ���ϴ� �ڵ�� ���ٷ� �׳� �Ⱦƹ����°� �����̷�
	//���� �̷��� ¥�⶧����
	//�� �������α׷����� �Ҷ� space�� ������ �Ѿ��� ������ �ϸ�
	//if������ space �޾�����~ �̷������� �ϴ°� ã�ư��� ���µ�
	//������ �̷����̶� �����Ծ���
	
	
	//���� �ڵ尡 ���������� ���� ��ü������ ����Ѵٸ�

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
		// �� void (*func_ptr)() = key_command_binding[input_char];
		//	func_ptr(); �ϰ� ��������.

		
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

			//���⿡ Ű �Է� if �� ��������?
			//
//		}



		//if (input_char == 'a')
		//	cout << "Move left" << endl;
		//else if (input_char == 'd')
		//	cout << "Move right" << endl;

		//you defined 20 input key-commands combinations
//���� ���� �� Ű�� �ٲٶ�� �ϸ� a,d �κ��� �ٲٴµ�..
		//���� �� �ڵ带 �����ϴ°� �ƴ� script �� �༭ �ϴ°� 
		// move_left a 
		// move_right d
		// �츮�� ���� ����� ����� ����Ѵٴ°� �����ؾ���
       //�׷��� ���� ���� ��ũ��Ʈ���� �о ���°ŷ�


//�̹��� �� ����� �߰��ϰ�ʹٰ� �ϸ�?
		//map���� for�� �������
		
		//��� �ִ°ŵ� 





	}
	return 0;

}

//ó�� �����Ҷ� �ƿ� ������ �Ἥ �߻�ȭ ���Ѽ� ¥������
//����
//������ �ϵ� ���ϵ�
//�ʹݿ� �ϵ��ڵ� �ϴµ�.������;
//
//
//
//
//
//������