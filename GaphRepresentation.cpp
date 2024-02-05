#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<int> nodeOutEdges;
    vector<int> graphOutEdges;

public:
    void readGraph(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            int edgeCount = 0;
            int lastNode = -1;

            while (getline(file, line)) {
                istringstream iss(line);
                int from, to;

                if (iss >> from >> to) 
                {
                    if (from > lastNode) 
                    {
                        lastNode = from;

                        if (from >= nodeOutEdges.size()) 
                        {
                            nodeOutEdges.resize(from + 1, 0);
                        }

                        nodeOutEdges[from] = edgeCount;
                        
                    }

                    edgeCount++;
                    graphOutEdges.push_back(to);
                }
            }

         
            nodeOutEdges.at(0)=edgeCount-1;

            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    void displayGraphOutEdges() {
        cout << "graphOutEdges: ";
        for (int node : graphOutEdges) {
            cout << node << " ";
        }
        cout << endl;
    }

    void displayNodeOutEdges() {
        cout << "nodeOutEdges: ";
        for (int edge : nodeOutEdges) {
            cout << edge << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph graph;
    graph.readGraph("graph.txt");

    graph.displayGraphOutEdges();
    graph.displayNodeOutEdges();

    return 0;
}
