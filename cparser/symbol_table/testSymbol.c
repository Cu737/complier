#include "symbol.h"

int main() {
    initializeSymbolTable(&symbolTable);

    // 添加一些符号到符号表中
    addSymbol(&symbolTable, "variable1", INT_TYPE, -1, "值1");//int变量
    addSymbol(&symbolTable, "array1", ARRAY_TYPE, 10, "");//数组名和大小
    addSymbol(&symbolTable, "array1", INT_TYPE, 0, "值2");//数组中的第一个元素
    addSymbol(&symbolTable, "array1", INT_TYPE, 1, "值3");//数组中的第二个元素
    addSymbol(&symbolTable, "pointer1", POINTER_TYPE, -1, "地址");

    // 查找符号并打印信息
    SymbolEntry* entry = findSymbol(&symbolTable, "array1", INT_TYPE, 0);
    if (entry) {
        printf("Name: %s\nType: %d\nIndex: %d\nValue: %s\n", entry->name, entry->type, entry->index, entry->value);
    } else {
        printf("Symbol not found.\n");
    }

    return 0;
}
