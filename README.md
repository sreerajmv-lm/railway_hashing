# railway_hashing
# Railway Booking System Using Hashing

## 1. Aim

To implement a railway booking system using a hash table and compare the collision-resolution techniques:

- Linear Probing
- Quadratic Probing
- Double Hashing

## 2. Given Data

Booking IDs:

23, 43, 13, 33, 53, 63, 73

Hash table size:

11

Hash function:

h(k) = k % 11

## 3. Load Factor

Number of keys:

n = 7

Hash table size:

m = 11

Load factor:

α = n / m

α = 7 / 11

α = 0.6364

Therefore, the load factor is approximately **63.64%**.

## 4. Linear Probing

Formula:

h_i(k) = (h(k) + i) % 11

For the given booking IDs, no collision occurs during insertion.

Final hash table:

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| Value | 33 | 23 | 13 | - | - | - | - | 73 | 63 | 53 | 43 |

## 5. Quadratic Probing

Formula:

h_i(k) = (h(k) + i²) % 11

No collision occurs during insertion.

Final hash table:

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| Value | 33 | 23 | 13 | - | - | - | - | 73 | 63 | 53 | 43 |

## 6. Double Hashing

First hash function:

h₁(k) = k % 11

Second hash function:

h₂(k) = 7 - (k % 7)

Formula:

h_i(k) = (h₁(k) + i × h₂(k)) % 11

No collision occurs during insertion.

Final hash table:

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| Value | 33 | 23 | 13 | - | - | - | - | 73 | 63 | 53 | 43 |

## 7. Search Operation

The following keys were selected:

- 53 — Existing
- 73 — Existing
- 12 — Non-existing

### Search Results

| Key | Status | Linear Probing | Quadratic Probing | Double Hashing |
|---|---|---:|---:|---:|
| 53 | Existing | 1 | 1 | 1 |
| 73 | Existing | 1 | 1 | 1 |
| 12 | Non-existing | 3 | 3 | 2 |

For key 12:

12 % 11 = 1

### Linear Probing

Probe positions:

1 → 2 → 3

Index 3 is empty.

Number of probes = 3.

### Quadratic Probing

Probe positions:

1 → 2 → 5

Index 5 is empty.

Number of probes = 3.

### Double Hashing

h₁(12) = 1

h₂(12) = 2

Probe positions:

1 → 3

Index 3 is empty.

Number of probes = 2.

## 8. Complexity Analysis

| Operation | Linear Probing | Quadratic Probing | Double Hashing |
|---|---|---|---|
| Average insertion | O(1) | O(1) | O(1) |
| Average search | O(1) | O(1) | O(1) |
| Worst-case insertion | O(n) | O(n) | O(n) |
| Worst-case search | O(n) | O(n) | O(n) |
| Space complexity | O(m) | O(m) | O(m) |

## 9. Comparison

| Feature | Linear Probing | Quadratic Probing | Double Hashing |
|---|---|---|---|
| Collision handling | Sequential positions | Square increments | Second hash function |
| Primary clustering | High | Reduced | Very low |
| Extra hash function | No | No | Yes |
| Implementation | Simple | Moderate | More complex |
| Average time | O(1) | O(1) | O(1) |
| Selected unsuccessful search | 3 probes | 3 probes | 2 probes |

## 10. Effect of Load Factor

The load factor is:

α = 7 / 11 = 0.6364

Therefore, approximately 63.64% of the hash table is occupied.

As the load factor increases, collisions generally increase and more probes may be required.

Linear probing can suffer from primary clustering.

Quadratic probing reduces primary clustering.

Double hashing generally provides better distribution and reduces clustering.

For this particular input, there are no collisions during insertion because all seven booking IDs have different initial hash positions.

## 11. Conclusion

For the given booking IDs and a hash table of size 11, all three collision-resolution techniques produce the same final hash table because no collision occurs during insertion.

For the selected searches, existing keys require one probe. For the non-existing key 12, linear probing and quadratic probing require three probes, while double hashing requires two probes.

Thus, in this particular execution, double hashing uses fewer probes for the selected unsuccessful search. It also requires an additional hash function and is slightly more complex to implement.

## 12. Files in This Repository

- `railway_hashing.c` — C implementation of the three hashing techniques.
- `output.txt` — Program execution output.
- `trace_table.txt` — Insertion and search trace tables.
- `README.md` — Assignment description, analysis, comparison, and conclusion.
