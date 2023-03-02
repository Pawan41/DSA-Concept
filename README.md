DSA-Concept
✅What is segment tree

✅A segment tree is a data structure used to store information about array segments and answer segment queries efficiently. There are two main operations performed on a segment tree:
1️⃣range(i, j): gives the sum of the array elements starting at index i and ending at index j.
2️⃣update(i, val): updates the value at index i to the val in the original array and updates the segment tree accordingly.
✅Both range(i, j) and update(i, val) take O(log(n)) time, where n is the number of elements in the segment tree.


✅Segment Trees can be used to solve Range Min/Max & Sum Queries and Range Update Queries in O (log n) time. These problems can be easily solved with the Segment Tree technique. We can study this method by solving such a problem efficiently. Basically, a Segment Tree has only three operations:

1️⃣Building Tree: in this step, we create the structure of the segment tree variable and initialize it.
2️⃣Updating Tree: during this step, we change the tree by updating the value in the array at a point or over an interval.
3️⃣Querying Tree: we may use this operation to run a range query on the array.


