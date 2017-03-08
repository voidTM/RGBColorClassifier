
#include "colormap.h"

vector<vector<string>> parse(iftream& in)
{
    string line;
    string word;
    stringstream stream;
    vector<vector<string>> dataSet

    while(getline(in, line)){
      stream.str(line);
      vector<string> parsedLine;
      while(stream) //read until stream is empty
      {
        stream >> word;
        cout << word << endl;
        parsedLine.push_back(word);
      }

      dataSet.push_back(parsedLine);
    }

    return dataSet;
}

// constructors
ColorMap::ColorMap()
{
  mapDataAddress = "colormap_data.tsv";
  ifstream colorMapFile; //file containing the colormap
	colorMapFile.open(mapDataAddress);
	string line

	if(colorMapFile.is_open)
	{
		while(getline(colorMapFile, ))
	}
}

ColorMap::ColorMap(string addr)
{
  ifstream colorMapFile; //file containing the colormap
	colorMapFile.open("colormap_data.txt");
	string line

	if(colorMapFile.is_open)
	{
    getline(colorMapFile, line);
    // parse and get each line
		while(getline(colorMapFile, line))
    {

    }
	}
}

//Protected
ColorMap::fillMap();


ColorMap::
ColorMap::
