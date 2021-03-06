#ifndef COLORMAP_H
#define COLORMAP_H


//#include "feature.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;
//RGB colormap

class ColorMap
{
  //3d color map
  private:
    int*** rgbmap; // too large

    string mapDataAddress; //address to the colormap data

  protected:
    void fillMap(); //
    void init();

  public:
    ColorMap();
    ColorMap(string addr);

    int maptoRGB(int R, int G, int B);

};

#endif // COLORMAP_H
