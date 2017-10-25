#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>

void main()
{
	using namespace std;
	ifstream inf("paragraph.txt");
	stringstream infstream;
	string inStr;

	infstream << inf.rdbuf();
	inStr = infstream.str();

	cout << inStr << endl;

	string type_str;

	auto begin = chrono::high_resolution_clock::now();

	getline(cin, type_str);

	auto end = chrono::high_resolution_clock::now();

	cout << chrono::duration_cast<chrono::microseconds>(end - begin).count() / 1000.0 << "s" << endl;
	cout << "c" << type_str.compare(inStr) << endl;

}

//#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <chrono>
//void main()
//{
//	using namespace std;
//	ifstream inf("paragraph.txt");
//	string input_string;
//	stringstream string_steam;
//	string_steam << inf.rdbuf();
//	input_string = string_steam.str();
//	cout << input_string << endl;
//	string typing_str;
//	auto begin = chrono::high_resolution_clock::now();
//	getline(cin, typing_str);
//	auto end = chrono::high_resolution_clock::now();
//	cout << chrono::duration_cast<chrono::microseconds>(end - begin).count() / 1000.0 << "s" << endl;
//	cout << "Comparision" << typing_str.compare(input_string) << endl;
//
//}
//
