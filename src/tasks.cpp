#include "tasks.hpp"
#include "algos.hpp"

#include <iostream>

bool validInput(string message, string &input, set<string> valid) {
  cout << message << ": ";
  getline(cin, input);
  return (bool) valid.count(input);
}

bool valueInput(string message, unsigned int &x) {
  cout << message << ": ";
  try {
    string input;
    getline(cin, input);
    x = stoul(input, nullptr, 0);
  } catch (...) {
    return false;
  }
  return true;
}

vector<string> task1(Graph g) {
 
  vector<string> route;
  set<string> valid;
  string a, b;
  unsigned int x;

  valid = g.getNodesWithEdges();

  while(!validInput("[Task 1] Enter city A (inner node)", a, valid))
    cout << "not a valid city" << endl;

  valid = g.getNodes(); // valid choices are now all nodes
  valid.erase(a);
        
  while(!validInput("[Task 1] Enter city B (not city A)", b, valid)) {
    if(a == b)
      cout << "You are already here" << endl;
    else
      cout << "not a valid city" << endl;
  }
        
  while(!valueInput("[Task 1] Enter desired # of connections", x))
    cout << "not a valid number" << endl;

  route = BFSdst(g, a, b);

  if(route.size() > x)
    return {};

  return route;
}

vector<string> task2(Graph g) {
  
  vector<string> route, routeA, routeB, routeC;
  set<string> valid;
  string a, b, c, d;

  valid = g.getNodesWithEdges();

  while(!validInput("[Task 1] Enter city A (inner node)", a, valid))
    cout << "not a valid city" << endl;

  valid.erase(a);
        
  while(!validInput("[Task 1] Enter city B (inner node)", b, valid)) {
    if(b == a)
      cout << "You are already here" << endl;
    else
      cout << "not a valid city" << endl;
  }
  
  valid.erase(b);

  while(!validInput("[Task 1] Enter city C (inner node)", c, valid)) {
    if(c == a || c == b)
      cout << "You are already here" << endl;
    else
      cout << "not a valid city" << endl;
  }
  
  valid = g.getNodes(); // valid choices are now all nodes
  valid.erase(a);
  valid.erase(b);
  valid.erase(c);

  while(!validInput("[Task 1] Enter city D (not city A/B/C)", d, valid)) {
    if(d == a || d == b || d == c)
      cout << "You are already here" << endl;
    else
      cout << "not a valid city" << endl;
  }
 
  routeA = BFSdst(g, a, b);
  routeB = BFSdst(g, b, c);
  routeC = BFSdst(g, c, d);

  routeA.pop_back();
  routeB.pop_back();

  route.insert(route.end(), routeA.begin(), routeA.end());
  route.insert(route.end(), routeB.begin(), routeB.end());
  route.insert(route.end(), routeC.begin(), routeC.end());

  return route;
}


vector<string> task3(Graph g) {
  
  vector<string> route, routeA, routeB;
  set<string> valid;
  string s;

  valid = g.getNodesWithEdges();

  while(!validInput("[Task 3] Enter starting city", s, valid))
    cout << "not a valid city" << endl;
  
  cout << "[Task 3] running..." << endl;
  
  routeA = DFSall(g, s);
  routeB = BFSdst(g, routeA[routeA.size() - 1], s);

  routeA.pop_back();
  
  route.insert(route.end(), routeA.begin(), routeA.end());
  route.insert(route.end(), routeB.begin(), routeB.end());

  return route;
}
