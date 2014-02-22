#include "list.h"
#include "blockpng.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

List<RGBAPixel> imageToList(PNG const & img)
{
	List<RGBAPixel> list;
	for (int i = 0; i < img.width(); i++)
	{
		for (int j = 0; j < img.height(); j++)
		{
            list.insertFront(*img(i,j));
		}
	}
	return list;
}

BlockPNG listToImage(List<RGBAPixel> const & list, int width, int height)
{
	BlockPNG ret;
	ret.resize(width, height);
	vector<RGBAPixel> v(list.begin(), list.end());
	int x = 0;
	int y = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		*ret(x,y) = v[i];
		y++;
		if (y == height)
		{
			y = 0;
			x++;
		}
	}
	return ret;
}

void checkSoln(string test, PNG out, string soln_file)
{
	PNG soln;
	soln.readFromFile(soln_file.c_str());

	if (!(soln == out))
		cerr << "[" << test << "]: Image does not match " << soln_file << endl;
    else
        cout << "[" << test << "]: Images match!" << endl;
}

void testInsertFront()
{
	cout << "[main]: " << __func__ << "()" << endl;

	// test insertFront
	List<int> list;
	for (int i = 1; i <= 10; i++)
		list.insertFront(i);

	cout << "[testInsertFront]: " << list << endl;
	cout << "[testInsertFront]: size: " << list.size() << endl;
	if (list.size() != 10)
		cout << "[testInsertFront]: Incorrect size" << endl;
}

void testInsertBack()
{
	cout << "[main]: " << __func__ << "()" << endl;

	// test insertBack
	List<int> list;
	for (int i = 1; i <= 10; i++)
		list.insertBack(i);

	cout << "[testInserts]: " << list << endl;
	cout << "[testInserts]: size: " << list.size() << endl;
	if (list.size() != 10)
		cout << "[testInserts]: Incorrect size" << endl;
}

void testReverse()
{

	/*List<int> list;
	for (int i = 1; i <= 2; i++)
		list.insertBack(i);
	cout << list << endl;
	list.reverse();
	cout << list << endl;*/
	
	cout << "[main]: " << __func__ << "()" << endl;
	PNG in("in.png");

	List<RGBAPixel> list = imageToList(in);
	list.reverse();

	PNG out = listToImage(list, in.width(), in.height());
	out.writeToFile("reverse.png");

	checkSoln(__func__, out, "soln_reverse.png");
}

void testShuffle()
{
	cout << "[main]: " << __func__ << "()" << endl;

    List<int> list;
	for (int i = 10; i > 0; i--)
		list.insertFront(i);
    cout << "[testShuffle]: before " << list << endl;
    list.shuffle();
    cout << "[testShuffle]: after " << list << endl;
}


int main(int argc, char ** argv) 
{
	vector<string> args(argv, argv+argc);
    if (argc == 1 || args[1] == "all")
    {
        testInsertFront();
        testInsertBack();
        testReverse();
        testShuffle();
    }
    else
    {
        if (args[1] == "front")
            testInsertFront();
        else if (args[1] == "back")
            testInsertBack();
        else if (args[1] == "reverse")
            testReverse();
        else if (args[1] == "shuffle")
            testShuffle();
    }

	return 0;
}

