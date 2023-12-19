#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeSymbolTable(SymbolTable* table) {
    table->count = 0;
}

void addSymbol(SymbolTable* table, const char* name, DataType type, int size, int address) {
    if (table->count < 100) {
        SymbolEntry* entry = &table->entries[table->count++];
        strncpy(entry->name, name, sizeof(entry->name));
        entry->type = type;
        entry->size = size;
        entry->address = address;
    } else {
        printf("Error: Symbol table is full.\n");
    }
}

SymbolEntry* findSymbol(SymbolTable* table, const char* name) {
    for (int i = 0; i < table->count; ++i) {
        if (strcmp(table->entries[i].name, name) == 0) {
            return &table->entries[i];
        }
    }
    return NULL; // Symbol not found
}
