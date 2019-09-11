//
//  Graph.hpp
//  WeightedGraph
//
//  Created by Blake Williams on 8/2/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#include <iostream>
#include <queue>

class Graph{
public:
    Graph();
    ~Graph();
    
    void AddEdge(std::string source, std::string target, int weight);
    void AddVertex(std::string label);
    
    int GetIndex(std::string label) const; // -1 if label is not found
    int GetWeight (int sourceIndex, int targetIndex) const;
    
    bool IsEdge(int sourceIndex, int targetIndex) const;
    
    void GetAdjacent(std::queue<int>& queue, int visited[], int v) const;
    void BreadthFirstSearch(std::string startingVertex) const;
    void BreadthFirstSearch(std::string startingVertex, int visited[]) const;
    
    std::vector<int> DijkstraShortestPath (std::string startingVertex);
    
    void PrintGraph() const;
    
    static const int MAX_VERTECIES = 10;
    
private:
    
    int matrix [MAX_VERTECIES][MAX_VERTECIES];
    std::string labels [MAX_VERTECIES];
    
};

#endif /* Graph_hpp */
