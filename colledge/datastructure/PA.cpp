#include <iostream>
using namespace std;

typedef struct node {
    int data;
    int chilcount = 0;
    struct node* children[10];
    int edgewight[10];
} node;

int mymax(int a, int b) {
    return (a > b) ? a : b;
}

struct Edge {
    int from;
    int to;
};

void swapEdge(Edge &a, Edge &b) {
    Edge t = a;
    a = b;
    b = t;
}

void sortEdges(Edge edges[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (edges[j].from < edges[i].from ||
               (edges[j].from == edges[i].from && edges[j].to < edges[i].to)) {
                swapEdge(edges[i], edges[j]);
            }
        }
    }
}

bool allvisited(bool visited[], int size) {
    for (int i = 0; i < size; ++i) {
        if (visited[i] == false) return false;
    }
    return true;
}

int main() {
    const int INF = 1000000000;
    int start;
    cin >> start;

    int now, next, weight;
    node nodes[1005];

    Edge edges[1005];
    int edgeCount = 0;

    int count = 0;    

    while (cin >> now >> next >> weight) {
        nodes[now].data = now;
        nodes[next].data = next;

        nodes[now].children[nodes[now].chilcount] = &nodes[next];
        nodes[now].edgewight[nodes[now].chilcount] = weight;
        nodes[now].chilcount++;

        nodes[next].children[nodes[next].chilcount] = &nodes[now];
        nodes[next].edgewight[nodes[next].chilcount] = weight;
        nodes[next].chilcount++;

        count = mymax(count, mymax(now, next));
    }

    int dist[1005];
    int father[1005];

    for (int i = 0; i < 1005; ++i) {
        dist[i] = INF;
    }

    int totaldist = 0;
    bool visited[1005] = {0};

    while (1) {
        node* cur = &nodes[start];

        for (int i = 0; i < cur->chilcount; ++i) {
            int v = cur->children[i]->data;
            int w = cur->edgewight[i];
            if (!visited[v]) {
                if (dist[v] > w) {
                    dist[v] = w;
                    father[v] = start;
                }
            }
        }

        visited[start] = true;
        dist[start] = INF;  

        int nxt = start;
        for (int i = 0; i <= count; ++i) {
            if (!visited[i] && dist[i] < dist[nxt]) {
                nxt = i;
            }
        }

        if (allvisited(visited, count + 1)) break;

        edges[edgeCount].from = father[nxt];
        edges[edgeCount].to = nxt;
        edgeCount++;

        start = nxt;
        totaldist += dist[start];
    }

    sortEdges(edges, edgeCount);

    for (int i = 0; i < edgeCount; ++i) {
        cout << "(" << edges[i].from << " " << edges[i].to << ") ";
    }
    cout << endl;
    cout << totaldist << endl;
}
