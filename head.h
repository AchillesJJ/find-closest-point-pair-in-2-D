#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<vector>
using namespace std;

// sort the points list with x or y direction with ascending order
void x_sort(vector<vector<double>> &pts, int p, int r); // in func.cpp
void y_sort(vector<vector<double>> &pts, int p, int r); // in func.cpp

// find the divided vertical line in the middle of a sorted point list
double find_divide(const vector<vector<double>> &sort_pts); // in func.cpp

// find the index below which all elements are in the deminded region
int find_index(const vector<vector<double>> &sort_pts, double mid, int mid_index, double r0); // in func.cpp

// find the closest pair of points in 2D (in update ...)
class point_pair
{
public:
	point_pair(const vector<double> p1,const vector<double> p2)
	{
		pair_coord.push_back(p1);
		pair_coord.push_back(p2);
		distance=sqrt(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2));
	}
	vector<vector<double>> get_pair_coord() const {return pair_coord;};
	double get_distance() const {return distance;};

private:
	vector<vector<double>> pair_coord;
	double distance;
};

double find_closest_pair_2D(vector<vector<double>> &sort_pts); // in find.cpp
double find_closest_pair_2D_merge(vector<vector<double>> &sort_pts, double mid, double r1, double r2); //in find.cpp



//************ claim for testing *************//
int binary_search(const vector<vector<double>> &sort_pts, int p, int q, double r);

