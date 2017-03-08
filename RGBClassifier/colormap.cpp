
#include "colormap.h"

// might move to seperate class for reading.
// reads the file and tokenize by line

// reads in the file for the colormap
vector<vector<int>> readFile(ifstream& in)
{
    string line;
    int word;
    stringstream stream;
    vector<vector<int>> dataSet;

    while(getline(in, line)){
      //cout << line << endl;
      stringstream stream;
      stream.str(line);
      vector<int> lineTok;
      while(stream >> word) // tokens the string by white space
      {
      //  cout << word << endl;
        lineTok.push_back(word);
      }

      dataSet.push_back(lineTok);
    }

    return dataSet;
}

// constructors
ColorMap::ColorMap()
{
  mapDataAddress = "colormap_data.tsv";
  init();
}

ColorMap::ColorMap(string addr)
{
  mapDataAddress = addr;
  init();
}

// Protected

// fills the color map with the default valueset.
void ColorMap::fillMap()
{
  int i = 1;
  //fill(rgbmap[0], rgbmap[0] + 255 * 255 * 255, 0); // too large
  for(auto n: labelSet)
  {
    colorMap[n] = i;
    i++;
  }
}

// constructs the common parts of the colormap
void ColorMap::init()
{
  // initialize map from heap
  for(int i = 0; i < 255; i++){

  }

  ifstream colorMapFile; //file containing the colormap
	colorMapFile.open(mapDataAddress);
	string line;

	if(colorMapFile.is_open())
	{
		labelSet = readFile(colorMapFile);
	}
  else
  {
    cerr << "Error Default ColorMap datafile not found. " << endl;
    exit(1);
  }

  fillMap();
}

// Public methods

int ColorMap::getClass(int R, int G, int B)
{
  //return rgbmap[R][G][B];
  vector<int> rgb;
  rgb.push_back(R);
  rgb.push_back(G);
  rgb.push_back(B);

  int label = colorMap[rgb];
  cout << label << endl;
  return label;
}

//ColorMap::
