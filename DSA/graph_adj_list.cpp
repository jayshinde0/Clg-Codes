#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int dest;   // Destination city index
    int time;   // Time in hours
    int fuel;   // Fuel in liters
    Node *next; // Pointer to next flight

    // Constructor
    Node(int d, int t, int f)
    {
        dest = d;
        time = t;
        fuel = f;
        next = nullptr;
    }
};

class Graph
{
    string cities[10];
    int n, m;
    Node *adj[10];

public:
    Graph()
    {
        n = m = 0;
        for (int i = 0; i < 10; i++)
            adj[i] = nullptr;
    }

    // Utility to add flight
    void addFlight(int src, int dest, int time, int fuel)
    {
        Node *newNode = new Node(dest, time, fuel);

        if (adj[src] == nullptr)
        {
            adj[src] = newNode;
        }
        else
        {
            Node *temp = adj[src];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // 1. Read Flight Data
    void read()
    {
        cout << "\nEnter number of cities: ";
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            cout << "City " << i + 1 << ": ";
            getline(cin, cities[i]);
        }

        cout << "\nEnter number of flights: ";
        cin >> m;
        cout << "\nEnter Source Destination Time Fuel (City numbers start from 1):\n";
        for (int i = 0; i < m; i++)
        {
            int src, dest, time, fuel;
            cout << "Flight " << i + 1 << ": ";
            cin >> src >> dest >> time >> fuel;
            src--;
            dest--;
            addFlight(src, dest, time, fuel);
        }
    }

    // 2. Display adjacency list for Time
    void displayTimeList()
    {
        cout << "\nAdjacency List (Time in hrs):\n";
        for (int i = 0; i < n; i++)
        {
            cout << cities[i] << " -> ";
            Node *temp = adj[i];
            while (temp != nullptr)
            {
                cout << "[" << cities[temp->dest] << ", Time: " << temp->time << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    // 3. Display adjacency list for Fuel
    void displayFuelList()
    {
        cout << "\nAdjacency List (Fuel in L):\n";
        for (int i = 0; i < n; i++)
        {
            cout << cities[i] << " -> ";
            Node *temp = adj[i];
            while (temp != nullptr)
            {
                cout << "[" << cities[temp->dest] << ", Fuel: " << temp->fuel << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    // 4. Check if direct flight exists
    void checkDirectFlight()
    {
        int src, dest;
        cout << "Enter source city number: ";
        cin >> src;
        cout << "Enter destination city number: ";
        cin >> dest;
        src--;
        dest--;

        Node *temp = adj[src];
        while (temp != nullptr)
        {
            if (temp->dest == dest)
            {
                cout << "Direct flight exists from " << cities[src]
                     << " to " << cities[dest] << "\n";
                cout << "Time: " << temp->time
                     << " hrs, Fuel: " << temp->fuel << " L\n";
                return;
            }
            temp = temp->next;
        }
        cout << "No direct flight exists between these cities.\n";
    }

    // 5. Display all available flights
    void displayFlights()
    {
        cout << "\nAvailable Flights:\n";
        for (int i = 0; i < n; i++)
        {
            Node *temp = adj[i];
            while (temp != nullptr)
            {
                cout << cities[i] << " -> " << cities[temp->dest]
                     << " | Time: " << temp->time
                     << " hrs, Fuel: " << temp->fuel << " L\n";
                temp = temp->next;
            }
        }
    }

    // 6. Count total flights from a city
    void countFlightsFromCity()
    {
        int city;
        cout << "Enter city number: ";
        cin >> city;
        city--;

        int count = 0;
        Node *temp = adj[city];
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        cout << "Total flights from " << cities[city] << ": " << count << "\n";
    }

    // 7. Find all reachable cities from a source with cost
    void findReachableCities()
    {
        int src;
        cout << "Enter source city number: ";
        cin >> src;
        src--;

        cout << "Cities reachable from " << cities[src] << ":\n";
        Node *temp = adj[src];
        while (temp != nullptr)
        {
            cout << cities[temp->dest] << " | Time: " << temp->time
                 << " hrs, Fuel: " << temp->fuel << " L\n";
            temp = temp->next;
        }
    }

    // 8 indirect path
    bool dfsUtil(int u, int dest, bool visited[])
    {
        if (u == dest)
            return true; // destination reached
        visited[u] = true;

        Node *temp = adj[u];
        while (temp != nullptr)
        {
            if (!visited[temp->dest])
            {
                if (dfsUtil(temp->dest, dest, visited))
                    return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void checkIndirectFlightDFS()
    {
        int src, dest;
        cout << "Enter source city number: ";
        cin >> src;
        cout << "Enter destination city number: ";
        cin >> dest;
        src--;
        dest--;

        
        
        bool visited[10] = {false};


        if (dfsUtil(src, dest, visited))
            cout << "Indirect flight exists from " << cities[src]
                 << " to " << cities[dest] << "\n";
        else
            cout << "No indirect flight exists between these cities.\n";
    }
};

int main()
{
    Graph g;
    int ch;
    do
    {
        cout << "\nMenu:";
        cout << "\n1. Read Flight Data";
        cout << "\n2. Display Time List";
        cout << "\n3. Display Fuel List";
        cout << "\n4. Check if Direct Flight Exists from A to B (with Time & Fuel)";
        cout << "\n5. Display All Available Flights (with Time & Fuel)";
        cout << "\n6. Count Total Flights from a City";
        cout << "\n7. Find All Reachable Cities from a Source (with Cost)";
        cout << "\n8. Check if Indirect Flight Exists (DFS)";
        cout << "\n9. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            g.read();
            break;
        case 2:
            g.displayTimeList();
            break;
        case 3:
            g.displayFuelList();
            break;
        case 4:
            g.checkDirectFlight();
            break;
        case 5:
            g.displayFlights();
            break;
        case 6:
            g.countFlightsFromCity();
            break;
        case 7:
            g.findReachableCities();
            break;
        case 8:
            g.checkIndirectFlightDFS();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (ch != 9);

    return 0;
}
