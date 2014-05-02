/**
 * @file dsets.h
*/

#ifndef DSETS_H
#define DSETS_H

#include <vector>

using std::vector;

class DisjointSets
{
	public:
		void addelements(int num);
		int find(int elem);
		void setunion(int a, int b);

	private:
		vector< int > vec; 
		
		
	//helper function declaration here
		bool isBigger(int a, int b);
};

#endif

