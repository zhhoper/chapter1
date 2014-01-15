/*
   this function is used to count the inverse pair of a vector
   if i < j and A[i] > A[j], then (i, j) is a inverse pair
   We adapt merge sort to realize that
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>

using namespace std;

inline int count_merge(vector<int> &input, int begin, int middle, int end)
{
	int num = 0;
	int lengthA = middle - begin +1;
	int lengthB = end - middle;

	// copy the two parts
	vector<int> tempA(lengthA);
	vector<int> tempB(lengthB);
	for(int i = 0; i < lengthA; i++)
		tempA[i] = input[i+begin];
	for(int i = 0; i < lengthB; i++)
		tempB[i] = input[i+middle+1];
	
	int iA = 0, iB = 0, index = begin;
	while(iA != lengthA && iB != lengthB)
	{
		if(tempA[iA] > tempB[iB])
		{
			input[index++] = tempB[iB++];
			num += lengthA - iA;
		}else
			input[index++] = tempA[iA++];
	}
	while(iA != lengthA)
		input[index++] = tempA[iA++];
	while(iB != lengthB)
		input[index++] = tempB[iB++];
	return num;
}

int merge(vector<int> &input, int begin, int end)
{
	if(begin == end)
		return 0;
	int middle = (begin + end)/2;
	int num = 0;
	num += merge(input, begin, middle);
	num += merge(input, middle+1, end);
	num += count_merge(input, begin, middle, end);
	return num;
}

int main()
{
	const int MAX_NUM = 100000;
	vector<int> toBeSort(MAX_NUM);
	/*for(int i = 0; i < MAX_NUM; i++)
		toBeSort[i] = MAX_NUM - i;
	*/
	ifstream inFile;
	inFile.open("permutation100000.txt");
	for(int i = 0; i < MAX_NUM; i++)
		inFile>>toBeSort[i];

	ofstream tempFile;
	tempFile.open("tempStore.txt");
	for(int i = 0; i< MAX_NUM;i++)
		tempFile<<toBeSort[i]<<endl;
	tempFile.close();

	int ground_num = 0;
	for(int i = 0; i < MAX_NUM-1; i++)
		for(int j = i+1; j < MAX_NUM; j++)
		{
			if(toBeSort[i] > toBeSort[j])
				ground_num++;
		}

	clock_t begin = clock();
	int num = merge(toBeSort, 0, MAX_NUM-1);
	clock_t end = clock();

	ofstream outFile;
	outFile.open("InversePair.txt");
	outFile<<"Time used to count InversePair is "<<1.0*(end - begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
	for(int i = 0; i < MAX_NUM; i++)
		outFile<<toBeSort[i]<<endl;
	outFile.close();
	cout<<"Ground truth number of inverse pair is "<<ground_num<<endl;
	cout<<"The number of inverse pair is "<<num<<endl;
	for(int i = 0; i < MAX_NUM;i++)
	{
		if(toBeSort[i] != i+1)
		{
			cout<<"False"<<endl;
			return 0;
		}
	}
	cout<<"True"<<endl;
	return 0;
}


