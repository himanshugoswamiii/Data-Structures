# Hash Table

It's a data structure

*Storing and Retrieving data in O(1) time*
Search Key(24,52,91,67,48,83)
Hash Table
Hash function (kmod 10, k mod n, Mid Square, Folding Method)

Storing data in Hash Table (we're using k mod 10)
Key =24 then 24 mod 10 = 4 => Hash value =4 (so we'll put 24 at 4th index in table)

K=52 then 52 mod 10=2 => 2nd index

Similary we can do searching

---

## Collision Resolution Technique

Suppose we enter 62 then , 62 mod 10=2

Ex: Keys(24,19,32,44)
In case of: k mod 6

| Index | Key |
| ----- | --- |
| 0     | 24  |
| 1     | 19  |
| 2     | 32  |
| 3     |     |
| 4     |     |
| 5     |     |

44 will go to index 2 but 32 is already there

Chaining (Open Hashing)

Open Addressing (Closed Hashing)

- Linear Probing
- Quadratic Probing
- Double Hashing

### Open Hashing

I'll create a chain with 32

[Reference](https://www.educba.com/hashing-function-in-c/)
[Reference Programiz](https://www.programiz.com/dsa/hash-table)