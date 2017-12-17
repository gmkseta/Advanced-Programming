#include<iostream>
#include<string>
#include <deque>
#include<vector>
#include <sstream>
#include <fstream>

using namespace std;

//
//class CITY
//{
//public:
//	vector <string> name;
//	int cache;
//	CITY(string str)
//	{
//		stringstream ss(str);
//		ss >> cache;
//		do {
//			string sub;
//			ss >> sub;
//			name.push_back(sub);
//		} while (ss);
//	}
//};



int find_v(string str, deque<string> vstr)
{
	for (int i = 0; i < vstr.size(); i++)
		if (vstr[i] == str)return i;
	return -1;
}
void LRU(int n, vector<string> arr)
{
	int count = 0;


	deque<string>strarr;
	for (auto itr : arr)
	{
		if (itr == "")
			break;
		for (int k = 0; k < itr.size(); k++)
			itr[k] = toupper(itr[k]);
		int m = find_v(itr, strarr);

		if (strarr.size() < n&&m < 0)
		{
			count += 5;
			strarr.push_back(itr);
		}
		else if (m >= 0)
		{
			string temp = strarr[m];
			strarr.erase(strarr.begin() + m);
			strarr.push_back(temp);
			count++;
		}
		else
		{
			count += 5;
			if (strarr.size() != 0)
				strarr.pop_front();
			strarr.push_back(itr);
		}


	}
	cout << count << endl;
}


class CITY
{
public:
	vector <string> city_name;
	int size;
	CITY(string seq)
	{
		stringstream ss(seq);
		ss >> size;
		do
		{
			string buf;
			ss >> buf;
			city_name.push_back(buf);
		} while (ss);
	}
};

ostream& operator<<(ostream& strm, vector<string> g)
{

	for (auto itr : g)
		strm << itr << " ";
	return strm;
}
int main()
{
	

	ifstream inf("paragraph.txt");

	vector <CITY*> text_in;

	string buf;
	while (getline(inf, buf))
	{
		text_in.push_back(new CITY(buf));
	}

	for (auto itr : text_in)
	{
		cout << itr->city_name << endl;
		LRU(itr->size, itr->city_name);
	}

	


	/*ifstream inf("paragraph.txt");


	vector <CITY*> city_arr;

	
	string buf;
	while (getline(inf, buf))
	{
		city_arr.push_back(new CITY(buf));
	}
	inf.close();


	for (auto itr : city_arr)
	{
		LRU(itr->cache, itr->name);
	}
*/



	//	string arr1[10] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	//	string arr2[10] = { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" };
	//	string arr3[15] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	//	string arr4[15] = { "Jeju", "Pangyo", "NewYork", "newyork" };
	//	string arr5[15] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	//
	/*LRU(3, arr1);
	LRU(3, arr2);
	LRU(2, arr3);
	LRU(5, arr3);
	LRU(2, arr4);
	LRU(0, arr5);
	*/
	return 0;
}
