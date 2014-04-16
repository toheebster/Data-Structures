/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include "kdtree.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;
//=============================================================================================================
template<int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim> & first, const Point<Dim> & second, int curDim) const
{
	if (first[curDim] < second[curDim])
		return true;
		
	else if ((first[curDim] == second[curDim]) && (first < second))
		return true;
			
	else
		return false;	
}
//===================================================================================================

template<int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim> & target, const Point<Dim> & currentBest, const Point<Dim> & potential) const
{
	if(dist(potential, target) < dist(currentBest, target))
		return true;
		
	else if	((dist(potential, target) == dist(currentBest, target)) && (potential < currentBest))	
		return true;

    return false;
}

template<int Dim>
int KDTree<Dim>::dist(const Point<Dim> & temp, const Point<Dim> & target) const
{
	int sum = 0;
	for(int i = 0; i < Dim; i++)
	{
		sum += ((target[i] - temp[i])*(target[i] - temp[i]));
	}

	return sum;	
}

//====================	CONSTRUCTOR	===========================================================
template<int Dim>
KDTree<Dim>::KDTree(const vector< Point<Dim> > & newPoints)
{
    points = newPoints;
    constHelp(points, 0, (points.size()-1), (points.size()-1)/2, 0);
}

template<int Dim>
void KDTree<Dim>::constHelp(vector< Point<Dim> > & Points, int left, int right, int center, int dimension)
{
	if (left< right)
	{
    	select(points, left, right, center, dimension);

	    dimension = (dimension+1) % Dim;

	    constHelp(points, left, center-1, (left+center-1)/2, dimension);
	    constHelp(points, center+1, right, (center+1+right)/2, dimension);
	}
}

template<int Dim>
Point<Dim> KDTree<Dim>::select(vector< Point<Dim> > & newPoints, int left, int right, int avg, int dimension)
{
	if (left>= right)
    	return newPoints[left];

	int pivotIndex = avg;
	Point<Dim> pivotValue = newPoints[pivotIndex];

    Point<Dim> temp = newPoints[pivotIndex];
    newPoints[pivotIndex] = newPoints[right];
    newPoints[right] = temp;

    int storeIndex = left;

    for(int i=left; i<right; i++)
    	if (smallerDimVal(newPoints[i], pivotValue, dimension))
        {
        	Point<Dim> tem = newPoints[storeIndex];
            newPoints[storeIndex] = newPoints[i];
            newPoints[i] = tem;

            storeIndex++;
		}

        temp = newPoints[right];
        newPoints[right] = newPoints[storeIndex];
        newPoints[storeIndex] = temp;


	int pivotNewIndex = storeIndex;
	int pivotDist = pivotNewIndex;
	
	if(pivotDist == avg)
		return newPoints[pivotNewIndex];
	
	else if(avg < pivotDist)
    	return select(newPoints, left, pivotNewIndex - 1, avg, dimension);
    else
    	return select(newPoints, pivotNewIndex + 1, right, avg, dimension);
}

//=============================================================================================

template<int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> & query) const
{
	return Point<Dim>();
	//find_helper(query, 0, points.size()-1, 0);	
}	
/*
template<int Dim>
Point<Dim> KDTree<Dim>::find_helper(const Point<Dim> & query, int left, int right, int dim) const
{
	Point<Dim> retval;
	Point<Dim> x;
	int med = (left + right)/2;
	
	if(left>=right)
	{
		retval=points[left];
		return retval;
	}
	
	if(smallerDimVal(query,points[med],dim%Dim))
	{
		retval=find_helper(query,left,med-1,(dim+1)%Dim);
		retval=findhelp(query, retval, left, right, med, dim);
		int a=0;
		if(shouldReplace(query,retval,points[med]))
			retval=points[med];
		for (int i=0;i<Dim;i++)
			a=a+pow(query[i]-retval[i],2);
		if(pow(points[med][dim%Dim]-query[dim%Dim],2)<=a)
		{
			Point<Dim> y;
			y=find_helper(query,med+1,right,(dim+1)%Dim);
			if(shouldReplace(query,retval,y))
			{
				retval=y;
			}
		}
		
	}
	
	else
	{
		retval=find_helper(query,med+1,right,(dim+1)%Dim);
		retval=findhelp(query, retval, med, dim);
		int a=0;
		if(shouldReplace(query,retval,points[med]))
			retval=points[med];
		for (int i=0;i<Dim;i++)
			a=a+pow(query[i]-retval[i],2);
		if(pow(points[med][dim%Dim]-query[dim%Dim],2)<=a)
		{
			Point<Dim> y;
			y=find_helper(query,left,med-1,(dim+1)%Dim);
			if(shouldReplace(query,retval,y))
			{
				retval=y;
			}
		}
	}
	return retval;	
}*/
