#include "scene.h"
#include ""

#include<iostream>

using namespace std;	

Scene::Scene(int size)
{
	max = size;
	int * x = new int[max];				//dymanic array
	
	for (int i = 0; i < max; max++)
	{
		x[i] = NULL;
	}
	
	
	
	
//might have to delete x as follows 'delete [] x'		
}

Scene::Scene(const Scene & source)	
{

}

const Scene & Scene::operator=	(const Scene & source)	
{

}

void Scene::changemaxlayers(int newmax)	
{

}

void Scene::addpicture(const char * FileName, int index, int x, int y)
{

}

void Scene::changelayer	(int index, int newindex)
{

}


void Scene::translate(int index, int xcoord, int ycoord)
{

}

void Scene::deletepicture(int index)
{

}


Image * Scene::getpicture(int index) const
{

}


Image Scene::drawscene()const
{

}

	
				


