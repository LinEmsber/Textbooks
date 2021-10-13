# Chapter 2

## 2.1 Introduction
- Locality occurs in time (temporal locality) and space (spatial locality).
- High-end processors have moved to multiple cores, further increasing the bandwidth requirements versus single cores.
- The large second or third level cache will consume significant power both as leakage when not operating (called static power) and as active power, as when performing a read or write (called dynamic power)

## Basics of Memory Hierarchies: A Quick Review
- Cache Mapping
  - The most popular scheme is set associative, where a set is a group of blocks in the cache. A block is first mapped onto a set, and then the block can be placed anywhere within that set. Search the set in parallel to find the block. The set is chosen by the address of the data:
    - (Block address) MOD (Number of sets in cache)
  - If there are n blocks in a set, the cache placement is called n-way set associative.
  - A direct-mapped cache has one block per set (so a block is always placed in the same location).
  - A fully associative cache has one set (so a block can be placed anywhere)
- Data copy
  - A write-through cache updates the item in the cache and writes through to update main memory.
 - A write-back cache only updates the copy in the cache. When the block is about to be replaced, it is copied back to memory.
 - Both write strategies can use a write buffer to allow the cache to proceed as soon as the data are placed in the buffer rather thna wait the full latency to write the data into memory.
- Cache Miss Rate
  - The cache miss rate: the number of accesses that miss divided by the number of accesses.
  - Compulsory - The very first access to a block cannot be in the cache.
  - Capacity - If the cache cannot contain all the blocks needed during execution of a program, capacity missed (in addition to compulsory misses) will occur because of blocks being discarded and later retrieved.
  - Conflict - If the block placement strategies is not fully associative, conflict misses (in addition to compulsory and capacity misses) will occur because a block may be discarded and later retrieved if multiple blocks map to its and accesses to the different blocks are intermingled.
