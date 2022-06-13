#include <iostream>
#include <cstring>
#include "vertex.h"
#include "edge.h"

using namespace std;

int main() {

  bool whilerunning = true;

  char input[100];
  char input2[100];
  char inputchar;
  char inputchar2;
  int inputnum;

  cout << "Welcome to Graph Creator! This is a program involving edges, vertexes, and other neat features that make up a graph!" << endl;
  
  while (whilerunning == true){

    cout << "What would you like to do? (ADD, DELETE, PATH, PRINT, QUIT)" << endl;

    cin >> input;

    if (strcmp(input, "ADD") == 0){

      cout << "Add an EDGE or a VERTEX?" << endl;

      cin >> input2;

      if (strcmp(input2, "EDGE") == 0){

        cout << "what is the label of the first vertex?" << endl;

	cin >> inputchar;
	
	cout << "what is the label of the second vertex?" << endl;

	cin >> inputchar2;

	cout << "what is the value of the edge?" << endl;

	cin >> inputnum;

	// add edge and with 2 labels and value
	
      }

      else if (strcmp(input2, "VERTEX") == 0){

	cout << "What is the character of the vertex?" << endl;

	cin >> inputchar;

	// add vertex with inputchar
	

      }
      
    }

    else if (strcmp(input, "DELETE") == 0){

      cout << "Delete an EDGE or VERTEX?" << endl;

      cin >> input2;

      if (strcmp(input2, "EDGE") == 0){

	cout << "What is the label of the first vertex?" << endl;

	cin >> inputchar;

	cout << "What is the label of the second vertex?" << endl;

	cin >> inputchar2;

	// delete edge with first and second label

      }

      else if (strcmp(input, "VERTEX") == 0){

	cout << "What is the label of the vertex?" << endl;

	cin >> inputchar;

	// delete vertext with label
	
      }
      
    }

    else if (strcmp(input, "PRINT") == 0){

      cout << "print function" << endl;

    }

    else if (strcmp(input, "QUIT") == 0){

      cout << "Goodbye!" << endl;
      whilerunning = false;
      break;

    }

    
    

  }
  
  



}
