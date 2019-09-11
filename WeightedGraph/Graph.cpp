//
//  Graph.cpp
//  WeightedGraph
//
//  Created by Blake Williams on 8/2/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#include "Graph.h"
#include <climits>
#include <queue>
#include <vector>

Graph::Graph(){
    for (int i=0;i<MAX_VERTECIES;i++){
        labels[i] = "NULL";
        for (int j=0;j<MAX_VERTECIES;j++){
            matrix[i][j] = INT_MAX;
        }
    }
}

Graph::~Graph(){
    
}

void Graph::AddEdge(std::string source, std::string target, int weight){
    for (int i=0;i<MAX_VERTECIES;i++){
        if (labels[i] == source){
            for (int j=0;j<MAX_VERTECIES;j++){
                if (labels[j] == target){
                    matrix[i][j] = weight;
                    break;
                }
            }
            break;
        }
    }
}

void Graph::AddVertex(std::string label){
    for (int i=0;i<MAX_VERTECIES;i++){
        if (labels[i] == "NULL"){
            labels[i] = label;
            break;
        }
    }
}

int Graph::GetIndex(std::string label) const{       // -1 if label is not found
    for (int i=0;i<MAX_VERTECIES;i++){
        if (labels[i] == label){
            return i;
        }
    }
    return -1;
}

int Graph::GetWeight (int sourceIndex, int targetIndex) const{
    return matrix[sourceIndex][targetIndex];
}

bool Graph::IsEdge(int sourceIndex, int targetIndex) const{
    if (matrix[sourceIndex][targetIndex] != INT_MAX){
        return true;
    }
    return false;
}

void Graph::GetAdjacent(std::queue<int>& queue, int visited[], int v) const{
    for (int i=0;i<MAX_VERTECIES;i++){
        if (matrix[v][i] != INT_MAX){
            bool vis = false;
            for (int j=0;j<MAX_VERTECIES;j++){
                if (visited[j] == i){
                    vis = true;
                    break;
                }
            }
            if (!vis){
                queue.push(i);
            }
        }
    }
}

void Graph::BreadthFirstSearch(std::string startingVertex) const{
    std::cout << "Starting BFS with vertex" << startingVertex << std::endl;
    
    int visited[MAX_VERTECIES] = {-1};
    std::queue<int>queue;
    queue.push(GetIndex(startingVertex));
    int i = 0;
    
    while(!queue.empty()){
        int v = queue.front();
        queue.pop();
        std::cout << "visited: " << v << std::endl;
        visited[i++] = v;
        
        GetAdjacent(queue, visited, v);
    }
    std::cout << std::endl;
}

void Graph::BreadthFirstSearch(std::string startingVertex, int visited[]) const{
    std::cout << "Starting BFS with vertex" << startingVertex << std::endl;
    // make a list of vertex indecies that are adjacent to startingVertex
    // while the list is not empty:
    // dequeue the first vertex, add it to the visited and print it
    // add the adjacency list of the dequeued vertex to the back of the queue
    
    // when making an adjacency list, never add an index that is in the visited list
    
    std::queue<int>queue;
    queue.push(GetIndex(startingVertex));
    int i = 0;
    
    while(!queue.empty()){
        int v = queue.front();
        queue.pop();
        std::cout << "visited: " << v << std::endl;
        visited[i++] = v;
        
        GetAdjacent(queue, visited, v);
    }
    std::cout << std::endl;
}


std::vector<int> Graph::DijkstraShortestPath (std::string startingVertex){
    // initialize a list of distances to INT_MAX
    // set the distance to the starting node to 0
    // initialize a list of visited nodes to false
    // set the current visited index to true
    
    // while not all the nodes have been visited,
    // choose the node with the smallest distance which has not been visited
    // cycle through the list of adjacents and update their distances
    
    std::vector<int>distances;
    std::vector<bool>visited;
    
    for (int i=0;i<MAX_VERTECIES;i++){
        if (labels[i] != "NULL"){
            distances.push_back(INT_MAX);
            visited.push_back(false);
        }
    }
    
    int currIdx = GetIndex(startingVertex);
    distances.at(currIdx) = 0;
    int minDis = INT_MAX;
    int minIdx = currIdx;
    
    while (minIdx != -1){      // not all visited
        minDis = INT_MAX;
        minIdx = -1;
        
        for (int i=0;i<visited.size();i++){         // find the next node to choose
            if (!visited.at(i) && distances.at(i) < minDis){
                minDis = distances.at(i);
                minIdx = i;
            }
        }
        
        if (minIdx != -1){
            currIdx = minIdx;
            visited.at(currIdx) = true;
            std::vector<int>adjacents;
        
            for (int i=0;i<MAX_VERTECIES;i++){
                if (matrix[currIdx][i] != INT_MAX){     // found connection
                    if (distances.at(currIdx) + matrix[currIdx][i] < distances.at(i)){      // update distance to i
                        distances.at(i) = distances.at(currIdx) + matrix[currIdx][i];
                    }
                }
            }
        }
    }
    return distances;
}

void Graph::PrintGraph() const{
    int i=0;
    for (;i<MAX_VERTECIES;i++){
        if (labels[i] == "NULL")
            break;
    }
    std::cout << "numVertices: " << i << std::endl;
}

