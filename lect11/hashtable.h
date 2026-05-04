#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <iomanip>
#include <cstdint>
#include <sstream>

#ifndef HASHATABLE_H
#define HASHATABLE_H

uint32_t ip_to_uint32(const std::string& ip);
std::string uint32_to_ip(uint32_t ip);

// Hash table with separate chaining
class HashTable {
private:
    std::vector<std::list<uint32_t>> buckets; // Buckets as vector of linked lists
    size_t m; // Number of buckets
    size_t n; // Number of keys
    uint32_t seed; // Random seed — 0 means deterministic

    size_t hash(uint32_t key) const {
        return key % m; 
    }

public:
    HashTable(size_t table_size, bool randomize = false) : m(table_size), n(0), seed(0) {
        buckets.resize(m);
        if (randomize) {
            std::random_device rd;
            seed = rd();
        }
    }

    // Insert a key
    void insert(uint32_t key) {
        size_t index = hash(key);
        buckets[index].push_back(key);
        n++;
    }

    // Search for a key
    bool find(uint32_t key) const {
        size_t index = hash(key);
        for(auto e : buckets[index]){
            if (e == key) return true;
        }
        return false;
    }


    // Visualize the hash table
    void visualize() const {
        std::cout << "Hash Table (m = " << m << ", n = " << n << ", load factor = " 
                  << std::fixed << std::setprecision(2) << (double)n / m << "):\n";
        for (size_t i = 0; i < m; ++i) {
            std::cout << "Bucket " << std::setw(2) << i << ": ";
            if (buckets[i].empty()) {
                std::cout << "[]";
            } else {
                std::cout << "[";
                bool first = true;
                for (const auto& key : buckets[i]) {
                    if (!first) std::cout << " -> ";
                    std::cout << uint32_to_ip(key); // Print as IP address
                    first = false;
                }
                std::cout << "]";
            }
            std::cout << "\n";
        }
    }

    // Get statistics
    void stats() const {
        size_t max_size = 0;
        size_t non_empty = 0;
        double sum_positions = 0.0;
        for (const auto& bucket : buckets) {
            size_t sz = bucket.size();
            if (sz > 0) non_empty++;
            sum_positions += sz * (sz + 1) / 2.0;  // 1 + 2 + ... + sz
            max_size = std::max(max_size, sz);
        }
        // Load factor alpha = n/m: always n/m regardless of distribution (not a useful metric alone)
        // Expected search cost: searching for a random key scans 1, 2, ..., b_j steps
        // for the 1st, 2nd, ..., b_j-th key in a chain of length b_j.
        // Total across all keys in bucket j = b_j*(b_j+1)/2. Average over all n keys = sum / n.
        // Uniform hashing predicts ~1 + alpha/2. Adversarial (all in one bucket) gives (n+1)/2.
        double alpha = (double)n / m;
        double expected_search_cost = n > 0 ? sum_positions / n : 0.0;
        std::cout << "Stats:\n";
        std::cout << "  Non-empty buckets:      " << non_empty << " / " << m << "\n";
        std::cout << "  Load factor (n/m):      " << std::fixed << std::setprecision(2) << alpha << "\n";
        std::cout << "  Max chain length:       " << max_size << "\n";
        std::cout << "  Exp. search cost:       " << std::setprecision(2) << expected_search_cost
                  << "  (theory predicts ~" << std::setprecision(2) << 1 + alpha/2 << " for uniform)\n";
    }
};
// Convert IP address (string) to uint32_t
uint32_t ip_to_uint32(const std::string& ip) {
    uint32_t result = 0;
    size_t start = 0;
    for (int i = 0; i < 4; ++i) {
        size_t end = ip.find('.', start);
        if (end == std::string::npos) end = ip.length();
        result = (result << 8) + std::stoi(ip.substr(start, end - start));
        start = end + 1;
    }
    return result;
}

// Convert uint32_t to IP address (string)
std::string uint32_to_ip(uint32_t ip) {
    std::ostringstream oss;
    oss << ((ip >> 24) & 0xFF) << "."
        << ((ip >> 16) & 0xFF) << "."
        << ((ip >> 8) & 0xFF) << "."
        << (ip & 0xFF);
    return oss.str();
}
#endif