#include <iostream>
#include <string>
#include <vector>

using namespace std;

//-1 on parent, child1 or child2 means there is none.
//depth denotes the amount of layers below this node.
struct TreeNode{
    string name;
    bool function;
    int parent;
    int child1;
    int child2;
    unsigned int depth;
};
typedef vector<TreeNode> Tree;
const unsigned int max_line_length = 200000;
unsigned int N;

void assign(TreeNode& node, string n, bool f, int p, int c1, int c2, unsigned int d){
    node.name = n;
    node.function = f;
    node.parent = p;
    node.child1 = c1;
    node.child2 = c2;
    node.depth = d;
}

string readLine(){
    string line = "";
    bool stop = false;
    for(unsigned int k = 0; k <  max_line_length && !stop; k++){
        char a;
        cin.get(a);
        line += a;
        if(a == '\n')
            stop = true;
    }
    return line;
}

vector<string> readLines(){
    cin >> N;
    cin.get();
    vector<string> lines;
    for(unsigned int k = 0; k < N; k++){
        string line = readLine();
        lines.push_back(line);
    }
    return lines;
}

void addDepth(Tree& tree, int start, unsigned int startDepth){
    if(start >= 0 && startDepth >= tree[start].depth){
        tree[start].depth++;
        addDepth(tree, tree[start].parent, tree[start].depth);
    }
}

Tree buildTree(string line){
    Tree tree;
    string name = "";
    int nr_nodes = 0;
    for(unsigned int k = 0; k < line.size(); k++){
        char c = line.at(k);
        if(c == '('){
            TreeNode node;
            if(nr_nodes == 0)
                assign(node, name, true, -1, -1, -1, 0);
            else{
                int n = 0;
                while(!tree[nr_nodes-1-n].function || (tree[nr_nodes-1-n].child1 != -1))
                    n++;
                if(tree[nr_nodes-1-n].child2 == -1)
                    addDepth(tree, nr_nodes-1-n, 0);
                assign(node, name, true, nr_nodes-1-n, -1, -1, 0);
                tree[nr_nodes-1-n].child1 = tree[nr_nodes-1-n].child2;
                tree[nr_nodes-1-n].child2 = nr_nodes;
            }
            tree.push_back(node);
            nr_nodes++;
            name = "";
        }
        else if(c == ',' && name.compare("") != 0){
            TreeNode node;
            int n = 0;
            while(!tree[nr_nodes-1-n].function || (tree[nr_nodes-1-n].child1 != -1))
                n++;
            addDepth(tree, nr_nodes-1-n, 0);
            assign(node, name, false, nr_nodes-1-n, -1, -1, 0);
            tree[nr_nodes-1-n].child1 = tree[nr_nodes-1-n].child2;
            tree[nr_nodes-1-n].child2 = nr_nodes;
            tree.push_back(node);
            nr_nodes++;
            name = "";
        }
        else if(c == ',' && name.compare("") == 0){
            //do nothing
        }
        else if(c == ')' && name.compare("") != 0){
            TreeNode node;
            int n = 1;
            while(!tree[nr_nodes-1-n].function || (tree[nr_nodes-1-n].child1 != -1))
                n++;
            assign(node, name, false, nr_nodes-1-n, -1, -1, 0);
            tree[nr_nodes-1-n].child1 = tree[nr_nodes-1-n].child2;
            tree[nr_nodes-1-n].child2 = nr_nodes;
            tree.push_back(node);
            nr_nodes++;
            name = "";
        }
        else if(c == ')' && name.compare("") == 0){
            //do nothing
        }
        else{
            name += c;
        }
    }
    return tree;
}

vector<Tree> buildTrees(vector<string> lines){
    vector<Tree> trees;
    for(unsigned int k = 0; k < N; k++){
        Tree tree = buildTree(lines[k]);
        trees.push_back(tree);
    }
    return trees;
}

int main()
{
    vector<string> lines = readLines();
    cout << endl << N << endl;
    for(unsigned int k = 0; k < N; k++)
        cout << lines[k];
    cout << endl;
    vector<Tree> trees = buildTrees(lines);
    //parents:
    cout << "parents:" << endl;
    for(unsigned int k = 0; k < N; k++){
        for(unsigned int l = 0; l < trees[k].size(); l++){
            cout << trees[k][l].parent << " ";
        }
        cout << endl;
    }
    //depth:
    cout << "depth:" << endl;
    for(unsigned int k = 0; k < N; k++){
        for(unsigned int l = 0; l < trees[k].size(); l++){
            cout << trees[k][l].depth << " ";
        }
        cout << endl;
    }
    //children, separated with comma:
    cout << "children:" << endl;
    for(unsigned int k = 0; k < N; k++){
        for(unsigned int l = 0; l < trees[k].size(); l++){
            cout << trees[k][l].child1 << "," << trees[k][l].child2 << " ";
        }
        cout << endl;
    }
    return 0;
}
