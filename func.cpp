#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<limits.h>
#include"head.h"
using namespace std;

// sort the points list with x direction with ascending order
void x_sort_merge(vector<vector<double>> &pts, int p, int q, int r)
{
	vector<vector<double>> pts_L, pts_R;
	vector<double> tmp(2,INT_MAX*1.0);
	for(auto i=p;i<=q;i++)
	{
		pts_L.push_back(pts[i]); // LHS of division
	}
	for(auto j=q+1;j<=r;j++)
	{
		pts_R.push_back(pts[j]); // RHS of division
	}
	pts_L.push_back(tmp); 
	pts_R.push_back(tmp); // ending signal
	// push the element in order
	int iL=0;
	int iR=0;
	for(auto k=p;k<=r;k++)
	{
		if(pts_L[iL][0]<pts_R[iR][0])
		{
			pts[k]=pts_L[iL];
			iL++;
		}
		else
		{
			pts[k]=pts_R[iR];
			iR++;
		}
	}
}

void x_sort(vector<vector<double>> &pts, int p, int r)
{
	if(p<r)
	{
		int q=floor((p+r)/2); // middle point
		x_sort(pts,p,q); // sort LHS
		x_sort(pts,q+1,r); // sort RHS
		x_sort_merge(pts,p,q,r); // merge
	}
}


// sort the points list with y direction with ascending order
void y_sort_merge(vector<vector<double>> &pts, int p, int q, int r)
{
	vector<vector<double>> pts_L, pts_R;
	vector<double> tmp(2,INT_MAX*1.0);
	for(auto i=p;i<=q;i++)
	{
		pts_L.push_back(pts[i]); // LHS of division
	}
	for(auto j=q+1;j<=r;j++)
	{
		pts_R.push_back(pts[j]); // RHS of division
	}
	pts_L.push_back(tmp); 
	pts_R.push_back(tmp); // ending signal
	// push the element in order
	int iL=0;
	int iR=0;
	for(auto k=p;k<=r;k++)
	{
		if(pts_L[iL][1]<pts_R[iR][1])
		{
			pts[k]=pts_L[iL];
			iL++;
		}
		else
		{
			pts[k]=pts_R[iR];
			iR++;
		}
	}
}

void y_sort(vector<vector<double>> &pts, int p, int r)
{
	if(p<r)
	{
		int q=floor((p+r)/2); // middle point
		y_sort(pts,p,q); // sort LHS
		y_sort(pts,q+1,r); // sort RHS
		y_sort_merge(pts,p,q,r); // merge
	}
}


// find the divided vertical line in the middle of a sorted point list
double find_divide(const vector<vector<double>> &sort_pts)
{
	int mid=floor(sort_pts.size()/2);
	return (sort_pts[mid-1][0]+sort_pts[mid][0])/2.0;
}

// find the index below which all elements are in the deminded region (mid-r0,mid+r0)
int binary_search(const vector<vector<double>> &sort_pts, int p, int q, double r)
{
	if(sort_pts[p][0]>=r)
	{
		return p;
	}
	else if(sort_pts[q][0]<=r)
	{
		return q;
	}
	else if(sort_pts[p][0]<=r && sort_pts[p+1][0]>=r)
	{
			return p;
	}
	else
	{
		int mid;
		mid=floor((p+q)/2);
		if(sort_pts[mid][0]<=r)
		{
			return binary_search(sort_pts,mid,q,r);
		}
		else
		{
			return binary_search(sort_pts,p,mid-1,r);
		}
	}
}

int find_index(const vector<vector<double>> &sort_pts, double mid, int mid_index, double r0)
{
	if(r0>0)
	{
		return binary_search(sort_pts,mid_index+1,sort_pts.size()-1,mid+r0);
	}
	else
	{
		return binary_search(sort_pts,0,mid_index,mid-r0);
	}
}