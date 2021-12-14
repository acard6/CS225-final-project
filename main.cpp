#include "TestSuite.h"

int main(int argc, char *argv[])
{
    string airportData = "./data/airports.csv";
    string routeData = "./data/routes.csv";

    vector<Airport> vertices = ImportAirports(airportData);
    vector<Route> edges = ImportRoutes(routeData);

    // the small graph made for testing
    ADJList* graphList = smallADJList();
    vector<string> places = {"ORD","ATL","DFW","DEN","JFK","DTW","SFO","ORL","SLC","LAX"};
    for (size_t i=0; i<places.size(); i++){
        
        ADJList::edge* head = graphList->getList(places[i]).getHead();

        string name = head->destination.name;
        cout << name << endl;
    }


    if(argc >= 2)
    {
        string param(argv[1]);
        bool test = false;

        //Adjacency List arguments
        /*

        //Graph arguments
        if(param == "PlotFull")
        {
            PngMap pngMap(vertices);
            pngMap.createMap(edges, argv[2]);
        }

        if(param == "PlotN")
        {
            vector<Airport> subAirports;
            vector<Route> subRoutes;

            int n = stoi(argv[2]);
            for(int i = 0; i < n; ++i)
            {
                subAirports.push_back(vertices[i]);
                subRoutes.push_back(edges[i]);
            }

            PngMap pngMap(subAirports);
            pngMap.createMap(subRoutes, argv[3]);
        }
        */
        if(param == "BFS")
        {
            
            
            BFS traversal = BFS(graphList,vertices[1]);
            //Airport a1 = graphList.getList("Chicago O'Hare International Airport").getHead();
            /*
            ADJList::edgeList templ = graphList.getList("Chicago O'Hare International Airport");
            ADJList::edge* temp = templ.getHead();
            for(unsigned int i = 0;i<templ.getSize();i++){
                cout << temp->destination.name << " - " << temp->weight << endl;
                temp = temp->next;
            }
            */
            //BFS traversal = BFS(graphList,vertices[1]);
            
            vector<Airport> shortestpath = traversal.Shortest(graphList,vertices[12],vertices[48]);
            vector<Route> R;
            for(unsigned int i = 0;i<(shortestpath.size()-2);i++){
                R.push_back(Route(shortestpath[i].code,shortestpath[i+1].code,0));
            }

            PngMap pngMap(shortestpath);
            pngMap.createMap(R,"shortestpathtest.png");
        }

        //Test arguments
        if(param == "TestArgs") cout << "Test successful" << endl;
        if(param == "TestAirportImport") test = TestAirportImport(stoi(argv[2]), argv[3]);
        if(param == "TestRouteImport") test = TestRouteImport(stoi(argv[2]), argv[3]);
        if(param == "PngAirportComparison") test = PngAirportComparison(stoi(argv[2]));
        if(param == "PngRouteComparison") test = PngRouteComparison(stoi(argv[2]));

        if(test) cout << "TRUE" << endl;
        else cout << "FALSE" << endl;
    }

    return 0;
}