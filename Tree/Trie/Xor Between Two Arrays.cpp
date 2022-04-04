class Node {
private:
    Node *links[2];

public:
    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node *node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node *node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

int Solution::solve(vector<int> &A, vector<int> &B) {
    Trie t;
    int ans = 0;

    for (int &i : A)
        t.insert(i);

    for (int &i : B)
        ans = max(ans, t.getMax(i));

    return ans;
}


// https://www.interviewbit.com/problems/xor-between-two-arrays/