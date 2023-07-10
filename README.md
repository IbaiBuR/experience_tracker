# Experience Tracker

Well, this is a simple project I wanted to overcome in order to decode and extract data from experience files, which are similar to a
[persistent hash table](https://www.chessprogramming.org/Persistent_Hash_Table).

# What is the format of the experience files?

For both [BrainLearn](https://github.com/amchess/BrainLearn), [ShashChess](https://github.com/amchess/ShashChess) and Eman the format is the following:

- 8 bytes to store the position's key, which is a [zobrist hash](https://www.chessprogramming.org/Zobrist_Hashing)
- 4 bytes to store the rest
  - Score, Depth, Move and Performance in the case of BrainLearn and ShashChess
  - Score, Depth, Move and Count in the case of Eman

So, each experience entry has a size of 24 bytes (192 bits)

# How to use it?

Its basic use is:

- ./experience_tracker experience.exp (for Linux)
- experience_tracker.exe experience.exp (for Windows)

# What does it do

For now, it converts part of the experience data to readable format and it removes all the depth 0 entries in the experience file

## Example

This is some sample output for the tool

```
Key: 537202e6, Move: a5b5, Score: -1, Depth: 54, Performance: 100
Key: be03c7e3, Move: c8c5, Score: -47, Depth: 25, Performance: 100
Key: 5b93aa11, Move: f6g5, Score: -8, Depth: 34, Performance: 100
Key: f53d4941, Move: e6e5, Score: -15, Depth: 31, Performance: 100
Key: 57de86fd, Move: f2c5, Score: 162, Depth: 32, Performance: 100
```

# To-Do

- [x] Defrag the experience file
- [X] Defrag with specific minimum depth
- [ ] Show experience entries for most common openings
