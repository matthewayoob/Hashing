# Hashing

Hash tables are one of the most ubiquitous data structures in SWE, and a lot of effort has been placed into getting them to work quickly and efficiently. This project implements two hashing approaches including

**Linear Probing:**
A hashing strategy where items can “leak out” of the slots they’re supposed to stay in. This strategy is surprisingly fast in practice!

**Robin Hood Hashing: **
This slight modification on linear probing “smooths out” the cost of lookups in a linear probing table, which leads to some interesting consequences.
