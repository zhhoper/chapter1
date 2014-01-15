/*
   this file inplements the merge sort algorithm
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<stdlib.h>

using namespace std;
int merge(vector<int> &input, int start, int middle, int end)
{
	// merge two sorted vectors
	// from start to middle is in one vector
	// from middle + 1 to end is in another vector
	vector<int> tempA(middle - start +1);
	vector<int> tempB(end - middle);
	// copy the vector to two temp vectors
	for(int i = 0; i < tempA.size(); i++)
		tempA[i] = input[i+start];
	for(int i = 0; i < tempB.size(); i++)
		tempB[i] = input[i+middle+1];
	int iA = 0;
	int iB = 0;
	int index = start;
	while(iA != tempA.size() && iB != tempB.size())
	{
		if(tempA[iA]  > tempB[iB])
			input[index++] = tempB[iB++];
		else
			input[index++] = tempA[iA++];
	}
	while(iA != tempA.size())
		input[index++] = tempA[iA++];
	while(iB != tempB.size())
		input[index++] = tempB[iB++];	
	return 0;
}

int mergeSort(vector<int>& toBeSort, int start, int end)
{
	// merge sort, 
	// start is the start point of vector function
	// end is the end point of the vector
	if(start == end)
		return 0;
	int middle = (start + end)/2;
	mergeSort(toBeSort, start, middle);
	mergeSort(toBeSort, middle+1, end);
	merge(toBeSort, start, middle, end);
	return 0;
}
int main(){
	// merge sort
	const int MAX_NUM = 1000000;
	vector<int> toBeSort(MAX_NUM);
	for(int i = 0; i < MAX_NUM; i++)
		toBeSort[i] = rand();
	clock_t begin;
	begin = clock();
	mergeSort(toBeSort, 0, MAX_NUM-1);
	clock_t end;
	end = clock();
	cout<<"Time used to sort "<<MAX_NUM<<" integers is "<<(end - begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
	ofstream outFile;
	outFile.open("mergeSort.txt");
	outFile<<"Time used to sort "<<MAX_NUM<<" integers is "<<(end - begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
	for(int i = 0; i < MAX_NUM; i++)
		outFile<<toBeSort[i]<<endl;
	outFile.close();
	return 0;
}
