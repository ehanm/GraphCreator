#ifndef vertexfile
#define vertexfile

#include <iostream>
#include <cstring>

using namespace std;

class vertex {

 public:
  char label;
  int distance;
  vertex* behind;

};

#endif
