#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node* parent = nullptr;
    int count = 1; // # decendents + current
};
Node* getRoot(Node* node) {
    while(node->parent) node = node->parent;
    return node;
}
int merge(Node* a, Node* b) {
    Node* r1 = getRoot(a);
    Node* r2 = getRoot(b);
    if(r1 == r2) return r1->count;
    // Add small tree to root of big tree
    Node *big, *small;
    if(r1->count > r2->count) { big = r1; small = r2; } else { big = r2; small = r1; }
    small->parent = big;
    big->count += small->count;
    return big->count;
}
int main() {
    int n;
    scanf("%d", &n);
    int largest = 1, a, b;
    unordered_map<int, Node> nodes;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        largest = max(largest, merge(&nodes[a], &nodes[b]));
        printf("%d\n", largest);
    }
    return 0;
}
