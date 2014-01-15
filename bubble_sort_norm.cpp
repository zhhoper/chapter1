#include<iostream>
#include<stdlib.h>
#include<vector>
#include<time.h>
#include<fstream>
using namespace std;

inline int swapNormal(vector<int> &vec, int a, int b)
{
	int temp = vec[a];
	vec[a] = vec[b];
	vec[b] = temp;
	return 0;
}

inline int swap_xor(vector<int> &vec, int a, int b)
{
	vec[a] = vec[a]^vec[b];
	vec[b] = vec[a]^vec[b];
	vec[a] = vec[a]^vec[b];
	return 0;
}

int bubble_sort(vector<int>& toBeSort)
{
	// bubble_sort with out flag
	int num = toBeSort.size();
	for(int i = 0; i < num-1; i++)
		for(int j = num-1; j > 0; j--)
		{
			if(toBeSort[j] < toBeSort[j-1])
				swap_xor(toBeSort, j, j-1);
		}
	return 0;
}

int main()
{
	const int MAX_NUM = 100000;
	vector<int> toBeSort(MAX_NUM);
	for(int i = 0; i < MAX_NUM; i++)
		toBeSort[i] = rand();
	clock_t begin;
	begin = clock();
	bubble_sort(toBeSort);
	clock_t end = clock();
	ofstream outFile;
	outFile.open("bubbleSortNormal_xor.txt");
	outFile<<"Using xor swap"<<endl;
	outFile<<"Time used to sort "<<MAX_NUM<<" integers is "<<1.0*(end - begin)/	CLOCKS_PER_SEC*1000<<" ms"<<endl;
	for(int i = 0; i < MAX_NUM; i++)
		outFile<<toBeSort[i]<<endl;
	outFile.close();
	return 0;
}


