#include "Graph.h"
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

Graph::Graph(Graph& other)
{
	numberOfNodes = other.numberOfNodes;
	copyListFrom(other);
}

Graph::Graph(Graph&& other)
{
	numberOfNodes = other.numberOfNodes;
	adj           = other.adj;

	other.adj     = nullptr;
}

Graph& Graph::operator=(Graph& other)
{
	if (this != &other)
	{
		numberOfNodes = other.numberOfNodes;
		copyListFrom(other);
	}
	return *this;
}

Graph& Graph::operator=(Graph&& other)
{
	if (this != &other)
	{
		numberOfNodes = other.numberOfNodes;
		adj           = other.adj;

		other.adj     = nullptr;
	}
	return *this;
}

void Graph::copyListFrom(Graph& other)
{
	adj = new std::list<int>[other.numberOfNodes];

	auto fromList = other.getNodeList();
	for (int i = 0; i < other.numberOfNodes; ++i)
	{
		for (auto it = fromList[i].cbegin(); it != fromList[i].cend(); ++it)
			adj[i].emplace_back(*it);
	}
}

void Graph::addEdge(int src, int dest)
{
	if (src >= numberOfNodes)
	{
		std::cout << "Node: " << src << " Source node id is out ouf bound" << std::endl;
		return;
	}
		
	if (dest >= numberOfNodes)
	{
		std::cout << "Node: " << dest << " Destination node id is out ouf bound" << std::endl;
		return;
	}
		
	// It is an undirected graph
	adj[src].emplace_back(dest);
	adj[dest].emplace_back(src);
}

// A utility function to print the adjacenncy list representation of graph
void Graph::printGraph() const
{
	std::string commonStr      = "Adjacency list of vertex ";
	std::string commonStrArrow = " => ";
	std::string commonStrEmpty = " ";
	for (int v = 0; v < numberOfNodes; ++v)
	{
		std::cout << commonStr.c_str() << v << commonStrArrow.c_str();
		for (auto it = adj[v].cbegin(); it != adj[v].cend(); ++it)
		{
			std::cout << *it << commonStrEmpty.c_str();
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
