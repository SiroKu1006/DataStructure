#include <iostream>
#include <cstring>
#include <string>
#define endl '\n'
using namespace std;
class HuffmanNode {
    public:
        HuffmanNode(char c, int f) : name(c), num(f), left(nullptr), right(nullptr) {}
        HuffmanNode(char c, int f, HuffmanNode* l, HuffmanNode* r) : name(c), num(f), left(l), right(r) {}

        char name;
        int num;
        HuffmanNode* left;
        HuffmanNode* right;
};
class MinHeap {
    private:
        HuffmanNode** heapArray; 
        int size; 
        int capacity; 
        // 正規化
        void heapify(int index) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            //左邊右邊 (比大小)
            if (left < size && heapArray[left]->num < heapArray[smallest]->num)
                smallest = left;
            if (right < size && heapArray[right]->num < heapArray[smallest]->num)
                smallest = right;
            //不是最小就交換
            if (smallest != index) {
                swap(heapArray[index], heapArray[smallest]);
                //recursive
                heapify(smallest);
            }
        }
    public:
        MinHeap(int capacity) : size(0), capacity(capacity) {
            heapArray = new HuffmanNode*[capacity];
        }
        ~MinHeap() {
            delete[] heapArray;
        }
        // insert  node to heap
        void insert(HuffmanNode* node) {
            if (size == capacity) return;
            int i = size++;
            heapArray[i] = node;
            while (i && heapArray[i]->num < heapArray[(i - 1) / 2]->num) {
                swap(heapArray[i], heapArray[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }
        //return 最小頻率的節點
        HuffmanNode* extractMin() {
            if (size == 0) return nullptr;
            if (size == 1) return heapArray[--size];
            HuffmanNode* root = heapArray[0];
            heapArray[0] = heapArray[--size];
            heapify(0);
            return root;
        }
        //return size
        int getSize() {
            return size;
        }
};

class HuffmanTree {
    public:
        HuffmanTree() : root(nullptr) {}
        HuffmanTree(HuffmanNode* r) : root(r) {}
        HuffmanNode* root;
        //build tree
        void buildTree(pair<char, int> frequencies[], int n) {
            MinHeap minHeap(n);
            for (int i = 0; i < n; ++i) {
                //將所有節點存入Heap
                minHeap.insert(new HuffmanNode(frequencies[i].first, frequencies[i].second));
            }
            while (minHeap.getSize() > 1) {
                //取出最小的兩個節點
                HuffmanNode* left = minHeap.extractMin();
                HuffmanNode* right = minHeap.extractMin();
                //合併
                int sum = left->num + right->num;
                //存回去
                minHeap.insert(new HuffmanNode('\0', sum, left, right));
            }
            root = minHeap.extractMin();
        }
        // generate huffman code
        void generateCodes(HuffmanNode* node, string code, string huffmanCode[]) {
            //空的就return
            if (!node) return;
            
            if (node->name != '\0') {
                //將字母的存入huffmanCode
                huffmanCode[node->name - 'A'] = code;
            }
            //recursive
            generateCodes(node->left, code + "0", huffmanCode);
            generateCodes(node->right, code + "1", huffmanCode);
        }

};

int main() {
    pair<char, int> arr[100];
    int n = 0;
    while (cin.peek() != EOF && cin.peek() != '\n') {
        string input;
        getline(cin, input);
        if (input.empty()) break;
        char name = input[0];
        int num = stoi(input.substr(2));
        arr[n++] = make_pair(name, num);
    }

    string nn;
    getline(cin, nn);
    cout << endl;

    HuffmanTree huffmanTree;
    huffmanTree.buildTree(arr, n);
    string huffmanCode[26];
    huffmanTree.generateCodes(huffmanTree.root, "", huffmanCode);
    for (int i = 0; i < n; ++i) {
        cout << arr[i].first << " " << huffmanCode[arr[i].first - 'A'] << endl;
    }

    string input;
    getline(cin, input);
    string encoded;
    for (char c : input) {
        encoded += huffmanCode[c - 'A'];
    }
    cout << encoded << endl;

    return 0;
}
