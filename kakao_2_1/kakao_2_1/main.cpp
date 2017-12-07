#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
int getScore(char a)
{
	if (a >='0' && a <= '9')
		return a - 48;
	return -1;//숫자가 아닐시 -1리턴

}
int getBonus(int s, char op)
{
	if (op == 'D')
		return s*s;
	else if (op == 'T')
		return s*s*s;
	else
		return s;
}
bool getOption(char o)
{
	if (o == '#' || o == '*')
		return true;
	else
		return false;
}

int solution2(string dartResult)
{
	int* scores = new int[3];
	int number = 0;

	for (int i = 0; i < dartResult.length();number++ )
	{
		int score = getScore(dartResult[i++]);

		if (score == 1 && dartResult[i] == '0')
		{
			score = 10;
			i++;
		}


		scores[number] = getBonus(score, dartResult[i++]);


		if (i < dartResult.length()&& getOption(dartResult[i]))
		{
			if (dartResult[i] == '*'&&number > 0)
			{
				scores[number] *= 2;
				scores[number - 1] *= 2;
			}
			else if (dartResult[i] == '#')
				scores[number] *= -1;
			else
				scores[number] *= 2;
			i++;
		}

	}

	return scores[0] + scores[1] + scores[2];

}



int main(void)
{
	cout << "answer : " << solution2("1S2D*3T") << endl;
	cout << "answer : " << solution2("1D2S#10S") << endl;
	cout << "answer : " << solution2("1D2S0T") << endl;
	cout << "answer : " << solution2("1S*2T*3S") << endl;
	cout << "answer : " << solution2("1D#2S*3S") << endl;
	cout << "answer : " << solution2("1T2D3D#") << endl;
	cout << "answer : " << solution2("1D2S3T*") << endl;

	return 0;
}
