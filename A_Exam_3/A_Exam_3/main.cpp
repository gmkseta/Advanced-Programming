#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

void main()
{
	using namespace std;

	ifstream inputfile("paragraph.txt");

	string input_string;

	stringstream string_stream;

	string_stream << inputfile.rdbuf();
	input_string = string_stream.str();

	cout << input_string << endl;

	string typed_string;

	
	auto begin = chrono::high_resolution_clock::now();

	getline(cin, typed_string);

	// end time check	
	auto end = chrono::high_resolution_clock::now();

	cout <<chrono::duration_cast<chrono::milliseconds>(end - begin).count() / 1000.0 << "s" << endl;

	cout << "Comparison " << typed_string.compare(input_string) << endl;


}