#include <set>
#include <queue>

#include "algos.hpp"

vector<string> BFSdst(Graph g, string src, string dst) {

  queue<pair<string, vector<string>>> nodes; // node queue
  set<string> visited;// set of visited nodes
  vector<string> nodePath;
  string node;

  nodes.push({src, {src}});

  while(!nodes.empty()) {
    
    node = nodes.front().first;
    nodePath = nodes.front().second;
    nodes.pop();
    
    if(node == dst)
      return nodePath;
 
    for(string connection : g.getNodes(node)) {
      if(visited.count(connection) == 0) {
        visited.insert(connection);
        nodePath.push_back(connection);
        nodes.push({connection, nodePath});
      }
    }
  }

  return {};
}

vector<string> BFSall(Graph g, string src) {

  queue<pair<string, vector<string>>> nodes; // node queue
  set<string> visited;// set of visited nodes
  vector<string> nodePath;
  string node;

  nodes.push({src, {src}});

  while(!nodes.empty()) {
    
    node = nodes.front().first;
    nodePath = nodes.front().second;
    nodes.pop();
    
    if(nodePath.size() == g.getNodes().size())
      return nodePath;

    for(string connection : g.getNodes(node)) {
      nodePath.push_back(connection);
      nodes.push({connection, nodePath});
    }
  }

  return {};
}
