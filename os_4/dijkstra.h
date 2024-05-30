#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>

extern int V;

int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet, int V);
void printSolution(const std::vector<int>& dist, int V);
void dijkstra(const std::vector<std::vector<int>>& graph, int src, int V);
void run_dijkstra();
#endif // DIJKSTRA_H