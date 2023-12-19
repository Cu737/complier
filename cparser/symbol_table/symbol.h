#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef enum {
    INT_TYPE,
    FLOAT_TYPE,
    CHAR_TYPE,
    ARRAY_TYPE,
    POINTER_TYPE
} DataType;

typedef struct {
    char name[30];
    DataType type;
    int size; // for arrays
    int address; // memory address
} SymbolEntry;

typedef struct {
    SymbolEntry entries[100];
    int count;
} SymbolTable;

void initializeSymbolTable(SymbolTable* table);
void addSymbol(SymbolTable* table, const char* name, DataType type, int size, int address);
SymbolEntry* findSymbol(SymbolTable* table, const char* name);

#endif
