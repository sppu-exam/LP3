#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Node class to represent each character, frequency, and binary code in the tree
class Node
{
public:
    int val;
    string symbol;
    string huffman;
    Node *left;
    Node *right;

    Node(int val, string symbol) : val(val), symbol(symbol), huffman(""), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue to build the Huffman Tree
struct Compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->val > r->val;
    }
};

// Builds the Huffman Tree
Node *buildHuffmanTree(vector<string> &characters, vector<int> &frequencies)
{
    priority_queue<Node *, vector<Node *>, Compare> nodes;
    for (int i = 0; i < characters.size(); i++)
    {
        nodes.push(new Node(frequencies[i], characters[i]));
    }

    while (nodes.size() > 1)
    {
        Node *left = nodes.top();
        nodes.pop();
        Node *right = nodes.top();
        nodes.pop();

        left->huffman = "0";
        right->huffman = "1";

        Node *newNode = new Node(left->val + right->val, left->symbol + right->symbol);
        newNode->left = left;
        newNode->right = right;
        nodes.push(newNode);
    }
    return nodes.top();
}

// Recursive traversal to assign Huffman Codes
void traverse(Node *node, string currentCode, unordered_map<string, int> &huffmanDecimal)
{
    if (!node->left && !node->right)
    {
        huffmanDecimal[node->symbol] = stoi(currentCode, nullptr, 2);
    }
    else
    {
        if (node->left)
        {
            traverse(node->left, currentCode + node->left->huffman, huffmanDecimal);
        }
        if (node->right)
        {
            traverse(node->right, currentCode + node->right->huffman, huffmanDecimal);
        }
    }
}

// Prints the Huffman codes in decimal representation
void printHuffmanCodes(Node *root)
{
    unordered_map<string, int> huffmanDecimal;
    traverse(root, "", huffmanDecimal);

    cout << "Huffman Codes (Decimal):\n";
    for (const auto &entry : huffmanDecimal)
    {
        cout << entry.first << " -> " << entry.second << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<string> characters(n);
    vector<int> frequencies(n);

    cout << "Enter characters (separated by space): ";
    for (int i = 0; i < n; i++)
    {
        cin >> characters[i];
    }

    cout << "Enter corresponding frequencies (separated by space): ";
    for (int i = 0; i < n; i++)
    {
        cin >> frequencies[i];
    }

    Node *root = buildHuffmanTree(characters, frequencies);
    printHuffmanCodes(root);

    return 0;
}
