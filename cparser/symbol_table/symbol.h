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
    int index; // 为-1时表示单个int，为正数时，如果类型为表示ARRAY_TYPE表示数组大小，如果类型为INT_TYPE时表示数组下标
    char value[30]; // 变量值
} SymbolEntry;

typedef struct {
    SymbolEntry entries[100];
    int count;
} SymbolTable;

extern SymbolTable symbolTable;// 全局变量

void initializeSymbolTable(SymbolTable* table);
void addSymbol(SymbolTable* table, const char* name, DataType type, int index, char* value);
SymbolEntry* findSymbol(SymbolTable* table, const char* name, DataType type, int index);
void printfAllEntry(SymbolTable* table);


#endif
