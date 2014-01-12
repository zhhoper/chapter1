#include<iostream>
#include<time.h>
#include<vector>
#include<fstream>
#include<stdlib.h>

using namespace std;
int main(){
	// inserted sort
       const int MAX_NUM = 100000;
       vector<int> toBeSorted(MAX_NUM);
       for(int i = 0; i < MAX_NUM; i++)
	       toBeSorted[i] = rand();
       clock_t begin;
       begin = clock();
       for(int i = 1; i < MAX_NUM; i++)
       {
	       int key = toBeSorted[i];
	       int j = i-1;
	       for(j = i-1; j > -1; j--)
	       {
		       if(toBeSorted[j] > key)
				toBeSorted[j+1] = toBeSorted[j];
		       else
			       break;
	       }
	       toBeSorted[j+1] = key;
       }
       clock_t end;
       end = clock();
       cout<<"The time used to sort "<<MAX_NUM<<" integer number is "<< (end - begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
       ofstream outFile;
       outFile.open("result.txt");
       outFile<<"Time used to sort "<<MAX_NUM<<" integer number is "<< (end - begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
       for(int i = 0; i < MAX_NUM; i++)
	       outFile<<toBeSorted[i]<<endl;
       outFile.close();
       return 0;
}
