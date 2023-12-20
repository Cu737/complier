#include "dag.h"

DAGNode create_dag_node(char* value, int left, int right, int is_leaf, char*variable) {
    DAGNode node;
    node.value = value;
    node.left = left;
    node.right = right;
    node.is_leaf = is_leaf;
    node.var_len = 0;
    node.visited = 0;
    if(variable!=NULL){
        node.varibales[node.var_len++] = variable;
    }
    return node;
}

void free_dag_node(DAGNode* node) {
    free(node->value);
}