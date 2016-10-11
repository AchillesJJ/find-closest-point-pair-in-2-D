#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<limits.h>
#include<time.h>
#include"head.h"
using namespace std;

int main()
{
	vector<vector<double>> test,test_c1;
	vector<double> tmp(2,0);
	srand(time(NULL));
	for(int i=0;i<200;i++)
	{
		tmp[0]=double(rand())/RAND_MAX;
		tmp[1]=double(rand())/RAND_MAX;
		test.push_back(tmp);
	}
	for(int i=0;i<200;i++)
	{
		cout<<"("<<test[i][0]<<","<<test[i][1]<<")"<<endl;
	}
	cout<<rand()<<endl;
	x_sort(test,0,test.size()-1);
	cout<<find_closest_pair_2D(test)<<endl;
	
}