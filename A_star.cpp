#include<bits/stdc++.h>
using namespace std;

map<char, vector<pair<char,int>>> g;
map<char,int> h;

struct Node
{
    char v;
    int cost;

    bool operator<(const Node& o) const
    {
        return cost > o.cost;
    }
};

int main()
{
    g['A']={{'B',1},{'C',3}};
    g['B']={{'D',3},{'E',1}};
    g['E']={{'G',2}};

    h['A']=6;
    h['B']=4;
    h['C']=4;
    h['D']=3;
    h['E']=2;
    h['G']=0;

    priority_queue<Node> pq;

    pq.push({'A',h['A']});

    while(!pq.empty())
    {
        Node cur=pq.top();
        pq.pop();

        cout<<cur.v<<" ";

        if(cur.v=='G')
            break;

        for(auto x:g[cur.v])
        {
            pq.push({x.first,x.second+h[x.first]});   //f(n) = edge cost + heuristic
        }
    }

    return 0;
}
// is it okay for the 
// Implement A star Algorithm for any game search problem.


// Yes, this code is okay ✅ for:

// “Implement A Algorithm for any game search problem.”*

// It demonstrates:

// Graph traversal
// Heuristic function h(n)
// Priority queue
// Best node selection using minimum cost

// Your code uses:

// f(n) = edge cost + heuristic

// and searches path:

// A → B → E → G
// Viva Points
// A* uses heuristic search
// g(n) = path cost
// h(n) = estimated cost to goal
// f(n) = g(n) + h(n)
// Priority queue selects minimum cost node
// Used in games and shortest path problems
// Small Note

// Your code is a simplified A* version because it does not store full accumulated g(n) path cost separately.
// But for practical/viva and simple game search demonstration, it is acceptable.

// mple game search
// which use in above code

// The above code represents a simple path finding game search.

// Example game scenario:

// A = Start Position
// G = Goal/Target
// B,C,D,E = Intermediate positions

// A* searches the best path from:

// A → G

// using minimum estimated cost.

// Example Use in Games
// Maze solving
// Treasure hunt game
// Robot movement
// Chess/map movement
// Finding shortest route in game world
// In Your Code
// A → Player Start
// G → Destination

// Possible paths:

// A → B → E → G
// A → C
// A → B → D

// A* chooses:

// A → B → E → G

// because it has lowest estimated cost.