#include "Graph.h"
#include <algorithm>
#include <iostream>

Graph::Graph(const int nodeNumber) :
	numberOfNodes(nodeNumber)
{
	adj = new std::list<int>[nodeNumber];
}

Graph::~Graph()
{
	delete[] adj;
}

void Graph::addEdge(int src, int dest)
{
	if (src >= numberOfNodes)
	{
		std::cout << "Source node id is out ouf bound" << std::endl;
		return;
	}
		
	if (dest >= numberOfNodes)
	{
		std::cout << "Destination node id is out ouf bound" << std::endl;
		return;
	}
		
	// It is an undirected graph
	adj[src].emplace_back(dest);
	adj[dest].emplace_back(src);
}

// A utility function to print the adjacenncy list representation of graph
void Graph::printGraph() const
{
	for (int v = 0; v < numberOfNodes; ++v)
	{
		std::cout << "\n Adjacency list of vertex " << v << " =>  ";
		for (auto it = adj[v].cbegin(); it != adj[v].cend(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

const std::list<int>* Graph::getNodeList() const
{
	return adj;
}

const int Graph::getNodeCount() const
{
	return numberOfNodes;
}
