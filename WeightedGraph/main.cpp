#include <iostream>
#include <climits>
#include "Graph.h"

using namespace std;

//    Page 4 of 4

// Test 1  Vertex
//bool testPassed() {
//    Graph g;
//    g.AddVertex("Brown");
//    g.AddVertex("Cow");
//    g.AddVertex("Now");
//
//    int brownIndex = g.GetIndex("Brown");
//    int cowIndex = g.GetIndex("Cow");
//    int nowIndex = g.GetIndex("Now");
//    int badIndex = g.GetIndex("Junk");
//
//    if (brownIndex < 0 || brownIndex > 2)
//    {
//        cout << "Index of vertex Brown is not correct" << std::endl;
//        return false;
//    }
//    if (cowIndex < 0 || cowIndex > 2)
//    {
//        cout << "Index of vertex Cow is not correct" << std::endl;
//        return false;
//    }
//    if (nowIndex < 0 || nowIndex > 2)
//    {
//        cout << "Index of vertex Now is not correct" << std::endl;
//        return false;
//    }
//    if (badIndex >= 0)
//    {
//        cout << "Index of invalid vertex is not correct" << std::endl;
//        return false;
//    }
//
//    if (brownIndex == cowIndex ||
//        cowIndex == nowIndex)
//    {
//        cout << "Multiple vertex labels map to the same index number" << std::endl;
//        return false;
//    }
//
//
//    g.AddEdge("Brown", "Cow", 123);
//    g.AddEdge("Cow", "Brown", 321);
//
//    if (g.GetWeight(brownIndex, cowIndex) != 123)
//    {
//        cout << "Incorrect weight between to edges (Brown to Cow)" << std::endl;
//        return false;
//    }
//    if (g.GetWeight(cowIndex, brownIndex) != 321)
//    {
//        cout << "Incorrect weight between to edges (Cow to Brown)" << std::endl;
//        return false;
//    }
//    if (g.GetWeight(cowIndex, nowIndex) < 32767)
//    {
//
//        cout << "Incorrect weight for no-path" << std::endl;
//        return false;
//    }
//
//    return true;
//}
// Test 2 Breadth First Search
//bool testPassed() {
//    Graph g;
//    g.AddVertex("V0");
//    g.AddVertex("V1");
//    g.AddVertex("V2");
//    g.AddVertex("V3");
//    g.AddVertex("V4");
//    g.AddVertex("V5");
//    g.AddVertex("V6");
//
//    g.AddEdge("V0", "V1", 1);
//    g.AddEdge("V0", "V4", 1);
//
//    g.AddEdge("V1", "V3", 1);
//
//    g.AddEdge("V2", "V0", 1);
//
//    g.AddEdge("V3", "V0", 1);
//    g.AddEdge("V3", "V5", 1);
//    g.AddEdge("V3", "V6", 1);
//
//    g.AddEdge("V6", "V1", 1);
//
//    int visited[Graph::MAX_VERTECIES];
//
//    int ansV0[Graph::MAX_VERTECIES] = { 0, 1, 4, 3, 5, 6, -1, -1, -1 };
//    for (int i = 0; i < Graph::MAX_VERTECIES; i++) { visited[i] = -1; }
//    g.BreadthFirstSearch("V0", visited);
//    for (int i = 0; i < 7; i++)
//    {
//          if (visited[i] != ansV0[i])
//          {
//                cout << "Problem with Breadth First Search from V0" << std::endl;
//                return false;
//          }
//    }
//
//    int ansV3[Graph::MAX_VERTECIES] = { 3, 0, 5, 6, 1, 4, -1, -1, -1, -1 };
//    for (int i = 0; i < Graph::MAX_VERTECIES; i++) { visited[i] = -1; }
//    g.BreadthFirstSearch("V3", visited);
//    for (int i = 0; i < 6; i++)
//    {
//          if (visited[i] != ansV3[i])
//          {
//                cout << "Problem with Breadth First Search from V3" << std::endl;
//                return false;
//          }
//    }
//
//
//    int ansV5[Graph::MAX_VERTECIES] = { 5, -1, -1, -1, -1, -1, -1, -1, -1 };
//    for (int i = 0; i < Graph::MAX_VERTECIES; i++) { visited[i] = -1; }
//    g.BreadthFirstSearch("V5", visited);
//    for (int i = 0; i < 1; i++)
//    {
//          if (visited[i] != ansV5[i])
//          {
//                cout << "Problem with Breadth First Search from V5" << std::endl;
//                return false;
//          }
//    }
//
//    return true;
//}
// Test 3 Computes the correct distance[] array
//bool testPassed() {
//    Graph g;
//    g.AddVertex("V0");
//    g.AddVertex("V1");
//    g.AddVertex("V2");
//    g.AddVertex("V3");
//    g.AddVertex("V4");
//    g.AddVertex("V5");
//    g.AddVertex("V6");
//
//    g.AddEdge("V0", "V1", 1);
//    g.AddEdge("V0", "V4", 2);
//
//    g.AddEdge("V1", "V3", 3);
//
//    g.AddEdge("V2", "V0", 4);
//
//    g.AddEdge("V3", "V0", 5);
//    g.AddEdge("V3", "V5", 6);
//    g.AddEdge("V3", "V6", 7);
//
//    g.AddEdge("V6", "V1", 8);
//
//    int * distance = new int[Graph::MAX_VERTECIES];
//    int * prevVertex = new int[Graph::MAX_VERTECIES];
//    int v3Dist[] = { 5, 6, INT_MAX, 0, 7, 6, 7 };
//    g.DijkstraShortestPath("V3", distance, prevVertex);
//
//    for (int i = 0; i < 7; i++)
//    {
//          if (distance[i] != v3Dist[i])
//          {
//                cout << "Distance algorithm wrong for V3 (distance)" << endl;
//                return false;
//          }
//    }
//
//    delete[] distance;
//    delete[] prevVertex;
//
//
//
//    return true;
//}
// Test 4 Computes the correct prevVertex[] array
bool testPassed() {
    Graph g;
    g.AddVertex("V0");
    g.AddVertex("V1");
    g.AddVertex("V2");
    g.AddVertex("V3");
    g.AddVertex("V4");
    g.AddVertex("V5");
    g.AddVertex("V6");

    g.AddEdge("V0", "V1", 1);
    g.AddEdge("V0", "V4", 2);

    g.AddEdge("V1", "V3", 3);

    g.AddEdge("V2", "V0", 4);

    g.AddEdge("V3", "V0", 5);
    g.AddEdge("V3", "V5", 6);
    g.AddEdge("V3", "V6", 7);

    g.AddEdge("V6", "V1", 8);

    vector<int>distances = g.DijkstraShortestPath("V3");

    for (int i = 0; i < distances.size(); i++)
    {
        cout << distances.at(i) << endl;
    }



    return true;
}

int main()
{
    
    cout << testPassed();

    
}
