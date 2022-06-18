// This is a program that develops a graph involving edges and vertexes.
// Things to add: algorithm

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
void vertexremove(char label);
void edgeremove(char first, char second, bool check);
void printfunction();

int main() {

  bool whilerunning = true;

  char input[100];
  char input2[100];
  char inputchar;
  char inputchar2;
  int inputnum;

  cout << "Welcome to Graph Creator! This is a program involving edges, vertexes, and other neat features that make up a graph!" << endl;
  
  while (whilerunning == true){

    cout << "What would you like to do? (ADD, DELETE, PRINT, QUIT)" << endl;

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

	edgeremove(inputchar, inputchar2, true);
	
      }

      else if (strcmp(input2, "VERTEX") == 0){

	cout << "What is the label of the vertex?" << endl;

	cin >> inputchar;

	vertexremove(inputchar);
      }
      
    }

    else if (strcmp(input, "PRINT") == 0){

      printfunction();
      
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

void vertexremove(char label) {

  vector<vertex*>::iterator v;
  vector<edge*>::iterator e;
  bool hasedge = false;
  char input[100];

  if (vertices.empty() == true){ // if no vertexes exist

    cout << "No vertices to delete!" << endl;
    return;
    
  }

  for (v = vertices.begin(); v != vertices.end(); v++){

    if ((*v)->label == label){
      for (e = edges.begin(); e != edges.end(); e++){

	if ((*e)->first == *v || (*e)->second == *v){
	  hasedge = true;
	}

      }
      if (hasedge == true){

	cout << "This vertex contains an edge. Remove? (YES/NO)" << endl;
	cin >> input;

	if (strcmp(input, "YES") == 0) {

	  bool stillrunning = false;
	  while (stillrunning == true){

	    for (e = edges.begin(); e != edges.end(); e++){

	      if (e == edges.end() - 1){

	        stillrunning = true;
		
	      }

	      if ((*e)->first == *v || (*e)->second == *v){

		edgeremove((*e)->first->label, (*e)->second->label, false); // deletes any existing edges too
		edgeremove((*e)->second->label, (*e)->first->label, false);
		break;

	      }
	      
	    }

	  }

	  vertices.erase(v);
	  cout << "vertex removed" << endl;
	  return;

	}

	else {

	  cout << "vertex no removed" << endl;
	  return;

	}

      }

      else {

	vertices.erase(v);
	cout << "vertex removed" << endl;
	return;

      }

    }
    
  }

}

void edgeremove(char first, char second, bool check){

  vertex* firsttemp = NULL;
  vertex* secondtemp = NULL;
  vector<vertex*>::iterator v;
  vector<edge*>::iterator e;
  
  if (edges.empty() == true){ // if no edges

    if (check == true){

      cout << "No edges" << endl;

    }
    return;
    
  }

  for (v = vertices.begin(); v != vertices.end(); v++){
    if ((*v)->label == first){

      firsttemp = *v;
      
    }
    if ((*v)->label == second){

      secondtemp = *v;

    }
  }

  if (firsttemp == NULL || secondtemp == NULL) {

    cout << "One or both of vertexes not in existance" << endl; // ensures user doesn't enter some NULL vertex
    return;
    
  }

  if (firsttemp == secondtemp) {

    cout << "vertex can't be connected to itself!" << endl; // ensures user can't enter the same vertex twice
    return;

  }

  for (e = edges.begin(); e != edges.end(); e++) {

    if (((*e)->first == firsttemp && (*e)->second == secondtemp)){

      edges.erase(e);
      if (check == true){
	cout << "edge removed" << endl;
      }
      return;

    }
  }

  if (firsttemp != NULL && secondtemp != NULL && check == true){

    cout << "This edge does not exist" << endl;
    
  }
  else {

    if (check == true){

      cout << "edge removed" << endl;

    }
    return;
    
  }

  return;

}

void printfunction(){

  if (vertices.empty()) {
    cout << "There are no vertices." << endl;
    return;
  }
  
  cout << "\t";
  vector<vertex*>::iterator v;

  for (v = vertices.begin(); v != vertices.end(); v++) { // prints vertices on top row
    cout << (*v)->label << "\t";
  }
  cout << endl;

  vector<vertex*>::iterator v2;
  vector<edge*>::iterator e; 

  for (v = vertices.begin(); v != vertices.end(); v++) { // prints vertices on the left side
    cout << (*v)->label << "\t";

    for (v2 = vertices.begin(); v2 != vertices.end(); v2++) {
      bool connection = false;
      if (v2 == v) {
	cout << "n/a";
	connection = true;
      }
      else {
	for (e = edges.begin(); e != edges.end(); e++) {
	  if ((*e)->first == *v) {
	    if ((*e)->second == *v2) {
	      cout << (*e)->value;
	      connection = true;
	    }
	  }
	}
      }
      
      if (connection != true){ // if the 2 vertexes are able to be connected but no connection exists
	cout << "none";
      }
      
      cout << "\t";
    }
    cout << endl;
  }


}
