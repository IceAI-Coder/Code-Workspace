# Data Structure Practice Plan

This repository documents a structured learning path for mastering data structures through curated LeetCode problems. The goal is to build deep understanding for technical interviews and software engineering fundamentals.

Each section includes:
- Concept overview and why the data structure matters
- High-quality learning resources focused on theory and implementation
- Curated problem list with difficulty progression, classic problems, Status, and Solved Date

---

## Table of Contents

- [Array & String](#array--string)
- [Linked List](#linked-list)
- [Stack & Queue](#stack--queue)
- [Hash Table](#hash-table)
- [Binary Tree](#binary-tree)
- [Binary Search Tree (BST)](#binary-search-tree-bst)
- [Heap & Priority Queue](#heap--priority-queue)
- [Graph](#graph)
- [Union Find](#union-find)
- [Other Classics](#other-classics)
- [Learning Strategy](#learning-strategy)

---

## Array & String

Arrays and Strings are foundational for two pointers, sliding window, prefix sums, and hashing-based techniques.

**Concept Resources**
- MIT OpenCourseWare – Introduction to Algorithms (arrays, strings, asymptotics): https://ocw.mit.edu
- VisuAlgo – Arrays and string operations visualization: https://visualgo.net
- UC Berkeley CS61B – Array-based structures and iteration: https://cs61b.org

### Problem List

| ID  | Title                                      | Complexity   | Difficulty | Status   | Solved Date | Link |
|-----|--------------------------------------------|--------------|------------|----------|-------------|------|
| 1   | Two Sum                                    | O(n^2) Brute | Easy       |    AC    | 2025/08/20  | [Link](https://leetcode.com/problems/two-sum/) |
| 26  | Remove Duplicates from Sorted Array        | O(n)         | Easy       |    AC    | 2025/08/21  | [Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) |
| 344 | Reverse String                             | O(n)         | Easy       |    AC    | 2025/08/21  | [Link](https://leetcode.com/problems/reverse-string/) |
| 125 | Valid Palindrome                           | O(n)         | Easy       |    AC    | 2025/08/21  | [Link](https://leetcode.com/problems/valid-palindrome/) |
| 11  | Container With Most Water                  | O(n)         | Medium     |    AC    | 2025/08/30  | [Link](https://leetcode.com/problems/container-with-most-water/) |
| 15  | 3Sum                                       | O(n^2)       | Medium     |    AC    | 2025/08/31  | [Link](https://leetcode.com/problems/3sum/) |
| 238 | Product of Array Except Self               | O(n)         | Medium     |          |             | [Link](https://leetcode.com/problems/product-of-array-except-self/) |
| 121 | Best Time to Buy and Sell Stock            | O(n)         | Easy       |          |             | [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) |
| 53  | Maximum Subarray                           | O(n)         | Easy       |          |             | [Link](https://leetcode.com/problems/maximum-subarray/) |

---

## Linked List

Linked Lists build intuition for pointers, mutation, recursion, and in-place algorithms.

**Concept Resources**
- CS50 – Linked Lists (memory, nodes, pointers): https://cs50.harvard.edu
- OpenDSA – Linked Lists (visual explanations): https://opendsa-server.cs.vt.edu
- CMU 15-122 – Linked structures: https://www.cs.cmu.edu

### Problem List

| ID  | Title                              | Complexity | Difficulty | Status   | Solved Date | Link |
|-----|------------------------------------|------------|------------|----------|-------------|------|
| 206 | Reverse Linked List                | O(n)       | Easy       |    AC    | 2025/08/23  | [Link](https://leetcode.com/problems/reverse-linked-list/) |
| 21  | Merge Two Sorted Lists             | O(n)       | Easy       |    AC    | 2025/08/23  | [Link](https://leetcode.com/problems/merge-two-sorted-lists/) |
| 141 | Linked List Cycle                  | O(n)       | Easy       |    AC    | 2025/08/23  | [Link](https://leetcode.com/problems/linked-list-cycle/) |
| 142 | Linked List Cycle II               | O(n)       | Medium     |    AC    | 2025/08/23  | [Link](https://leetcode.com/problems/linked-list-cycle-ii/) |
| 19  | Remove Nth Node From End           | O(n)       | Medium     |    AC    | 2025/08/23  | [Link](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) |
| 160 | Intersection of Two Linked Lists   | O(n)       | Easy       |          |             | [Link](https://leetcode.com/problems/intersection-of-two-linked-lists/) |
| 234 | Palindrome Linked List             | O(n)       | Easy       |          |             | [Link](https://leetcode.com/problems/palindrome-linked-list/) |
| 92  | Reverse Linked List II             | O(n)       | Medium     |          |             | [Link](https://leetcode.com/problems/reverse-linked-list-ii/) |
| 148 | Sort List                          | O(n log n) | Medium     |          |             | [Link](https://leetcode.com/problems/sort-list/) |

---

## Stack & Queue

Stacks and Queues support parsing, evaluation, monotonic techniques, BFS, and sliding windows.

**Concept Resources**
- CMU 15-122 – Stacks and Queues: https://www.cs.cmu.edu
- OpenDSA – Stacks and Queues: https://opendsa-server.cs.vt.edu
- VisuAlgo – Stack and Queue: https://visualgo.net

### Problem List

| ID  | Title                              | Complexity     | Difficulty | Status      | Solved Date | Link |
|-----|------------------------------------|----------------|------------|-------------|-------------|------|
| 20  | Valid Parentheses                  | O(n)           | Easy       |    AC       | 2025/08/26  | [Link](https://leetcode.com/problems/valid-parentheses/) |
| 155 | Min Stack                          | O(1) per op    | Medium     |    AC       | 2025/08/27  | [Link](https://leetcode.com/problems/min-stack/) |
| 232 | Implement Queue using Stacks       | O(1) amortized | Easy       |    AC       | 2025/08/27  | [Link](https://leetcode.com/problems/implement-queue-using-stacks/) |
| 739 | Daily Temperatures                 | O(n)           | Medium     |    AC       | 2025/08/27  | [Link](https://leetcode.com/problems/daily-temperatures/) |
| 496 | Next Greater Element I             | O(m+n)         | Easy       |    AC       | 2025/08/27  | [Link](https://leetcode.com/problems/next-greater-element-i/) |
| 503 | Next Greater Element II            | O(n)           | Medium     |    AC       | 2025/08/27  | [Link](https://leetcode.com/problems/next-greater-element-ii/) |
| 84  | Largest Rectangle in Histogram     | O(n)           | Hard       |    AC       | 2025/08/28  | [Link](https://leetcode.com/problems/largest-rectangle-in-histogram/) |
| 239 | Sliding Window Maximum             | O(n)           | Hard       |    TLE      | 2025/08/30  | [Link](https://leetcode.com/problems/sliding-window-maximum/) |
| 85  | Maximal Rectangle                  | O(m·n)         | Hard       |             |             | [Link](https://leetcode.com/problems/maximal-rectangle/) |
| 622 | Design Circular Queue              | O(1)           | Medium     |             |             | [Link](https://leetcode.com/problems/design-circular-queue/) |
| 150 | Evaluate Reverse Polish Notation   | O(n)           | Medium     |             |             | [Link](https://leetcode.com/problems/evaluate-reverse-polish-notation/) |
| 641 | Design Circular Deque              | O(1)           | Medium     |             |             | [Link](https://leetcode.com/problems/design-circular-deque/) |

---

## Hash Table

Hashing enables near constant-time lookups, frequency counting, and deduplication. Core to many linear-time solutions.

**Concept Resources**
- Princeton Algorithms – Hashing (separate chaining, linear probing): https://algs4.cs.princeton.edu/34hash/
- UC Berkeley CS61B – Hash maps and hashing: https://cs61b.org
- OpenDSA – Hash Tables: https://opendsa-server.cs.vt.edu

### Problem List

| ID  | Title                             | Complexity  | Difficulty | Status | Solved Date | Link |
|-----|-----------------------------------|-------------|------------|--------|-------------|------|
| 217 | Contains Duplicate                | O(n)        | Easy       |        |             | [Link](https://leetcode.com/problems/contains-duplicate/) |
| 242 | Valid Anagram                     | O(n)        | Easy       |        |             | [Link](https://leetcode.com/problems/valid-anagram/) |
| 1   | Two Sum                           | O(n)        | Easy       |    AC  | 2025/08/20  | [Link](https://leetcode.com/problems/two-sum/) |
| 49  | Group Anagrams                    | O(n·k·logk) | Medium     |        |             | [Link](https://leetcode.com/problems/group-anagrams/) |
| 347 | Top K Frequent Elements           | O(n log k)  | Medium     |        |             | [Link](https://leetcode.com/problems/top-k-frequent-elements/) |
| 36  | Valid Sudoku                      | O(1)        | Medium     |        |             | [Link](https://leetcode.com/problems/valid-sudoku/) |
| 560 | Subarray Sum Equals K             | O(n)        | Medium     |        |             | [Link](https://leetcode.com/problems/subarray-sum-equals-k/) |
| 146 | LRU Cache                         | O(1) per op | Medium     |        |             | [Link](https://leetcode.com/problems/lru-cache/) |
| 128 | Longest Consecutive Sequence      | O(n)        | Hard       |        |             | [Link](https://leetcode.com/problems/longest-consecutive-sequence/) |
| 202 | Happy Number                      | O(n)        | Easy       |        |             | [Link](https://leetcode.com/problems/happy-number/) |
| 3   | Longest Substring Without Repeating Chars  | O(n)         | Medium     |          |             | [Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/) |
| 567 | Permutation in String                      | O(n)         | Medium     |          |             | [Link](https://leetcode.com/problems/permutation-in-string/) |
| 76  | Minimum Window Substring                   | O(n)         | Hard       |          |             | [Link](https://leetcode.com/problems/minimum-window-substring/) |

---

## Binary Tree

Binary Trees underpin recursion patterns, DFS/BFS traversals, and many path/state DP problems.

**Concept Resources**
- MIT OpenCourseWare – Trees and recursion: https://ocw.mit.edu
- OpenDSA – Binary trees and traversals: https://opendsa-server.cs.vt.edu
- VisuAlgo – Binary Trees: https://visualgo.net

### Problem List

| ID  | Title                                   | Complexity | Difficulty | Status | Solved Date | Link |
|-----|-----------------------------------------|------------|------------|--------|-------------|------|
| 104 | Maximum Depth of Binary Tree            | O(n)       | Easy       |        |             | [Link](https://leetcode.com/problems/maximum-depth-of-binary-tree/) |
| 100 | Same Tree                               | O(n)       | Easy       |        |             | [Link](https://leetcode.com/problems/same-tree/) |
| 226 | Invert Binary Tree                      | O(n)       | Easy       |        |             | [Link](https://leetcode.com/problems/invert-binary-tree/) |
| 101 | Symmetric Tree                          | O(n)       | Easy       |        |             | [Link](https://leetcode.com/problems/symmetric-tree/) |
| 102 | Binary Tree Level Order Traversal       | O(n)       | Medium     |        |             | [Link](https://leetcode.com/problems/binary-tree-level-order-traversal/) |
| 112 | Path Sum                                | O(n)       | Easy       |        |             | [Link](https://leetcode.com/problems/path-sum/) |
| 543 | Diameter of Binary Tree                 | O(n)       | Easy       |        |             | [Link](https://leetcode.com/problems/diameter-of-binary-tree/) |
| 124 | Binary Tree Maximum Path Sum            | O(n)       | Hard       |        |             | [Link](https://leetcode.com/problems/binary-tree-maximum-path-sum/) |
| 199 | Binary Tree Right Side View             | O(n)       | Medium     |        |             | [Link](https://leetcode.com/problems/binary-tree-right-side-view/) |
| 236 | Lowest Common Ancestor of a Binary Tree | O(n)       | Medium     |        |             | [Link](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) |

---

## Binary Search Tree (BST)

BSTs maintain order to support efficient search, insert, and delete. Many problems reduce to in-order traversal invariants.

**Concept Resources**
- Princeton Algorithms – BSTs and balanced trees: https://algs4.cs.princeton.edu/32bst/
- VisuAlgo – Binary Search Tree: https://visualgo.net
- UC Berkeley CS61B – BST operations and invariants: https://cs61b.org

### Problem List

| ID  | Title                                  | Complexity | Difficulty | Status | Solved Date | Link |
|-----|----------------------------------------|------------|------------|--------|-------------|------|
| 98  | Validate Binary Search Tree            | O(n)       | Medium     |        |             | [Link](https://leetcode.com/problems/validate-binary-search-tree/) |
| 700 | Search in a Binary Search Tree         | O(h)       | Easy       |        |             | [Link](https://leetcode.com/problems/search-in-a-binary-search-tree/) |
| 701 | Insert into a Binary Search Tree       | O(h)       | Medium     |        |             | [Link](https://leetcode.com/problems/insert-into-a-binary-search-tree/) |
| 450 | Delete Node in a BST                   | O(h)       | Medium     |        |             | [Link](https://leetcode.com/problems/delete-node-in-a-binary-search-tree/) |
| 235 | Lowest Common Ancestor of a BST        | O(h)       | Medium     |        |             | [Link](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) |
| 173 | Binary Search Tree Iterator            | O(h) per op| Medium     |        |             | [Link](https://leetcode.com/problems/binary-search-tree-iterator/) |
| 230 | Kth Smallest Element in a BST          | O(h)       | Medium     |        |             | [Link](https://leetcode.com/problems/kth-smallest-element-in-a-binary-search-tree/) |
| 653 | Two Sum IV Input is a BST              | O(n)       | Easy       |        |             | [Link](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) |
| 99  | Recover Binary Search Tree             | O(n)       | Hard       |        |             | [Link](https://leetcode.com/problems/recover-binary-search-tree/) |
| 538 | Convert BST to Greater Tree            | O(n)       | Medium     |        |             | [Link](https://leetcode.com/problems/convert-bst-to-greater-tree/) |

---

## Heap & Priority Queue

Heaps enable efficient retrieval of min/max and scheduling of tasks by priority.

**Concept Resources**
- Princeton Algorithms – Heaps and Priority Queues: https://algs4.cs.princeton.edu/24pq/
- VisuAlgo – Heaps: https://visualgo.net
- UC San Diego – Priority Queues notes: https://cseweb.ucsd.edu

### Problem List

| ID  | Title                                         | Complexity      | Difficulty | Status | Solved Date | Link |
|-----|-----------------------------------------------|-----------------|------------|--------|-------------|------|
| 215 | Kth Largest Element in an Array               | O(n log k)      | Medium     |        |             | [Link](https://leetcode.com/problems/kth-largest-element-in-an-array/) |
| 347 | Top K Frequent Elements                       | O(n log k)      | Medium     |        |             | [Link](https://leetcode.com/problems/top-k-frequent-elements/) |
| 23  | Merge k Sorted Lists                          | O(n log k)      | Hard       |        |             | [Link](https://leetcode.com/problems/merge-k-sorted-lists/) |
| 295 | Find Median from Data Stream                  | O(log n) per op | Hard       |        |             | [Link](https://leetcode.com/problems/find-median-from-data-stream/) |
| 502 | IPO                                           | O(n log n)      | Hard       |        |             | [Link](https://leetcode.com/problems/ipo/) |
| 703 | Kth Largest Element in a Stream               | O(log k)        | Easy       |        |             | [Link](https://leetcode.com/problems/kth-largest-element-in-a-stream/) |
| 373 | Find K Pairs with Smallest Sums               | O(k log n)      | Medium     |        |             | [Link](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/) |
| 451 | Sort Characters By Frequency                  | O(n log n)      | Medium     |        |             | [Link](https://leetcode.com/problems/sort-characters-by-frequency/) |
| 378 | Kth Smallest Element in a Sorted Matrix       | O(n log n)      | Medium     |        |             | [Link](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) |
| 621 | Task Scheduler                                | O(n log n)      | Medium     |        |             | [Link](https://leetcode.com/problems/task-scheduler/) |

---

## Graph

Graphs model networks and relationships. Core techniques: BFS/DFS, topological sort, shortest paths, and connectivity.

**Concept Resources**
- MIT OpenCourseWare – Graphs (BFS/DFS, topological sort): https://ocw.mit.edu
- CP-Algorithms – Graph algorithms (theory-first): https://cp-algorithms.com
- VisuAlgo – Graph traversals: https://visualgo.net

### Problem List

| ID  | Title                               | Complexity | Difficulty | Status | Solved Date | Link |
|-----|-------------------------------------|------------|------------|--------|-------------|------|
| 200 | Number of Islands                   | O(m·n)     | Medium     |        |             | [Link](https://leetcode.com/problems/number-of-islands/) |
| 133 | Clone Graph                         | O(V+E)     | Medium     |        |             | [Link](https://leetcode.com/problems/clone-graph/) |
| 207 | Course Schedule                     | O(V+E)     | Medium     |        |             | [Link](https://leetcode.com/problems/course-schedule/) |
| 210 | Course Schedule II                  | O(V+E)     | Medium     |        |             | [Link](https://leetcode.com/problems/course-schedule-ii/) |
| 994 | Rotting Oranges                     | O(m·n)     | Medium     |        |             | [Link](https://leetcode.com/problems/rotting-oranges/) |
| 417 | Pacific Atlantic Water Flow         | O(m·n)     | Medium     |        |             | [Link](https://leetcode.com/problems/pacific-atlantic-water-flow/) |
| 127 | Word Ladder                         | O(N·L^2)   | Hard       |        |             | [Link](https://leetcode.com/problems/word-ladder/) |
| 261 | Graph Valid Tree                    | O(V+E)     | Medium     |        |             | [Link](https://leetcode.com/problems/graph-valid-tree/) |
| 785 | Is Graph Bipartite                  | O(V+E)     | Medium     |        |             | [Link](https://leetcode.com/problems/is-graph-bipartite/) |
| 399 | Evaluate Division                   | O(V+E)     | Medium     |        |             | [Link](https://leetcode.com/problems/evaluate-division/) |

---

## Union Find

Disjoint Set Union (DSU) efficiently tracks connectivity with union-by-rank and path compression.

**Concept Resources**
- Princeton Algorithms – Union-Find (quick-find/union, weighted UF): https://algs4.cs.princeton.edu/15uf/
- CP-Algorithms – Disjoint Set Union (proofs and implementation): https://cp-algorithms.com/data_structures/disjoint_set_union.html
- VisuAlgo – Disjoint Set: https://visualgo.net

### Problem List

| ID   | Title                                        | Complexity     | Difficulty | Status | Solved Date | Link |
|------|----------------------------------------------|----------------|------------|--------|-------------|------|
| 684  | Redundant Connection                         | α(n) amortized | Medium     |        |             | [Link](https://leetcode.com/problems/redundant-connection/) |
| 721  | Accounts Merge                               | α(n) amortized | Medium     |        |             | [Link](https://leetcode.com/problems/accounts-merge/) |
| 947  | Most Stones Removed with Same Row or Column  | α(n) amortized | Medium     |        |             | [Link](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/) |
| 990  | Satisfiability of Equality Equations         | α(n) amortized | Medium     |        |             | [Link](https://leetcode.com/problems/satisfiability-of-equality-equations/) |
| 952  | Largest Component Size by Common Factor      | α(n) amortized | Hard       |        |             | [Link](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) |
| 305  | Number of Islands II                         | α(n) amortized | Hard       |        |             | [Link](https://leetcode.com/problems/number-of-islands-ii/) |
| 839  | Similar String Groups                        | α(n) amortized | Hard       |        |             | [Link](https://leetcode.com/problems/similar-string-groups/) |
| 765  | Couples Holding Hands                        | α(n) amortized | Hard       |        |             | [Link](https://leetcode.com/problems/couples-holding-hands/) |
| 128  | Longest Consecutive Sequence                 | O(n)           | Hard       |        |             | [Link](https://leetcode.com/problems/longest-consecutive-sequence/) |

---

## Other Classics

Cross-cutting problems frequently appearing in interviews. Focus on patterns: two pointers, interval merging, greedy, dynamic programming, and binary search.

**Concept Resources**
- MIT OpenCourseWare – Greedy, Dynamic Programming, and Divide & Conquer: https://ocw.mit.edu
- CP-Algorithms – Core techniques (two pointers, prefix sums, sweep line, DP): https://cp-algorithms.com
- The Algorithm Design Manual – Problem patterns and heuristics: https://www.algorist.com

### Problem List

| ID  | Title                               | Complexity     | Difficulty | Status   | Solved Date | Link |
|-----|-------------------------------------|----------------|------------|----------|-------------|------|
| 2   | Add Two Numbers                     | O(m+n)         | Medium     |    AC    | 2025/08/21  | [Link](https://leetcode.com/problems/add-two-numbers/) |
| 33  | Search in Rotated Sorted Array      | O(log n)       | Medium     |          |             | [Link](https://leetcode.com/problems/search-in-rotated-sorted-array/) |
| 56  | Merge Intervals                     | O(n log n)     | Medium     |          |             | [Link](https://leetcode.com/problems/merge-intervals/) |
| 88  | Merge Sorted Array                  | O(m+n)         | Easy       |          |             | [Link](https://leetcode.com/problems/merge-sorted-array/) |
| 42  | Trapping Rain Water                 | O(n)           | Hard       |          |             | [Link](https://leetcode.com/problems/trapping-rain-water/) |
| 152 | Maximum Product Subarray            | O(n)           | Medium     |          |             | [Link](https://leetcode.com/problems/maximum-product-subarray/) |
| 31  | Next Permutation                    | O(n)           | Medium     |          |             | [Link](https://leetcode.com/problems/next-permutation/) |
| 55  | Jump Game                           | O(n)           | Medium     |          |             | [Link](https://leetcode.com/problems/jump-game/) |
| 300 | Longest Increasing Subsequence      | O(n log n)     | Medium     |          |             | [Link](https://leetcode.com/problems/longest-increasing-subsequence/) |
| 221 | Maximal Square                      | O(m·n)         | Medium     |          |             | [Link](https://leetcode.com/problems/maximal-square/) |

---

## Learning Strategy

Build depth first, then breadth. Combine concept study with spaced repetition and targeted problem sets.

### Phase Progression
1. Foundations: Array & String → Linked List.
2. Core Patterns: Stack & Queue → Hash Table.
3. Trees: Binary Tree → BST.
4. Advanced Structures: Heap → Graph → Union Find.
5. Integration: Mixed-topic sets and systematized review of hard classics.

### Weekly Cadence
- Day 1–2: Study concepts (read/watch), then implement the data structure from scratch.
- Day 3–5: Solve 6–10 curated problems in the current topic (mix Easy/Medium; include 1–2 Hard).
- Day 6: Review errors, re-solve 2–3 previous misses from memory (no peeking).
- Day 7: Write a one-page summary (APIs, invariants, patterns, pitfalls).

### Deliberate Practice Rules
- Implement-first: Write a minimal working implementation of the structure before solving problems.
- State invariants: For each problem, write the invariant or window/stack meaning in one sentence.
- Complexity budget: Track time and space for each submission; aim for the target complexity in the table.
- Error log: Maintain a miss-log with root cause (concept gap, pattern recognition, edge case).
- Spaced repetition: Revisit misses after 24 hours, 7 days, and 30 days.

### Checkpoints
- After Hash Table: Re-derive collision strategies and compare load factor impacts.
- After BST: Implement delete from scratch (all cases) and prove in-order invariant.
- After Heap: Derive heapify and explain O(n) build-heap via bottom-up.
- After Graph: Code BFS/DFS templates and topological sort from scratch.
- After Union Find: Explain α(n) amortized via path compression and union by rank/size.

### When Stuck
- Articulate the pattern (two pointers, monotonic, prefix sums, DSU).
- Reduce to known templates (BFS with visited; sliding window with counts; stack with meaning).
- Construct minimal counterexamples to test hypotheses before coding.
