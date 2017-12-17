#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;


int find_v(string str, deque<string> vstr)
{
	for (int i = 0; i<vstr.size(); i++)
	{
		if (vstr[i] == str)return i;
	}
	return -1;
}

void LRU(int n, string arr[]) //n은 캐시 사이즈
{
	int count = 0;
	deque<string> strarr; //캐시


	for (int i = 0; arr[i].size()<=20&&arr[i].size()>0 ; i++)
	{
		for (int k = 0; k<arr[i].size(); k++)
			arr[i][k] = toupper(arr[i][k]);	

		int m = find_v(arr[i], strarr);
		if (strarr.size()<n &&m<0)
		{
			count += 5;
			strarr.push_back(arr[i]);
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
			strarr.push_back(arr[i]);
		} 
	}

	cout << count << endl;

}

int main()
{
	string arr1[10] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	string arr2[10] = { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" };
	string arr3[15] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	string arr4[15] = { "Jeju", "Pangyo", "NewYork", "newyork" };
	string arr5[15] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	
	LRU(3, arr1);
	LRU(3, arr2);
	LRU(2, arr3);
	LRU(5, arr3);
	LRU(2, arr4);
	LRU(0, arr5);
	return 0;
}

