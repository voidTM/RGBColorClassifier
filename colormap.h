#ifndef COLORMAP_H
#define COLORMAP_H

#define CLASS_NOT_FOUND -1

#include "feature.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <sstream>

using namespace std;
//RGB colormap
class ColorMap
{
  //3d color map
  private:
    int map[255][255][255];
    string mapDataAddress; //address to the colormap data

  protected:
    void fillMap(); //

  public:
    ColorMap();
    ColorMap(string addr);

    maptoRGB(int R, int G, int B);

};

#endif // COLORMAP_H
