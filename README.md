# Hashing

Hash tables are one of the most ubiquitous data structures in software engineering, and a lot of effort has been placed into getting them to work quickly and efficiently. In lecture, we coded up chained hashing. We also talked about two other hashing approaches:

Linear Probing: A hashing strategy where items can “leak out” of the slots they’re supposed to stay in. This strategy is surprisingly fast in practice!
Robin Hood Hashing: This slight modification on linear probing “smooths out” the cost of lookups in a linear probing table, which leads to some interesting consequences.
Your task in this assignment is to code up these two hashing strategies and evaluate their performance against chained hashing. How do they hold up in practice? Which hash table implementations tend to work well in which scenarios?
