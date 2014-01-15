#include<iostream>
#include<vector>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int binary_search(vector<int> input, int key)
{
	// binary search to find whether there is a key in the input
        // vector, we suppose the input vector is sorted
	// if find, return the position 
	// if not, return -1
	int low = 0;
	int high = input.size()-1;
	int pos = (low+high)/2;
	while(low < high)
	{
		if(input[pos] == key)
			return pos;
		else if( input[pos] < key)
			low = pos + 1;
		else
			high = pos - 1;
		pos = (low+high)/2;
	}
	return -1;
}

int main(){
	const int MAX_NUM = 10000000;
	vector<int> toFind(MAX_NUM);
	for(int i = 0; i < MAX_NUM; i++)
		toFind[i] = i;
	int key = rand()%MAX_NUM;
	clock_t begin = clock();
	int pos = binary_search(toFind, key);
	clock_t end = clock();
	cout<<"The key word "<<key<<" is at the position "<<pos<<". The time used to find the key word is "<<1.0*(end - begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
	return 0;
}
