#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>

#include "PathPlanner.hpp"

namespace asteroids
{

    vector<graph_edge> PathPlanner::getEdgeList(const string mapfile, streampos& pos) const
    {
       ifstream file(mapfile);
       vector<graph_edge> edges;
       if (file.good()) 
       {
          file.seekg(pos);
          while (!file.eof()) 
          {
             int u, v;
             file >> u >> v;
             edges.push_back(make_pair(u,v));
          }
       }
       file.close();
       return edges;
    }
    vector<Vertex<float>> PathPlanner::getVertexList(const int& num, streampos& stream_pos, 
         const string& mapfile, 
         map<string,int>& landmarks) const
   {
      vector<Vertex<float>> vertices;
      ifstream file(mapfile);
      if (file.good()) 
      {
         file.seekg(stream_pos);
         stringstream s;
         string line, name;
         for (int i = 0; i < num ; i++) 
         {
            getline(file, line);
            s = stringstream(line);
            s >> name;
            landmarks[name] = i;
            float x, y, z;
            s >> x >> y >> z;
            /* cout << name << ": " << x << ", " << y << ", " << z << endl; */
            vertices.push_back(Vertex<float>(x,y,z));
         }
      } else cerr << "Error. Could not read file." << endl;
      stream_pos = file.tellg();
      file.close();
      return vertices;
   }


    void PathPlanner::printGraph() const
    {
      ofstream o("graph");
      write_graphviz(o, g, default_writer(), make_edge_writer(get(edge_weight, g)));
      o.close();
      system("neato -Tsvg graph > graph.svg");
    }

   std::list<Vertex<float> > PathPlanner::getPath(Vertex<float> position, std::string s, std::string e)
   {
      // TODO: Replace return statement and search a solution path
      return std::list<Vertex<float> >();
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

      navPoints = getVertexList(num_vertices, pos, mapfile, nameMap);
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
         cout << "adding edge between " << u << " and " << v << ", weight is " << sqrt(diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2])<< endl;
      }
      printGraph();
      /* for(list<Vertex<float>>::iterator b = navPoints.begin(); b != navPoints.end(); b++) */
      /*    cout << (*b)[0] << ", " << (*b)[1] << ", " << (*b)[2] << endl; */
   }

}
