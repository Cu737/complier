#include "basic_block.h"
int compare( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

struct FourGroup* find_quadruple_by_id(struct FourGroup* start, int target_id) {
    while (start != NULL) {
        if (start->id == target_id) {
            return start;  // Found the quadruple with the target ID
        }
        start = start->next;
    }
    return NULL;  // Quadruple with the target ID not found
}

BasicBlock create_basic_block(struct FourGroup* quadruples, int size) {
    BasicBlock block;
    block.quadruples = quadruples;
    block.size = size;
    return block;
}

void generate_basic_blocks(struct FourGroup* quadruples, int num_quadruples, BasicBlock** basic_blocks, int* num_blocks) {
    // printf("num_quadruples:%d\n", num_quadruples);
    int* leaders = (int*)malloc(num_quadruples * sizeof(int));
    int num_leaders = 0;
    struct FourGroup* current = quadruples;

    // Identify leaders
    leaders[num_leaders++] = 1;  // Assume the first quadruple is leader

    while (current != NULL) {
        if (strcmp(current->op, "Jump") == 0 || strcmp(current->op, "JumpIf") == 0) {
            if(current->id != num_quadruples){
                leaders[num_leaders++] = current->id + 1;  // Quadruple following jump is leader
            }
            int jump_target = atoi(current->jump);
            if (jump_target > 0) {
                leaders[num_leaders++] = jump_target;
            }
        }
        current = current->next;
    }

    qsort(leaders, num_leaders, sizeof(int), compare);

    // Create basic blocks
    *num_blocks = num_leaders;
    *basic_blocks = (BasicBlock*)malloc(num_leaders * sizeof(BasicBlock));

    // Reset current pointer to the beginning of the list
    current = quadruples;

    for (int i = 0; i < num_leaders - 1; ++i) {
        int start_index = leaders[i];
        int end_index = leaders[i + 1];
        int block_size = end_index - start_index;
        if (block_size == 0)
            continue;
        struct FourGroup* block_quadruples = find_quadruple_by_id(current, start_index);
        (*basic_blocks)[i] = create_basic_block(block_quadruples, block_size);
    }

    // Handle the last basic block
    int start_index = leaders[num_leaders - 1];
    int block_size = num_quadruples - start_index + 1;
    struct FourGroup* block_quadruples = find_quadruple_by_id(current, start_index);
    (*basic_blocks)[num_leaders - 1] = create_basic_block(block_quadruples, block_size);
}

DAGNode* convert_to_dag(BasicBlock* block, int* dag_size){
        DAGNode* dag = (DAGNode*)malloc(MAX_DAG_SIZE * sizeof(DAGNode));
        struct FourGroup* current = block->quadruples;
        int block_size = block->size;
       
        printf("block_size: %d\n", block_size);
        
        for (int i = 0; i < block_size && current != NULL; ++i) {
            int left = -1, right = -1;
            
            // Create or find a leaf node for current->add1
            for (int i = (*dag_size) - 1; i >=0 ; --i) {
                if (dag[i].is_leaf && strcmp(dag[i].value, current->add1) == 0) {
                    left = i;
                    break;
                }
                else{
                    for(int j=0; j<dag[i].var_len; ++j){
                        if(strcmp(dag[i].varibales[j], current->add1) == 0){
                            left = i;
                            break;
                        }
                    }
                }
            }

            // If not found, create a new leaf node
            if (left == -1) {
                dag[(*dag_size)++] = create_dag_node(current->add1, -1, -1, 1, NULL);  // 1 indicates a leaf node
                left = *dag_size - 1;
            }

            // Create or find a leaf node for current->add2
            for (int i = (*dag_size) - 1; i >=0 ; --i) {
                if (dag[i].is_leaf && strcmp(dag[i].value, current->add2) == 0) {
                    right = i;
                }
                else{
                    for(int j=0; j<dag[i].var_len; ++j){
                        if(strcmp(dag[i].varibales[j], current->add2) == 0){
                            right = i;
                            break;
                        }
                    }
                }
            }
            // If not found, create a new leaf node
            if (right == -1) {
                dag[(*dag_size)++] = create_dag_node(current->add2, -1, -1, 1, NULL);  // 1 indicates a leaf node
                right = *dag_size - 1;
            }

            

            // Create or find a non-leaf node for the current operation
            int op_node_index = -1;
            for (int i = (*dag_size) - 1; i >=0 ; --i) {
                if (!dag[i].is_leaf && strcmp(dag[i].value, current->op) == 0 &&
                    dag[i].left == left && dag[i].right == right) {
                    op_node_index = i;
                    for (int j=0; j<=dag[i].var_len; ++j){
                        if(j == dag[i].var_len){
                            dag[i].varibales[dag[i].var_len++] = current->jump;
                            break;
                        }
                        if(strcmp(dag[i].varibales[j], current->jump) == 0)
                            break;
                    }    
                    
                    break;
                }
            }

            // If not found, create a new non-leaf node
            if (op_node_index == -1) {
                dag[(*dag_size)++] = create_dag_node(current->op, left, right, 0, current->jump);  // 0 indicates a non-leaf node
                op_node_index = *dag_size - 1;
            }

            current = current->next;
            //printf("i: %d \t dag_size: %d\n", i, *dag_size);

        }

        return dag;

}


void convert_dag_to_tac(DAGNode* dag, int current_index) {
    if (current_index == -1) 
        return;
    
    DAGNode* current_node = &dag[current_index];

    if(current_node->visited)
        return;
    current_node->visited = 1;

    // Generate code based on node type
    if (current_node->is_leaf) {
        // Leaf node represents a variable or constant
        printf("initial value = %s\n", current_node->value);
    } else {
        // Non-leaf node represents an operation
        // Recursively generate code for left and right children
        convert_dag_to_tac(dag, current_node->left);
        convert_dag_to_tac(dag, current_node->right);
        char* add1;
        char* add2;
        if(dag[current_node->left].is_leaf){
            add1 = dag[current_node->left].value;
        }
        else{
            add1 = dag[current_node->left].varibales[0];
        }
        if(dag[current_node->right].is_leaf){
            add2 = dag[current_node->right].value;
        }
        else{
            add2 = dag[current_node->right].varibales[0];
        }
        insert(current_node->value, add1, add2, current_node->varibales[0]);
        for(int i=1; i<current_node->var_len; ++i){
            insert("=", current_node->varibales[0], "$", current_node->varibales[i]);
        }
    }
}


// DAG-based optimization function
void optimize_basic_blocks(BasicBlock* basic_blocks, int num_blocks) {
    FourGroupId = 1;
    head = NULL;
    for (int i = 0; i < num_blocks; ++i) {
        BasicBlock* block = &basic_blocks[i];
        int dag_size = 0;
        // Build DAG
        printf("===============Three Address Code to DAG==================\n");
        DAGNode* dag = convert_to_dag(block, &dag_size);
        printf("===============DAG to Three Address code==================\n");
        for(int i=0; i<dag_size; ++i){
            convert_dag_to_tac(dag, i);
        }
        printf("===============Block               Ended==================\n");
    }
}


void print_basic_block(BasicBlock* block) {
    struct FourGroup* current = block->quadruples;
    int block_size = block->size;
    for (int i = 0; i < block_size && current != NULL; ++i) {
        printf("%s %s %s %s\n", current->op, current->add1, current->add2, current->jump);
        current = current->next;
    }
}


void print_basic_blocks(BasicBlock* basic_blocks, int num_blocks) {
    for (int i = 0; i < num_blocks; ++i) {
        printf("Basic Block %d:\n", i + 1);
        print_basic_block(&basic_blocks[i]);
        printf("\n");
    }
}

void test1()
{
    insert("+", "b", "c", "a");
    insert("-", "a", "e", "d");
    insert("+", "b", "c", "a");
    insert("-", "a", "e", "f");
    insert("Jump", "$", "$", "2");
    insert("*", "d", "f", "g");
}

void test2(){
    // insert("=","50","$","a");
    // insert("-","0","1","temp0");
    // insert("=","temp0","$","sum");
    // insert("=","0","$","i");
    // insert("*","a","2","temp1");
    // insert("<","i","temp1","temp2");
    // insert("JumpIf","temp2","$","9");
    // insert("Jump","$","$","43");
    // insert("=","0","$","j");
    // insert("<","j","a","temp3");
    // insert("JumpIf","temp3","$","13");
    // insert("Jump","$","$","40");
    // insert("/","a","2","temp4");
    // insert("<","j","temp4","temp5");
    // insert("%","j","2","temp6");
    // insert("!=","temp6","0","temp7");
    // insert("&&","temp5","temp7","temp8");
    // insert("JumpIf","temp8","$","20");
    // insert("Jump","$","$","26");
    insert("*","i","j","temp9");
    insert("/","temp9","2","temp10");
    insert("+","sum","temp10","temp11");
    insert("*","i","j","temp12");
    insert("+","temp11","temp12","temp13");
    insert("=","temp13","$","sum");
    // insert(">","sum","j","temp14");
    // insert("!","sum","$","temp15");
    // insert("%","temp15","2","temp16");
    // insert("==","temp16","1","temp17");
    // insert("||","temp14","temp17","temp18");
    // insert("JumpIf","temp18","$","33");
    // insert("Jump","$","$","37");
    // insert("/","3","2","temp19");
    // insert("-","sum","temp19","temp20");
    // insert("=","temp20","$","sum");
    // insert("Jump","$","$","26");
    // insert("=","j","$","temp21");
    // insert("+","j","1","j");
    // insert("Jump","$","$","10");
    // insert("=","i","$","temp22");
    // insert("+","i","1","i");
    // insert("Jump","$","$","5");
}

void test3(){
    insert("ToAdress","a","$","temp0");
    insert("=","1","$","temp0");
    insert("+","a","1","temp1");
    insert("ToAdress","temp1","$","temp2");
    insert("=","2","$","temp2");
    insert("+","a","2","temp3");
    insert("ToAdress","temp3","$","temp4");
    insert("=","3","$","temp4");
}

int main() {

    test3();
    
    //Original Three Address Code
    printFourGroup();
    printf("\n");
    
    BasicBlock* basic_blocks;
    int num_blocks;
    generate_basic_blocks(head, FourGroupId - 1, &basic_blocks, &num_blocks);

    //printf("Original Basic Blocks:\n");
    //print_basic_blocks(basic_blocks, num_blocks);

    optimize_basic_blocks(basic_blocks, num_blocks);
    
    //Optimized Three Address Code
    printf("\n");
    printFourGroup();

    // Free allocated memory
    free(basic_blocks);

    return 0;

}