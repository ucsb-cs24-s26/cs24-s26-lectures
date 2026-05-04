#include "hashtable.h"
#include <iostream>
#include <random>

uint32_t generate_ip(std::mt19937& gen, bool unif_rnd, size_t m) {
    if (!unif_rnd) {
        // Generate an integer multiple of m — adversarial input for h(x) = x mod m
        uint32_t ip = (gen() % (UINT32_MAX / m)) * m;
        return ip;
    } else {
        std::uniform_int_distribution<int> octet_dist(0, 255);
        std::ostringstream oss;
        oss << octet_dist(gen) << "." << octet_dist(gen) << "."
            << octet_dist(gen) << "." << octet_dist(gen);
        return ip_to_uint32(oss.str());
    }
}

void run(const std::string& label, bool uniform_random_ip, bool randomize_seed,
         size_t m, size_t n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    HashTable ht(m, randomize_seed);

    std::cout << "\n=== " << label << " ===\n";
    for (size_t i = 0; i < n; i++) {
        uint32_t ip = generate_ip(gen, uniform_random_ip, m);
        ht.insert(ip);
    }
    ht.visualize();
    ht.stats();
}

int main() {
    size_t m = 20, n = 20;

    // --- Show before derivation ---

    // Run 1: uniform random IPs — chains stay short, O(1) in practice
    // run("Uniform random IPs (deterministic hash)", true, false, m, n);

    // Run 2: adversarial IPs (multiples of m) — all collide into bucket 0, O(n) search
    //run("Adversarial IPs, deterministic hash  [ALL COLLIDE]", false, false, m, n);

    // --- Uncomment after derivation: randomized seed defeats the adversarial input ---
    run("Adversarial IPs, randomized seed     [DEFENDED]", false, true, m, n);

    return 0;
}
