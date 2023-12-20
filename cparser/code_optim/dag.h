#ifndef DAG_H
#define DAG_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_DAG_SIZE 1024
typedef struct {
    char* value;
    int left;
    int right;
    int is_leaf;  // 1 if the node is a leaf (contains a value), 0 otherwise
    int var_len;
    char* varibales[MAX_DAG_SIZE];
    int visited;
} DAGNode;

DAGNode create_dag_node(char* value, int left, int right, int is_leaf, char*variable);

void free_dag_node(DAGNode* node);
#endif //DAG_H