#ifndef __tasks_hpp__
#define __tasks_hpp__

#include <vector>
#include <string>

#include "graph.hpp"

bool validInput(string, string &, set<string>);
bool valueInput(string, unsigned int &);
void showFlight(vector<string>);

vector<string> task1(Graph);
vector<string> task2(Graph);
vector<string> task3(Graph);

#endif
