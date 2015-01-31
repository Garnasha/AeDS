#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

//depth denotes the amount of layers of children this node has.
struct TreeNode{
    string name;
    bool function;
    int parent;
    int child1;
    int child2;
    unsigned int depth;
    unsigned int code;
};
typedef vector<TreeNode> Tree;
const unsigned int max_line_length = 200000;
unsigned int N;

void fillArray(unsigned int array[], unsigned int size){
    for(unsigned int k = 0; k < size; k++){
        array[k] = 0;
    }
}

string readLine(istream& in){
    string line = "";
    bool stop = false;
    for(unsigned int k = 0; k < max_line_length && !stop; k++){
        char a;
        in.get(a);
        line += a;
        if(a == '\n')
            stop = true;
    }
    return line;
}

vector<string> readLines(istream& in){
    in >> N;
    in.get();
    vector<string> lines;
    for(unsigned int k = 0; k < N; k++){
        string line = readLine(in);
        lines.push_back(line);
    }
    return lines;
}

void buildTree(Tree& tree, string line, unsigned int& line_ind, unsigned int& nr_nodes, int parentNode, unsigned int currentNode);

void addFunctionNode(Tree& tree, string line, string name, unsigned int& line_ind, unsigned int& nr_nodes, int parentNode, unsigned int currentNode){
    TreeNode node = {name, true, parentNode, -1, -1, 0, 0};
    tree.push_back(node);
    line_ind++;
    nr_nodes++;
    tree[currentNode].child1 = nr_nodes;
    buildTree(tree, line, line_ind, nr_nodes, currentNode, nr_nodes);
    tree[currentNode].child2 = nr_nodes;
    buildTree(tree, line, line_ind, nr_nodes, currentNode, nr_nodes);
    tree[currentNode].depth = max(tree[tree[currentNode].child1].depth + 1, tree[tree[currentNode].child2].depth + 1);
}

void buildTree(Tree& tree, string line, unsigned int& line_ind, unsigned int& nr_nodes, int parentNode, unsigned int currentNode){
    string name = "";
    bool stop = false;
    for(; line_ind < line.size() && !stop; line_ind++){
        char c = line.at(line_ind);
        if(c == '('){
            addFunctionNode(tree, line, name, line_ind, nr_nodes, parentNode, currentNode);
            stop = true;
        }
        if(c == ',' || c == ')' || (c == '\n' && name.compare("") != 0)){
            TreeNode node = {name, false, parentNode, -1, -1, 0, 0};
            tree.push_back(node);
            nr_nodes++;
            stop = true;
        }
        name += c;
    }
}

vector<Tree> buildTrees(vector<string>& lines){
    vector<Tree> trees;
    for(unsigned int k = 0; k < N; k++){
        Tree tree;
        unsigned int i = 0, j = 0;
        buildTree(tree, lines[k], i, j, -1, 0);
        trees.push_back(tree);
    }
    return trees;
}

string intToString(unsigned int code){
    string codestr = "";
    for(unsigned int k = 0; k < log((double)code); k++){
        unsigned int clog = (unsigned int)log((double)code);
        unsigned int currentDigit = (code/(unsigned int)pow(10, (double)(clog - k)))%10;
        if(codestr.compare("") != 0 || currentDigit != 0){
            codestr += (char)(currentDigit + 48);
        }
    }
    return codestr;
}

bool sameSubTrees(Tree& tree, TreeNode node1, TreeNode node2){
    if(node1.name.compare(node2.name) == 0 && node1.depth == node2.depth){
        if(!node1.function){
            return true;
        }
        return sameSubTrees(tree, tree[node1.child1], tree[node2.child1])
                && sameSubTrees(tree, tree[node1.child2], tree[node2.child2]);
    }
    return false;
}

TreeNode findCorresponding(Tree& unCoded, TreeNode codedNode, unsigned int nodeIndex){
    if(codedNode.code == 0){
        TreeNode node = {"", false, 0, 0, 0, 0, 0};
        return node;
    }
    for(unsigned int k = nodeIndex; k < unCoded.size(); k++){
        if(unCoded[k].name == codedNode.name){
            return unCoded[k];
        }
    }
    TreeNode node = {"", false, 0, 0, 0, 0, 0};
    return node;
}

unsigned int countNodes(Tree& unCoded, TreeNode node){
    unsigned int count = 1;
    if(node.function){
        count += countNodes(unCoded, unCoded[node.child1])
                + countNodes(unCoded, unCoded[node.child2]);
    }
    return count;
}

void adjustParent(unsigned int nodesRemoved[], TreeNode& node){
    for(unsigned int k = 0; (int)k < node.parent; k++){
        node.parent -= nodesRemoved[k];
    }
}

void adjustChildren(Tree& codedTree, unsigned int nodesRemoved[], TreeNode startNode){
    if(startNode.function){
        for(unsigned int k = 0; (int)k < startNode.child1; k++){
            startNode.child1 -= nodesRemoved[k];
        }
        for(unsigned int k = 0; (int)k < startNode.child2; k++){
            startNode.child2 -= nodesRemoved[k];
        }
        if(startNode.parent > -1){
            adjustChildren(codedTree, nodesRemoved, codedTree[startNode.parent]);
        }
    }
}

void checkSubTree(Tree& unCoded, Tree& codedTree, unsigned int nodesRemoved[], unsigned int& c, unsigned int k){
    bool found = false;
    for(unsigned int l = 0; l < codedTree.size() && !found; l++){
        TreeNode deCoded = findCorresponding(unCoded, codedTree[l], l);
        if(deCoded.name.compare("") != 0 && sameSubTrees(unCoded, unCoded[k], deCoded)){
            TreeNode cnode = {intToString(codedTree[l].code), false, unCoded[k].parent, -1, -1, 0, 0};
            nodesRemoved[codedTree.size()] = countNodes(unCoded, unCoded[k]) - 1;
            adjustParent(nodesRemoved, cnode);
            codedTree.push_back(cnode);
            adjustChildren(codedTree, nodesRemoved, codedTree[cnode.parent]);
            found = true;
        }
        else if(unCoded[k].depth > deCoded.depth){
            l += countNodes(unCoded, deCoded);
        }
    }
    if(!found){
        TreeNode cnode = {unCoded[k].name, unCoded[k].function, unCoded[k].parent, unCoded[k].child1, unCoded[k].child2, unCoded[k].depth, c};
        adjustParent(nodesRemoved, cnode);
        codedTree.push_back(cnode);
        c++;
    }
}

Tree reduceTree(Tree& unCoded){
    Tree codedTree;
    unsigned int c = 1;
    unsigned int nodesRemoved[unCoded.size()];
    fillArray(nodesRemoved, unCoded.size());
    for(unsigned int k = 0; k < unCoded.size(); k++){
        checkSubTree(unCoded, codedTree, nodesRemoved, c, k);
    }
    return codedTree;
}

vector<Tree> reduceTrees(vector<Tree>& unCoded){
    vector<Tree> codedTrees;
    for(unsigned int k = 0; k < N; k++){
        Tree codedTree = reduceTree(unCoded[k]);
        codedTrees.push_back(codedTree);
    }
    return codedTrees;
}

void flattenTree(Tree& tree, TreeNode node){
    cout << node.name;
    if(node.function){
        cout << "(";
        flattenTree(tree, tree[node.child1]);
        cout << ",";
        flattenTree(tree, tree[node.child2]);
        cout << ")";
    }
}

int main()
{
    ifstream in;
    in.open("samples.in");
    vector<string> lines = readLines(in);
    cout << "Done reading..." << endl;
    vector<Tree> trees = buildTrees(lines);
    cout << "Done building..." << endl;
    vector<Tree> codedTrees = reduceTrees(trees);
    cout << endl;
    for(unsigned int k = 0; k < N; k++){
        flattenTree(codedTrees[k], codedTrees[k][0]);
        cout << endl;
    }
    return 0;
}
