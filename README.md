# Experience Tracker

Well, this is a simple project I wanted to overcome in order to decode and extract data from experience files, which are similar to a
[persistent hash table](https://www.chessprogramming.org/Persistent_Hash_Table).

# What is the format of the experience files?

For both [BrainLearn](https://github.com/amchess/BrainLearn), [ShashChess](https://github.com/amchess/ShashChess) and Eman the format is the following:

- 8 bytes to store the position's key, which is a [zobrist hash](https://www.chessprogramming.org/Zobrist_Hashing)
- 4 bytes to store the rest
  - Score, Depth, Move and Performance in the case of BrainLearn and ShashChess
  - Score, Depth, Move and Count in the case of Eman

So, each experience entry has a size of 24 bytes (192 bits).

# How to use it?

Its basic use is:

- ./experience_tracker experience.exp (for Linux)
- experience_tracker.exe experience.exp (for Windows)

# What does it do

For now, it converts part of the experience data to readable format, and it removes all the depth 0 entries in the experience file.

## Example

This is some sample output for the tool (which as of now only handles BrainLearn-like experience files)

```
Key: 8DD6190269E07728, Move: f1b1 , Score: 508   cp, Depth: 26 , Performance: 100
Key: 3E0F662B9F837A61, Move: g2g3 , Score: 422   cp, Depth: 21 , Performance: 100
Key: CDBB4A73E4F0F53 , Move: b1f1 , Score: 406   cp, Depth: 20 , Performance: 100
Key: 3E6721CB79696F37, Move: d2g2 , Score: 417   cp, Depth: 21 , Performance: 100
Key: 3E6721CB79696F37, Move: f8f7 , Score: 387   cp, Depth: 26 , Performance: 100
```

# To-Do

- [x] Defrag the experience file
- [X] Defrag with specific minimum depth
- [ ] Show experience entries for most common openings
