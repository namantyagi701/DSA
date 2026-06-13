#include <bits/stdc++.h>
using namespace std;

class LFUCache {
private:
    struct Node {
        int key, value, freq;
        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, list<Node>::iterator> keyTable;
    unordered_map<int, list<Node>> freqTable;

    void updateFreq(list<Node>::iterator it) {
        int key = it->key;
        int value = it->value;
        int freq = it->freq;

        freqTable[freq].erase(it);

        if (freqTable[freq].empty()) {
            freqTable.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        freqTable[freq + 1].push_front(Node(key, value));
        freqTable[freq + 1].front().freq = freq + 1;

        keyTable[key] = freqTable[freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyTable.find(key) == keyTable.end())
            return -1;

        auto it = keyTable[key];
        int value = it->value;

        updateFreq(it);

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyTable.find(key) != keyTable.end()) {
            auto it = keyTable[key];
            it->value = value;
            updateFreq(it);
            return;
        }

        if (keyTable.size() == capacity) {
            auto &lst = freqTable[minFreq];

            int evictKey = lst.back().key;

            keyTable.erase(evictKey);
            lst.pop_back();

            if (lst.empty())
                freqTable.erase(minFreq);
        }

        freqTable[1].push_front(Node(key, value));
        keyTable[key] = freqTable[1].begin();
        minFreq = 1;
    }
};