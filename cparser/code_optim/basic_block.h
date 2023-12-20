#ifndef BASICBLOCK_H
#define BASICBLOCK_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../quadruples.h"
#include "dag.h"
typedef struct {
    struct FourGroup* quadruples;
    int size;
} BasicBlock;

BasicBlock create_basic_block(struct FourGroup* quadruples, int size);

void generate_basic_blocks(struct FourGroup* quadruples, int num_quadruples, BasicBlock** basic_blocks, int* num_blocks);

void optimize_basic_blocks(BasicBlock* basic_blocks, int num_blocks);

void print_basic_block(BasicBlock* block);

void print_basic_blocks(BasicBlock* basic_blocks, int num_blocks);
#endif //BASICBLOCK_H