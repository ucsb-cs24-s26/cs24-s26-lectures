#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

/*
 * Activity: Web Traffic Analysis
 *
 * You're a software engineer at Amazon. 
 * Here's a log of IP addresses that visited the site. 
 * Your boss wants answers.
 */

vector<string> traffic_log = {
    "192.168.1.1", "10.0.0.5", "192.168.1.1", "172.16.0.1",
    "10.0.0.5", "192.168.1.1", "8.8.8.8", "10.0.0.5",
    "192.168.1.1", "172.16.0.1", "192.168.1.1", "8.8.8.8",
    "192.168.1.1", "10.0.0.5", "203.0.113.42"
};
// Data structures for fast insertion and fast search: BST: std::set 
// insert: O(log n), search : O(log n)
// hashtable: unordered_set: insertions O(1) --- average , search -- O(1) --average
// ============================================================
// Part A: How many unique visitors?
// Use: unordered_set
// Expected output: 5
// ============================================================
int uniqueVisitors(const vector<string>& log) {
    // TODO: Your code here
    unordered_set<string> unique_ips;
    for (auto ip : log){
        unique_ips.insert(ip);
    }
    return unique_ips.size();
}

// ============================================================
// Part B: How many times did each IP visit?
// Use: unordered_map
// Expected output:
//   192.168.1.1: 6
//   10.0.0.5: 4
//   172.16.0.1: 2
//   8.8.8.8: 2
//   203.0.113.42: 1
// ============================================================
unordered_map<string, int> countVisits(const vector<string>& log) {
    // TODO: Your code here
    unordered_map<string, int> ipcount;
    ipcount["0.0.0.0"] = 1 ; // inserts the key '0.0.0.0' with value 1
    for (auto ip : log){
        ipcount[ip]++; // insert and update !! 
    }
    return ipcount;
}


// ============================================================
// Part C (Challenge): Find the top K most frequent visitors
// Use: priority_queue (min-heap of size k)
// Expected output for k=3:
//   192.168.1.1: 6
//   10.0.0.5: 4
//   172.16.0.1: 2  (or 8.8.8.8: 2, tie)
// ============================================================
vector<pair<string, int>> topKVisitors(const unordered_map<string, int>& counts, int k) {

    return {};
}


// ============================================================
// Test your solutions
// ============================================================
int main() {
    cout << "=== Part A: Unique Visitors ===" << endl;
    cout << "Count: " << uniqueVisitors(traffic_log) << endl;
    cout << "Expected: 5" << endl << endl;

    cout << "=== Part B: Visit Counts ===" << endl;
    auto counts = countVisits(traffic_log);
    for (const auto& [ip, count] : counts) {
        cout << ip << ": " << count << endl;
    }
    cout << endl;

    // Part C, reuses the counts map from Part B
    cout << "=== Part C: Top 3 Visitors ===" << endl;
    auto top3 = topKVisitors(counts, 3);
    for (const auto& [ip, count] : top3) {
        cout << ip << ": " << count << endl;
    }
    cout << endl;

    return 0;
}
