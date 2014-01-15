#include<iostream>
#include<stdlib.h>
#include<vector>
#include<time.h>
#include<fstream>
using namespace std;

inline int selectSort(vector<int> &input)
{
	for(int i = 0; i < input.size()-1; i++)
	{
		int minValue = input[i];
		int pos = i;
		for(int j = i+1; j < input.size(); j++)
		{
			if(input[j] < minValue){
				minValue = input[j];
				pos = j;
			}
		}
		if(pos != i)
		{
			input[pos] = input[i];
			input[i] = minValue;
		}
	}
	return 0;
}

int main()
{
	const int MAX_NUM = 100000;
	vector<int> toBeSort(MAX_NUM);
	for(int i = 0; i < MAX_NUM; i++)
		toBeSort[i] = rand();

	clock_t begin = clock();
	selectSort(toBeSort);
	clock_t end = clock();
	ofstream outFile("selectSort.txt");
	outFile<<"Time used to sort "<<MAX_NUM<<" integers is "<<1.0*(end - begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
	for(int i = 0; i < MAX_NUM; i++)
		outFile<<toBeSort[i]<<endl;
	outFile.close();
	return 0;
}

