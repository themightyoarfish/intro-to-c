#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>

#include "PathPlanner.hpp"

namespace asteroids
{

   vector<Vertex<float>> PathPlanner::getNavpoints()
   {
      return navPoints;
   }
   vector<graph_edge> PathPlanner::getEdgeList(const string mapfile, streampos& pos) const
   {
      ifstream file(mapfile);
      vector<graph_edge> edges; // this will hold all the edges
      if (file.good()) 
      {
         file.seekg(pos); // seek to beginning of edge definitions
         while (!file.eof()) // BUG: Last edge added twice
         {
            int u, v;
            file >> u >> v; // TODO: Some form of error checking is needed
            edges.push_back(make_pair(u,v));
         }
      }
      file.close();
      return edges;
   }

   vector<Vertex<float>> PathPlanner::getVertexList(const int& num, streampos& stream_pos, 
         const string& mapfile) 
   {
      vector<Vertex<float>> vertices;
      ifstream file(mapfile);
      if (file.good()) 
      {
         file.seekg(stream_pos); // first line after vertex number definition
         stringstream line_stream;
         string line, name;
         for (int i = 0; i < num ; i++) 
         {
            getline(file, line); // one vertex per line
            line_stream = stringstream(line); // wrap in stream to extract name and coordinates
            line_stream >> name;
            nameMap[name] = i; // save name and index
            indexMap[i] = name;
            float x, y, z;
            line_stream >> x >> y >> z;
            vertices.push_back(Vertex<float>(x,y,z));
         }
      } else cerr << "Error. Could not read file." << endl;
      stream_pos = file.tellg();
      file.close();
      return vertices;
   }


   void PathPlanner::printGraph() 
   {
      ofstream o("graph");
      if (o.good()) 
      {
         write_graphviz(o, g, default_writer(), edge_writer<WeightMap>(get(edge_weight, g)));
         o.close();
         system("neato -Tsvg graph > graph.svg"); // TODO: Error checking
      }
   }

   std::list<Vertex<float> > PathPlanner::getPath(Vertex<float> position, std::string s, std::string e)
   {
      // Taken from
      // http://www.boost.org/doc/libs/1_38_0/libs/graph/example/astar-cities.cpp
      // example
      vector<asteroids::Vertex_t> p(num_vertices);
      vector<cost> d(num_vertices);
      try 
      {
         // call astar named parameter interface
         astar_search
            (g, nameMap[s], // index of start vertex
             distance_astar_heuristic(nameMap[e], navPoints),
             predecessor_map(&p[0]).distance_map(&d[0]).visitor(astar_goal_visitor<Vertex_t>(nameMap[e])));


      } catch(found_goal f) 
      { // found a path to the goal
         list<Vertex<float>> shortest_path;
         list<string> shortest_path_names;
         for(Vertex_t v = nameMap[e];; v = p[v]) 
         {
            shortest_path.push_front(navPoints[v]);
            shortest_path_names.push_front(indexMap[v]);
            if(p[v] == v) break;
         }
         cout << "Path computed with vertices " << endl;
         int index = 0;
         for (list<Vertex<float>>::iterator it = shortest_path.begin() ; it != shortest_path.end() ; it++, index++) 
            cout << "\t" << indexMap[index] << endl;
         shortest_path.push_front(position);
         return shortest_path;
      }
   }


   PathPlanner::PathPlanner (string mapfile) 
   {
      ifstream file(mapfile);
      stringstream s;
      streampos pos;
      string line;
      if (file.good()) 
      {
         getline(file, line);
         stringstream s(line);
         s >> num_vertices;
         pos = file.tellg();
      }
      file.close();
      cout << "Number of vertices: " << num_vertices << endl;

      navPoints = getVertexList(num_vertices, pos, mapfile);
      edges = getEdgeList(mapfile, pos);
      for (int i = 0; i < edges.size(); i++) 
      {
         int u = edges[i].first;
         int v = edges[i].second;
         Edge_t e;
         bool b;
         tie(e,b) = add_edge(u, v, g);
         Vertex<float> diff = navPoints[u] - navPoints[v];
         weightmap[e] = sqrt(diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2]);
         cout << "Adding edge between " << indexMap[u] << "(" << u << ")" 
            << " and " << indexMap[v] << "(" << v << ")" << ", weight is " 
            << sqrt(diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2])
            << endl;
      }
      printGraph();
   }

}
