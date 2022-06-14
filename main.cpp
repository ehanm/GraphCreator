#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <cmath>
#include <map>
#include <stdlib.h>
#include "vertex.h"
#include "edge.h"

using namespace std;

vector<vertex*> vertices; // vectors to hold both vectors and edges
vector<edge*> edges;
void vertexadd(char label);
void edgeadd(char firstlabel, char secondlabel, int value);

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

        edgeadd(inputchar, inputchar2, inputnum);
	
      }

      else if (strcmp(input2, "VERTEX") == 0){

	cout << "What is the character of the vertex?" << endl;

	cin >> inputchar;

	vertexadd(inputchar);

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

      whilerunning = false;
      break;

    }

    
  
  }
  

}

void vertexadd(char label){

  vertex* temp = new vertex();
  temp->label = label;
  bool check = false;
  vector<vertex*>::iterator v;

  for (v = vertices.begin(); v != vertices.end(); v++){ // checking if the vertex already exists

    if ((*v)->label == label){
      check = true;
    }

  }

  if (check != true){

    vertices.push_back(temp);
    cout << "Vertex added!" << endl;

  }

  else {

    cout << "Can't make a duplicate vertex!" << endl;

  }

  return;


}

void edgeadd(char firstlabel, char secondlabel, int value){

  edge* temp = new edge();
  vertex* first = NULL;
  vertex* second = NULL;
  bool check = false;
  vector<vertex*>::iterator v;
  vector<edge*>::iterator e;
  
  for (v = vertices.begin(); v != vertices.end(); v++){ // first and second vertices

    if ((*v)->label == firstlabel){

      first = *v;
      
    }

    if ((*v)->label == secondlabel){

      second = *v;

    }
    
  }

  if (first == NULL && second == NULL){

    cout << "neither labels found." << endl;
    return;

  }

  if (first == second) { // stops user from making an edge between a vertex and itself

    cout << "You can't connect a vertex to itself!" << endl;
    return;

  }

  for (e = edges.begin(); e != edges.end(); e++) {

    if (((*e)->first == first && (*e)->second == second)){

      check = true;

    }
  }

  if (first != NULL && second != NULL && check != true){

    temp->first = first;
    temp->second = second;
    temp->value = value;
    edges.push_back(temp);

    cout << "edge connected!" << endl;

  }

  else if (first != NULL && second != NULL && check == true){

    cout << "an edge connecting these vertices already exists." << endl;

  }

  else {

    cout << "One or both of the vertices don't exist" << endl;

  }

  return;
  
}
