#ifndef COLORMAP_H
#define COLORMAP_H

#define CLASS_NOT_FOUND 0

#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;
//RGB colormap

class ColorMap
{
  //3d color map
  private:

    string mapDataAddress; //address to the colormap data
    vector<vector<int>> labelSet;
    map<vector<int>, int>colorMap;
  protected:
    void fillMap(); //
    void init();

  public:
    ColorMap();
    ColorMap(string addr);

    int getClass(int R, int G, int B);

};

#endif // COLORMAP_H
