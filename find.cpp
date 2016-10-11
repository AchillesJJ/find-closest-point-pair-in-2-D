#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<limits.h>
#include"head.h"
using namespace std;

/*
	give the distance between two points
*/
double pair_distance(vector<double> p1, vector<double> p2)
{
	return sqrt(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2));
}

/*
	merge 2 parts of points in which closest pair has been found individually
*/
double find_closest_pair_2D_merge(vector<vector<double>> &sort_pts, double mid, int mid_index, double r1, double r2)
{
	double r0;
	r0=min(r1,r2);
	int bound_L,bound_R;
	bound_R=find_index(sort_pts,mid,mid_index,r0); // RHS bound
	bound_L=find_index(sort_pts,mid,mid_index,-r0); // LHS bound
	vector<vector<double>> bound_pts;
	for(int i=bound_L;i<=bound_R;i++)
	{
		bound_pts.push_back(sort_pts[i]);
	}
	y_sort(bound_pts,0,bound_pts.size()-1); // sort bounded point list alone Y-axis
	for(int i=0;i<bound_pts.size()-1;i++)
	{
		for(int j=1;j<=min(int(bound_pts.size())-1-i,6);j++)
		{
			if(pair_distance(bound_pts[i],bound_pts[i+j])<r0)
			{
				r0=pair_distance(bound_pts[i],bound_pts[i+j]);
			}
		}
	}
	return r0;
}

/*
	find closest point pair in 2-D plane
	using divide-and-conquer method
*/
double find_closest_pair_2D(vector<vector<double>> &x_sort_pts)
{
	if(x_sort_pts.size()>=2)
	{
		double mid,pair_L,pair_R;
		int mid_index;
		int num=x_sort_pts.size();
		vector<vector<double>> pts_L,pts_R;

		mid=find_divide(x_sort_pts); // find divide line
		mid_index=floor(num/2)-1;  // index of the point next to the LHS of vertical line
		for(int i=0;i<=mid_index;i++)
		{
			pts_L.push_back(x_sort_pts[i]); // LHS subset of points
		}
		for(int i=mid_index+1;i<=num-1;i++)
		{
			pts_R.push_back(x_sort_pts[i]); // RHS subset of points
		}
		pair_L=find_closest_pair_2D(pts_L);
		pair_R=find_closest_pair_2D(pts_R);
		return find_closest_pair_2D_merge(x_sort_pts,mid,mid_index,pair_L,pair_R);

	}
	else if(x_sort_pts.size()==2)
	{
		return pair_distance(x_sort_pts[0],x_sort_pts[1]);
	}
	else
	{
		return INT_MAX*1.0;
	}
}