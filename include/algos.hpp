#ifndef __algos_hpp__
#define __algos_hpp__

// this file defines the algorithms used
// in this project

#include "graph.hpp"
#include <vector>

vector<string> BFSdst(Graph, string, string);
vector<string> BFSthru(Graph, string, string, string, string);

void DFSvisit(Graph, string, set<string> &, vector<string> &);
vector<string> DFSall(Graph, string);

#endif
