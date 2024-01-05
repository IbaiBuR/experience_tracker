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

## UNIX-Like Systems
```bash
./experience_tracker <path_to_your_experience_file> (optional) default = experience.exp
```
## Windows
```commandline
experience_tracker.exe <path_to_your_experience_file> (optional) default = experience.exp
```

# What does it do

For now, it converts part of the experience data to readable format, and it removes all the depth <= 4 entries in the experience file.

## Sample output

### For BrainLearn-like experience files

```
Key: 8DD6190269E07728, Move: f1b1 , Score: 322   cp, Depth: 26 , Performance: 100
Key: 3E0F662B9F837A61, Move: g2g3 , Score: 267   cp, Depth: 21 , Performance: 100
Key: CDBB4A73E4F0F53 , Move: b1f1 , Score: 257   cp, Depth: 20 , Performance: 100
Key: 3E6721CB79696F37, Move: d2g2 , Score: 264   cp, Depth: 21 , Performance: 100
Key: 3E6721CB79696F37, Move: f8f7 , Score: 245   cp, Depth: 26 , Performance: 100
```

### For SugaRV2-like experience files

```
Key: 1A2DB5D97A00000 , Move: d6d5 , Score: 0     cp, Depth: 42 , Count: 126
Key: 9DF8572884600002, Move: c1h1 , Score: 2     cp, Depth: 36 , Count: 127
Key: 5BE1913CAF200002, Move: g6h5 , Score: 52    cp, Depth: 37 , Count: 120
Key: DBF14C587CC0000B, Move: h7h5 , Score: -38   cp, Depth: 27 , Count: 5
Key: CFE00D075A80000C, Move: d2b4 , Score: 8     cp, Depth: 38 , Count: 126
```

# To-Do

- [x] Defrag the experience file
- [X] Defrag with specific minimum depth
- [ ] Show experience entries for most common openings
