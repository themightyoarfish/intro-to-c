#ifndef PATH_H_
#define PATH_H_

#include <string>
#include <list>
#include "math/Vertex.hpp"

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphml.hpp>
#include <boost/graph/astar_search.hpp>


namespace asteroids
{

using namespace boost;
using namespace std;

typedef struct {
    string name;
    int x;
    int y;
    int z;
} nodeentry;

typedef struct {
    unsigned int from;
    unsigned int to;
} edgeentry;


typedef float cost;
typedef adjacency_list< listS, vecS, undirectedS, no_property, property<edge_weight_t, cost > > MutableGraph;
typedef property_map<MutableGraph, edge_weight_t>::type WeightMap;
typedef property_map<MutableGraph, vertex_index_t>::type IndexMap;
typedef MutableGraph::vertex_descriptor Vertex_t;
typedef MutableGraph::vertex_iterator vertex_iterator;
typedef MutableGraph::edge_descriptor Edge_t;
typedef pair<unsigned int, unsigned int> graph_edge;

struct location {
    location() {}
    location(float lat, float lon) : y(lat), x(lon) {}
    float y, x;
};

class distance_astar_heuristic : public astar_heuristic<MutableGraph, float>
{
   public:
      distance_astar_heuristic(Vertex_t goal,vector<asteroids::Vertex<float>> points) : points(points), m_goal(goal) {}
      float operator()(Vertex_t v)
      {
         asteroids::Vertex<float> diff = points[v] - points[m_goal];
         return sqrt(diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2]);
      }
   private:
      Vertex_t m_goal;
      vector<asteroids::Vertex<float>> points;
};


class PathPlanner {
   public:
      PathPlanner(string mapfile);
      list<Vertex<float> > getPath(Vertex<float> position, string s, string e);
      vector<Vertex<float> > getNavpoints();
      vector<Vertex<float>> getVertexList(const int& num, streampos& stream_pos, const string& mapfile, map<string,int>& nameMap) const;
      vector<graph_edge> getEdgeList(const string mapfile, streampos& pos) const;
   private:
      int num_vertices;
      vector<int> costs;
      list<Vertex<float> > solutionpath;
      vector<Vertex<float> > navPoints;
      map<string, int> nameMap;
      vector<graph_edge> edges;

      nodeentry* nodes;
      MutableGraph g;
      WeightMap weightmap = get(edge_weight, g);
};
}

#endif
