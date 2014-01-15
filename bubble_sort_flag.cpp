#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<fstream>
using namespace std;

inline int swap(vector<int> &input, int a, int b)
{
	int temp = input[a];
	input[a] = input[b];
	input[b] = temp;
	return 0;
}

int bubble_sort(vector<int> &vec)
{
	int flag = 1;
	while(flag)
	{
		int exchange = flag;
		flag = 0;
		for(int i = vec.size()-1; i > exchange-1; i--)
		{
			if(vec[i] < vec[i-1])
			{
				swap(vec, i, i-1);
				flag = i;
			}
		}
	}
	return 0;
}

int main()
{
	const int MAX_NUM = 100000;
	vector<int> toBeSort(MAX_NUM);
	for(int i = 0; i< MAX_NUM; i++)
		toBeSort[i] = rand();

	clock_t begin = clock();
	bubble_sort(toBeSort);
	clock_t end = clock();
	ofstream outFile("bubble_sort_flag.txt");
	outFile<<"Time used to sort "<<MAX_NUM<<" integer is "<< 1.0*(end - begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
	for(int i = 0; i < MAX_NUM; i++)
		outFile << toBeSort[i]<<endl;
	outFile.close();
	return 0;
}
				

