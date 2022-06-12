#include <iostream>
#include <cstring>

using namespace std;

int main() {

  bool whilerunning = true;

  char input[100];
  char input2[100];
  char inputchar;

  cout << "Welcome to Graph Creator! This is a program involving edges, vertexes, and other neat features that make up a graph!" << endl;
  
  while (whilerunning == true){

    cout << "What would you like to do? (ADD, DELETE, PATH, PRINT, QUIT)" << endl;

    cin >> input;

    if (strcmp(input, "ADD") == 0){

      cout << "Add an edge or a vertex?" << endl;

      cin >> input2;
      
    }

    if (strcmp(input, "DELETE") == 0){

      cout << "Delete an edge or vertex?" << endl;

      cin >> input2;
      
    }

    if (strcmp(input, "QUIT") == 0){

      cout << "Goodbye!" << endl;
      whilerunning = false;
      break;

    }

    
    

  }
  
  



}
