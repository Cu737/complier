#include "symbol.h"

int main() {
    initializeSymbolTable(&symbolTable);

    // 添加一些符号到符号表中
    addSymbol(&symbolTable, "variable1", INT_TYPE, 0, 100);
    addSymbol(&symbolTable, "array1", ARRAY_TYPE, 10, 200);
    addSymbol(&symbolTable, "pointer1", POINTER_TYPE, 0, 300);

    // 查找符号并打印信息
    SymbolEntry* entry = findSymbol(&symbolTable, "variable1");
    if (entry) {
        printf("Name: %s\nType: %d\nAddress: %d\n", entry->name, entry->type, entry->address);
    } else {
        printf("Symbol not found.\n");
    }

    return 0;
}
