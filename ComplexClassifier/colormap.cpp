
#include "colormap.h"

// might move to seperate class for reading.
// reads the file and tokenize by line
vector<vector<string>> readFile(ifstream& in)
{
    string line;
    string word;
    stringstream stream;
    vector<vector<string>> dataSet;

    while(getline(in, line)){
      stream.str(line);
      vector<string> lineTok;
      while(stream) // tokens the string by white space
      {
        stream >> word;
        cout << word << endl;
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
  //fill(rgbmap[0], rgbmap[0] + 255 * 255 * 255, 0);
}

// constructs the common parts of the colormap
void ColorMap::init()
{
  // initialize map from heap
  for(int i = 0; i < 255; i++){

  }

  ifstream colorMapFile; //file containing the colormap
	colorMapFile.open(mapDataAddress);
  vector<vector<string>> mapData;
	string line;

	if(colorMapFile.is_open())
	{
		mapData = readFile(colorMapFile);
	}
  else
  {
    cerr << "Error Default ColorMap datafile not found. " << endl;
    exit(1);
  }
  fillMap();
}

// Public methods

int ColorMap::maptoRGB(int R, int G, int B)
{
  //return rgbmap[R][G][B];
}

//ColorMap::
