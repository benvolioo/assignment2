#include <string>
#include <cmath>
struct Point{
    long long lon;
    long long lat;
}
long long manhattan(const Point& pt1, const Point& pt2)
{
    return abs(pt1.lon - pt2.lon) + abs(pt1.lat - pt2.lat);

}
Digraph* read_city_graph_undirected(sting filename, WDigraph& graph, unordered_map<int, Point>&points) 
{
    ifstream file(filename);
    string str;
    vector<int> pos;
    Point point;
    if(file.is_open())
    {
    	string::size_type sz;
    	while(getline(file, str))
    	{
    		if(str[0] == 'V')
    		{
    			size_t found = str.find(",");
    			size_t found1 = str.find(",", found+1);
                size_t found2 = str.find(",", found1+1);
    			string index1s = str.substr(found+1,(found1-1)-(found));
                string lats = str.substr(found1+1, (found2-1)- found1);
                string lons = str.substr(found2+1, (str.length()-1)-found2);
    			int index = stoi(index1s, &sz);
                int lat = stoi(lats);
                int lon = stoi(lons);
    			graph->addVertex(index);
                point.lon = lon*100000; 
                point.lat = lat*100000;
                points[index] = point;
    		}
    		else if(str[0] == 'E')
    		{
    			size_t found = str.find(",");
    			size_t found1 = str.find(",", found+1);
    			size_t found2 = str.find(",", found1+1);
    			string index1s = str.substr(found+1, (found1-1)-(found));
    			string index2s = str.substr(found1+1,(found2-1)-(found1));
    			int index1 = stoi(index1s, &sz);
    			int index2 = stoi(index2s, &sz);
    			graph->addEdge(index1, index2, manhattan(points[index1], points[index2]));
    		}

    	}

    }
    return graph;
}