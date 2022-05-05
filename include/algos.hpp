#ifndef __algos_hpp__
#define __algos_hpp__

// this file defines the algorithms used
// in this project

#include "graph.hpp"
#include <vector>

vector<string> unwrap(map<string, string>, string, string);
vector<string> BFSdst(Graph, string, string);
vector<string> BFSall(Graph, string);

#endif
