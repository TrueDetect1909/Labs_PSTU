#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>
#include <Windows.h>
const int NotUsed = system("color 80");
using namespace std;

struct Edge {
    int to;
    int weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

class Graph {
private:
    vector<vector<Edge>> adjList;
    vector<int> distances;
    vector<int> parents;
    int numVertices;
    sf::RenderWindow window;

public:
    Graph(int numVertices) : numVertices(numVertices) {
        adjList.resize(numVertices);

    }

    void addEdge(int from, int to, int weight) {
        adjList[from].push_back(Edge(to, weight));
    }

    void bfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        q.push(startVertex);
        visited[startVertex] = true;
        while (!q.empty()) {
            int currVertex = q.front();
            q.pop();
            cout << currVertex << " ";
            for (auto edge : adjList[currVertex]) {
                int neighbor = edge.to;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void dfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> s;
        s.push(startVertex);
        visited[startVertex] = true;
        while (!s.empty()) {
            int currVertex = s.top();
            s.pop();
            cout << currVertex << " ";
            for (auto edge : adjList[currVertex]) {
                int neighbor = edge.to;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void dijkstra(int startVertex) {
        distances.assign(numVertices, numeric_limits<int>::max());
        parents.assign(numVertices, -1);
        vector<bool> visited(numVertices, false);
        distances[startVertex] = 0;
        for (int i = 0; i < numVertices - 1; i++) {
            int currVertex = -1;
            for (int j = 0; j < numVertices; j++) {
                if (!visited[j] && (currVertex == -1 || distances[j] < distances[currVertex])) {
                    currVertex = j;
                }
            }
            visited[currVertex] = true;
            for (auto edge : adjList[currVertex]) {
                int neighbor = edge.to;
                int weight = edge.weight;
                if (distances[currVertex] + weight < distances[neighbor]) {
                    distances[neighbor] = distances[currVertex] + weight;
                    parents[neighbor] = currVertex;
                }
            }
        }
        for (int i = 0; i < numVertices; i++) {
            cout << "Distance from " << startVertex << " to " << i << " is " << distances[i] << endl;
        }
    }

    void addVertex() {
        numVertices++;
        adjList.resize(numVertices);
    }

    void removeVertex(int vertex) {
        numVertices--;
        adjList.erase(adjList.begin() + vertex);
        for (auto& adj : adjList) {
            for (auto& edge : adj) {
                if (edge.to == vertex) {
                    edge.to = -1;
                }
                else if (edge.to > vertex) {
                    edge.to--;
                }
            }
        }
    }

    void addEdge(int from, int to) {
        addEdge(from, to, 1);
    }

    void removeEdge(int from, int to) {
        for (auto& edge : adjList[from]) {
            if (edge.to == to) {
                edge.to = -1;
            }
        }
    }

    void editEdgeWeight(int from, int to, int weight) {
        for (auto& edge : adjList[from]) {
            if (edge.to == to) {
                edge.weight = weight;
            }
        }
    }

    void editAdjacencyMatrix(int** matrix, int size) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (matrix[i][j] != -1) {
                    if (i >= size || j >= size) {
                        removeEdge(i, j);
                    }
                    else {
                        editEdgeWeight(i, j, matrix[i][j]);
                    }
                }
                else if (i < size && j < size) {
                    addEdge(i, j, matrix[i][j]);
                }
            }
        }
    }

    void addNewVertex() {
        addVertex();
        cout << "Added new vertex " << numVertices - 1 << endl;
    }

    void removeExistingVertex() {
        int vertex;
        cout << "Enter vertex to remove: ";
        cin >> vertex;
        if (vertex < 0 || vertex >= numVertices) {
            cout << "Invalid vertex" << endl;
            return;
        }
        removeVertex(vertex);
        cout << "Removed vertex " << vertex << endl;
    }

    void addNewEdge() {
        int from, to, weight;
        cout << "Enter source vertex: ";
        cin >> from;
        cout << "Enter destination vertex: ";
        cin >> to;
        cout << "Enter weight: ";
        cin >> weight;
        if (from < 0 || from >= numVertices || to < 0 || to >= numVertices) {
            cout << "Invalid vertices" << endl;
            return;
        }
        addEdge(from, to, weight);
        cout << "Added edge from " << from << " to " << to << " with weight " << weight << endl;
    }

    void removeExistingEdge() {
        int from, to;
        cout << "Enter source vertex: ";
        cin >> from;
        cout << "Enter destination vertex: ";
        cin >> to;
        if (from < 0 || from >= numVertices || to < 0 || to >= numVertices) {
            cout << "Invalid vertices" << endl;
            return;
        }
        removeEdge(from, to);
        cout << "Removed edge from " << from << " to " << to << endl;
    }

    void editEdge() {
        int from, to, weight;
        cout << "Enter source vertex: ";
        cin >> from;
        cout << "Enter destination vertex: ";
        cin >> to;
        cout << "Enter new weight: ";
        cin >> weight;
        if (from < 0 || from >= numVertices || to < 0 || to >= numVertices) {
            cout << "Invalid vertices" << endl;
            return;
        }
        editEdgeWeight(from, to, weight);
        cout << "Changed weight of edge from " << from << " to " << to << " to " << weight << endl;
    }

    void printGraph() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Graph");
        window.setFramerateLimit(60);
        sf::Color myColor(255, 162, 64);
        sf::Color myColor2(2, 78, 104);
        window.clear(myColor);
        cout << "Graph:" << endl;
        sf::Font font;
        font.loadFromFile("Barlow-Medium.ttf");
        vector<sf::CircleShape> vertices(numVertices);
        vector<sf::Text> texts(numVertices);
        vector<vector<sf::Vertex>> edges(numVertices, vector<sf::Vertex>());
        for (int i = 0; i < numVertices; i++) {
            vertices[i].setRadius(20);
            vertices[i].setPosition(sf::Vector2f(rand() % 700 + 50, rand() % 500 + 50));
            vertices[i].setOutlineThickness(3);
            vertices[i].setOutlineColor(myColor2);
            vertices[i].setFillColor(myColor);
            texts[i].setFont(font);
            texts[i].setString(to_string(i));
            texts[i].setCharacterSize(20);
            texts[i].setFillColor(myColor2);
            texts[i].setPosition(sf::Vector2f(vertices[i].getPosition().x + 15, vertices[i].getPosition().y + 5));
            window.draw(vertices[i]);
            window.draw(texts[i]);
            for (auto edge : adjList[i]) {
                if (edge.to != -1) {
                    sf::Vector2f from(vertices[i].getPosition().x + 20, vertices[i].getPosition().y + 20);
                    sf::Vector2f to(vertices[edge.to].getPosition().x + 20, vertices[edge.to].getPosition().y + 20);
                    sf::Vertex line[] = {
                        sf::Vertex(from,myColor2),
                        sf::Vertex(to,myColor2)
                    };
                    edges[i].push_back(line[0]);
                    edges[i].push_back(line[1]);
                    window.draw(line, 2, sf::Lines);
                    float angle = atan2(to.y - from.y, to.x - from.x);
                    sf::Vector2f arrowheadPos(to.x - 20 * cos(angle), to.y - 20 * sin(angle));
                    const float PI = 3.14159265f;
                    sf::Vertex arrowhead[] = {
                        sf::Vertex(arrowheadPos,sf::Color::Black),
                        sf::Vertex(sf::Vector2f(arrowheadPos.x - 20 * cos(angle + PI / 6),arrowheadPos.y - 20 * sin(angle + PI / 6)),myColor2),
                        sf::Vertex(sf::Vector2f(arrowheadPos.x - 20 * cos(angle - PI / 6),arrowheadPos.y - 20 * sin(angle - PI / 6)),myColor2)
                    };
                    window.draw(arrowhead, 3, sf::Triangles);

                    sf::Text weightText;
                    weightText.setFont(font);
                    weightText.setString(to_string(edge.weight));
                    weightText.setCharacterSize(20);
                    weightText.setFillColor(myColor2);
                    weightText.setPosition(sf::Vector2f((from.x + to.x) / 2, (from.y + to.y) / 2));
                    window.draw(weightText);
                }
            }
        }
        window.display();
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        for (int i = 0; i < numVertices; i++) {
                            if (vertices[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                                sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                                sf::Vector2f offset = mousePos - vertices[i].getPosition();
                                while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                                    mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
                                    vertices[i].setPosition(mousePos - offset);
                                    texts[i].setPosition(sf::Vector2f(vertices[i].getPosition().x + 15, vertices[i].getPosition().y + 5));
                                    window.clear(myColor);
                                    for (int i = 0; i < numVertices; i++) {
                                        for (auto edge : adjList[i]) {
                                            if (edge.to != -1) {
                                                sf::Vector2f from(vertices[i].getPosition().x + 20, vertices[i].getPosition().y + 20);
                                                sf::Vector2f to(vertices[edge.to].getPosition().x + 20, vertices[edge.to].getPosition().y + 20);
                                                sf::Vertex line[] = {
                                                    sf::Vertex(from,myColor2),
                                                    sf::Vertex(to,myColor2)
                                                };
                                                edges[i].push_back(line[0]);
                                                edges[i].push_back(line[1]);
                                                window.draw(line, 2, sf::Lines);
                                                float angle = atan2(to.y - from.y, to.x - from.x);
                                                sf::Vector2f arrowheadPos(to.x - 20 * cos(angle), to.y - 20 * sin(angle));
                                                const float PI = 3.14159265f;
                                                sf::Vertex arrowhead[] = {
                                                    sf::Vertex(arrowheadPos,myColor2),
                                                    sf::Vertex(sf::Vector2f(arrowheadPos.x - 20 * cos(angle + PI / 6),arrowheadPos.y - 20 * sin(angle + PI / 6)),myColor2),
                                                    sf::Vertex(sf::Vector2f(arrowheadPos.x - 20 * cos(angle - PI / 6),arrowheadPos.y - 20 * sin(angle - PI / 6)),myColor2)
                                                };
                                                window.draw(arrowhead, 3, sf::Triangles);
                                                sf::Text weightText;
                                                weightText.setFont(font);
                                                weightText.setString(to_string(edge.weight));
                                                weightText.setCharacterSize(20);
                                                weightText.setFillColor(myColor2);
                                                weightText.setPosition(sf::Vector2f((from.x + to.x) / 2, (from.y + to.y) / 2));
                                                window.draw(weightText);
                                            }
                                        }
                                        window.draw(vertices[i]);
                                        window.draw(texts[i]);
                                    }
                                    window.display();
                                }
                                break;
                            }
                        }
                    }
                }
                else if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {

                    }
                }
            }
        }
    }

};

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo = { sizeof(fontInfo) };
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    fontInfo.dwFontSize.Y = 24;
    wcscpy_s(fontInfo.FaceName, L"Bahnschrift");

    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    int numVertices;
    cout << "Enter number of vertices: ";
    cin >> numVertices;
    Graph g(numVertices);
    int choice;
    do {
        cout << "1. Add vertex" << endl;
        cout << "2. Remove vertex" << endl;
        cout << "3. Add edge" << endl;
        cout << "4. Remove edge" << endl;
        cout << "5. Edit edge weight" << endl;
        cout << "6. Print graph" << endl;
        cout << "7. BFS" << endl;
        cout << "8. DFS" << endl;
        cout << "9. Dijkstra" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            g.addNewVertex();
            break;
        case 2:
            g.removeExistingVertex();
            break;
        case 3:
            g.addNewEdge();
            break;
        case 4:
            g.removeExistingEdge();
            break;
        case 5:
            g.editEdge();
            break;
        case 6:
            g.printGraph();
            break;
        case 7:
            int bfsStart;
            cout << "Enter starting vertex: ";
            cin >> bfsStart;
            g.bfs(bfsStart);
            break;
        case 8:
            int dfsStart;
            cout << "Enter starting vertex: ";
            cin >> dfsStart;
            g.dfs(dfsStart);
            break;
        case 9:
            int dijkstraStart;
            cout << "Enter starting vertex: ";
            cin >> dijkstraStart;
            g.dijkstra(dijkstraStart);
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}
