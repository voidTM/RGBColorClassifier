#include <iostream>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <vector>
#include "colormap.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <random>
#include <fstream>

using namespace std;
//using namespace cv;


int main(int argc, char* argv[]) {
  ColorMap map;
  int label;
  label = map.getClass(1, 22, 25);
  label = map.getClass(0,	55,	88);
  if(label == CLASS_NOT_FOUND)
    cout << "couldnt find class" << endl;
  return 0;
}
