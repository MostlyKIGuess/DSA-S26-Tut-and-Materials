#import "@preview/polylux:0.4.0": *
#import "@preview/metropolis-polylux:0.1.0" as metropolis
#import metropolis: new-section, focus

#show: metropolis.setup

#show link: set text(fill: blue)

#slide[
  #set page(header: none, footer: none, margin: 3em)

  #text(size: 1.3em)[
    *AVL Trees and Intro to Graphs *
  ]

  Data Structures and Algorithms Tutorial

  #metropolis.divider

  #set text(size: .8em, weight: "light")
  IIITH - S26

  #v(1em)
  _AVL Trees, Graphs (C++)_
]

#slide[
  = Agenda

  #metropolis.outline
]

#new-section[AVL Trees]

#slide[
  = What is an AVL Tree?

  *Definition*
  - Self-balancing BST invented by Adelson-Velsky and Landis (1962)
  - Balance factor: `height(left) - height(right)`
  - For EVERY node: `|balance factor| <= 1`

  *Why AVL?*
  - Regular BST can degenerate to linked list: $O(n)$
  - AVL guarantees $O(log n)$ for all operations

  *Balanced Cases*
  - `0`: Left and right subtrees same height
  - `1`: Left is 1 taller (left-heavy)
  - `-1`: Right is 1 taller (right-heavy)
  - `|bf| > 1`: Unbalanced! Needs rotation
]

#slide[
  = AVL Rotations
  #image("rotations.png")
  #image("rotations-2.png")

]

#slide[
  = AVL Insertion Algorithm

  *Steps*
  1. Insert normally (BST insert)
  2. Update heights going up
  3. Check balance factor at each node
  4. If unbalanced, perform appropriate rotation

  *Rotation Selection*
  - Left-Left (bf > 1, left child bf >= 0): Right rotation
  - Left-Right (bf > 1, left child bf < 0): Left-Right rotation
  - Right-Right (bf < -1, right child bf <= 0): Left rotation
  - Right-Left (bf < -1, right child bf > 0): Right-Left rotation

  *Time*: $O(log n)$ - height of tree
]


#slide[
  = AVL Deletion

  *Steps*
  1. Delete normally (BST delete)
  2. Update heights going up
  3. Check balance factor at each node
  4. Rebalance if needed

  *Deletion Cases*
  - Leaf: Just remove
  - One child: Replace with child
  - Two children: Replace with inorder successor (or predecessor), then delete successor

]

#slide[
  *Key Difference from Insert*
  - Multiple rotations might be needed on path to root
  - Deletion can cause imbalance at multiple levels

  *Time*: $O(log n)$

]

#slide[


    #link("https://mostlykiguess.github.io/DSA-S26-Tut-and-Materials/avl")[AVL Visualization]
]

#new-section[Graphs]

#slide[
  = Graph Representation

  *Graph: G = (V, E)*
  - V = set of vertices (nodes)
  - E = set of edges (connections)

  *Two main representations*
  1. _Adjacency Matrix_: `int adj[n][n]`
  2. _Adjacency List_: Array of linked lists

  *Which one to use?*
  - Matrix: Simple, but $O(V^2)$ space
  - List: Efficient for sparse graphs, $O(V + E)$ space

  *For this course*: We'll use adjacency lists in C++
]

#slide[
  = Why C++ for Graphs?

  *Problem with C*
  - Adjacency list: array of linked lists
  - Lots of pointer management
  - Memory allocation overhead
  - Verbose code

  *C++ Solution: vector*
  - Dynamic array that grows automatically
  - Clean syntax for adjacency lists
  - Still only what you need (no extra STL features)

  *Allowed for graphs ONLY*
  ```cpp
  vector<int> adj[MAX_N];  // Array of vectors
  adj[u].push_back(v);      // Add edge
  ```
]

#slide[
  = C++ Vector Basics

  *Vector*: Dynamic array (only STL feature you can use)
  ```cpp
  #include <vector>
  using namespace std;
  int main() {
      int n;
      cin >> n;
      vector<int> v(n);
      v[0] = 5;
      int x = v[0];
      // Add element (dynamic growth)
      v.push_back(10);  // O(1) amortized
      // Size
      int sz = v.size();
      return 0;
  }
  ```

]

#slide[
  = Adjacency List in C++

  *Unweighted Graph*
  ```cpp
  const int MAX_N = 100005;
  vector<int> adj[MAX_N];
  int main() {
      int n, m;
      cin >> n >> m;  // n vertices, m edges
      for (int i = 0; i < m; i++) {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);  // Remove for directed
      }
  }
  ```

  *Space*: $O(V + E)$ | *Add edge*: $O(1)$
]

#slide[
  = Weighted Graphs in C++

  *Need to store: (neighbor, weight) pairs*

  ```cpp
  const int MAX_N = 100005;
  struct Edge {
      int to, weight;
  };
  vector<Edge> adj[MAX_N]; // or just use pait<int,int>
  int main() {
      int n, m;
      cin >> n >> m;
      for (int i = 0; i < m; i++) {
          int u, v, w;
          cin >> u >> v >> w;
          adj[u].push_back({v, w});
          adj[v].push_back({u, w});
      }
  }
  ```

]

#slide[
  *Traversal*:
  ```cpp
  for (Edge e : adj[u]) {
      cout << u << " -> " << e.to << " (weight: " << e.weight << ")\n";
  }
  ```

]

#slide[
  = Common Input Format for Graphs

  *Format 1: Edge List*
  ```
  n m           // n vertices, m edges
  u1 v1         // edge 1
  u2 v2         // edge 2
  ...
  ```

  *Format 2: Weighted Edge List*
  ```
  n m
  u1 v1 w1      // edge with weight
  u2 v2 w2
  ...
  ```

]

#slide[
  *Reading in C++*
  ```cpp
  int n, m;
  cin >> n >> m;
  vector<Edge> adj[n];
  while (m--) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
  }
  ```

]


#slide[
  = #link("https://cses.fi/problemset/list/")[CSES Graph Problems]

  *Recommended starting problems*
  - #link("https://cses.fi/problemset/task/1667")[Building Roads]: Count connected components
  - #link("https://cses.fi/problemset/task/1666")[Building Teams]: Bipartite check
  - #link("https://cses.fi/problemset/task/1668")[Building Roads]: Find shortest path
  - #link("https://cses.fi/problemset/task/1672")[Shortest Routes I]: Dijkstra's algorithm

]

#new-section[Summary]

#slide[
  = Summary: AVL Trees

  *Key Points*
  - Self-balancing BST with $O(log n)$ guarantees
  - Balance factor must be in `[-1, 0, 1]` for all nodes
  - Four rotation types: LL, RR, LR, RL
  - Insert: One rotation max (at first unbalanced ancestor)
  - Delete: Multiple rotations possible

  *When to use AVL*
  - Need guaranteed $O(log n)$ operations
  - Lots of lookups, fewer inserts/deletes
  - Memory overhead is acceptable
]


#slide[
  = Takeaway Problems!

  === #link("https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/")[Sorted Array to BST]
  Convert sorted array to height-balanced BST.

  === #link("https://leetcode.com/problems/recover-binary-search-tree/")[Recover BST]
  Two nodes swapped in BST. Recover it.

  === #link("https://cses.fi/problemset/task/1671")[Shortest Routes II]
  Floyd-Warshall all-pairs shortest path.
]

#slide[
  = More you know ...

  === #link("https://cses.fi/problemset/task/1139")[Gathering Children]
  Sparse Table for RMQ.

  === #link("https://cses.fi/problemset/task/1734")[Road Construction]
  Union-Find with rollback.
]

#slide[
  #set page(header: none, footer: none, margin: 3em)

  #align(center)[
    #text(size: 1.5em)[_Questions?_]

    #v(2em)
    Thank you!

    #v(1em)
    #set text(size: .7em)
  ]
]
