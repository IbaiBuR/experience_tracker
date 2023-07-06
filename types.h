#ifndef TYPES_H
#define TYPES_H
 #include <stdint.h>
 #define SIZE_READ 512
 
 typedef struct BL_EXP_ENTRY
 {
   uint64_t key;
   int32_t depth, score, move, performance;
 }BL_EXP_ENTRY;

 typedef struct MOVE
 {
   unsigned first_rank : 3;
   unsigned first_letter : 3;
   unsigned second_rank : 3;
   unsigned second_letter : 3;
 }MOVE;

 //Both of this functions write all the experience entries to a human readable format into a txt file
 void write_BLexp_entry_toTxTFile(FILE *, FILE *); 
 void delete_depth0_entries(FILE *, FILE *);
 char *  move_from_decimal(int32_t);
#endif