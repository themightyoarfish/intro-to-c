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

   typedef float cost;
   typedef adjacency_list< listS, vecS, undirectedS, no_property, property<edge_weight_t, cost > > MutableGraph;
   typedef property_map<MutableGraph, edge_weight_t>::type WeightMap;
   typedef property_map<MutableGraph, vertex_index_t>::type IndexMap;
   typedef MutableGraph::vertex_descriptor Vertex_t;
   typedef MutableGraph::vertex_iterator vertex_iterator;
   typedef MutableGraph::edge_descriptor Edge_t;
   typedef pair<unsigned int, unsigned int> graph_edge;

   /**
    * @struct found_goal
    * @brief 'Exception' to be thrown when the goal is found
    */
   struct found_goal
   {
      string s = "hooray!";
   };

   /**
    * @class astar_goal_visitor
    * @brief Visitor used during A* search
    */
   template<typename Vertex>
      class astar_goal_visitor : public default_astar_visitor
   {
      public:
         /**
          * @brief Construct the visitor
          * @param goal Vertex descriptor representing the goal
          */
         astar_goal_visitor(Vertex goal) : m_goal(goal) {}

         /**
          * @brief Called during the search when deciding whether a vertex is
          * part of the optimal path.
          * @param u The current vertex in the search.
          * @param g The graph containing it.
          * @throws found_goal type to indicate abortion of the search
          */
         void examine_vertex(Vertex u, const MutableGraph& g) {
            if(u == m_goal)
               throw found_goal();
         }
      private:
         Vertex m_goal; //< the goal vertex
   };

   /**
    * @class distance_astar_heuristic
    * @brief Functor to compute h(x) in astar search given vertex x
    */
   class distance_astar_heuristic : public astar_heuristic<MutableGraph, float>
   {
      public:
         /**
          * @brief Contruct the functor object
          * @param goal Vertex descriptor representing the goal
          * @param points Vector of all vertices to map descriptors to their
          * vectors.
          */
         distance_astar_heuristic(Vertex_t goal,vector<asteroids::Vertex<float>> points) : points(points), m_goal(goal) {}

         /**
          * @brief Compute distance heuristic for a vertex to the goal.
          * @param v Vertex descriptor for which the heuristic should be
          * computed.
          * @return The distance heuristic (euclidean distance to gaol)
          */
         float operator()(Vertex_t v)
         {
            asteroids::Vertex<float> diff = points[v] - points[m_goal];
            return sqrt(diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2]);
         }
      private:
         Vertex_t m_goal; //< the goal
         vector<asteroids::Vertex<float>> points; //< vector of all vertices
   };

   /**
    * @class edge_writer
    * @brief A class to use during graph-to-dot-writing so that edge costs
    * are printed
    */
   template <class WeightMap>
      class edge_writer {
         public:
            /**
             * @brief Construct an edge writer
             * @param w A boost::property_map to map edge descriptors to their
             * weights.
             */
            edge_writer(WeightMap w) : wm(w) {}

            /**
             * @brief Write the weight of the current edge to a stream
             * @param out The stream the dotfile is written to
             * @param e The current edge
             */
            template <class Edge> void operator()(ostream& out, const Edge& e) const 
            {
               out << "[label=\"" << wm[e] << "\"]"; // print in dot syntax
            }
         private:
            WeightMap wm;
      };


   /**
    * @class PathPlanner
    * @brief Class which can plan a shortest path in a weighted undirected
    * graph.
    */
   class PathPlanner {

      public:
         /**
          * @brief Construct a PathPlanner which reads from a file containing a
          * graph definition.
          * @param mapfile The file containing the vertices and edges
          */
         PathPlanner(string mapfile);

         /**
          * @brief Computes the shortest path from a start to a goal vertex
          * @param position The current fighter position
          * @param s The start vertex
          * @param e The goal vertex
          * @return A list with float Vectors being the shortest route.
          */
         list<Vertex<float> > getPath(Vertex<float> position, string s, string e);
         /**
          * @brief Get the list of all vertices in the graph
          * @return a Vector of all vertices in the graph in the form of float
          * Vetors.
          */
         vector<Vertex<float> > getNavpoints();

         /**
          * @brief Get the vector containing all edges as std::pairs of indices.
          * @param mapfile The file to read from
          * @param pos Position in the file at which edge definitions begin
          * @return A vector containing all edges
          */
         vector<graph_edge> getEdgeList(const string mapfile, streampos& pos) const;

         /**
          * @brief Print the graph to a dotfile
          */
         void printGraph();
      private:
         int num_vertices; //< number of vertices in graph
         vector<Vertex<float> > navPoints; //< vector if all vertices
         map<string, int> nameMap; //< Map to get index of nav point from name
         map<int, string> indexMap; //< Map to get name of nav point from index
         vector<graph_edge> edges; //< All graph edged
         MutableGraph g; //< The graph
         WeightMap weightmap = get(edge_weight, g); //< The map containing edge weights

         /**
          * @brief Compute and return all vertices in the graph after their
          * number has been determined.
          * @param num Number of vertices (read from the first line of the file)
          * @param stream_pos Position in the file after number has been read
          * (will be updated to faciliate subsequent edge reading)
          * @param mapfile The file containing the graph
          * @return The vector of all vertices
          */
         vector<Vertex<float>> getVertexList(const int& num, streampos& stream_pos, const string& mapfile);
   };
}

#endif
