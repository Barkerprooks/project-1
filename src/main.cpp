#include <algorithm>
#include <iostream>
#include <vector>

#include "graph.hpp"
#include "algos.hpp"
#include "tasks.hpp"

void showFlights(vector<string>);

int main(int argc, char **argv) {

  cout << "Welcome to " << string(argv[0]).substr(2) << endl;
  if(argc != 2) {
    cout << "usage: " << argv[0] << " <input>" << endl;
    return 0;
  }

  ifstream file(argv[1]);
  if(!file.good()) {
    cout << argv[1] << " is not a file" << endl;
    return 0;
  }
  // initialize the graph class
  Graph cities(file);

  vector<string> route;
  string input;

  while(true) {
   
    cout << "1) x connections from a to b" << endl;
    cout << "2) from a to d through b and c" << endl;
    cout << "3) around the world and back" << endl;
    cout << "l) list all nodes" << endl;
    cout << "i) list all inner nodes (nodes with outbound connections)" << endl;
    cout << "q) quit" << endl;
    while(!validInput("select from menu", input, {"1","2","3","4","l","i","q"}))
      cout << "not a valid option" << endl;

    if(input == "q")
      break;

    if(input == "l") {
      for(string city : cities.getNodes())
        cout << city << endl;
    } else if(input == "i") {
      for(string city : cities.getNodesWithEdges())
        cout << city << endl; 
    }

    if(input == "1")
      showFlights(task1(cities));
    else if(input == "2")
      showFlights(task2(cities));
    else if(input == "3")
      showFlights(task3(cities));
  }

  return 0;
}

void showFlights(vector<string> route) {
  if(route.empty()) {
    cout << "no path available" << endl;
    return;
  }

  cout << "[Result] connecting flights: " << route.size() - 1 << endl;
  cout << route[0];
  for(size_t i = 1; i < route.size(); i++)
    cout << " -> " << route[i];
  cout << endl;
}
