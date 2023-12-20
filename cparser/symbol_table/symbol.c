#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SymbolTable symbolTable;

void initializeSymbolTable(SymbolTable* table) {
    table->count = 0;
}

void addSymbol(SymbolTable* table, const char* name, DataType type, int index, char* value) {
    if (table->count < 100) {
        SymbolEntry* entry = &table->entries[table->count++];
        strncpy(entry->name, name, sizeof(entry->name));
        entry->type = type;
        entry->index = index;
        strncpy(entry->value, value, sizeof(entry->value));
    } else {
        printf("Error: Symbol table is full.\n");
    }
}

SymbolEntry* findSymbol(SymbolTable* table, const char* name, DataType type, int index) {
    for (int i = 0; i < table->count; ++i) {
        if ((strcmp(table->entries[i].name, name) == 0) && (table->entries[i].type == type) && (table->entries[i].index == index)) {
            return &table->entries[i];
        }
    }
    return NULL; // Symbol not found
}

void printfAllEntry(SymbolTable* table)
{
    int count = table->count;
    for (int i =0;i < count;i++)
    {
        SymbolEntry* entry = table->entries[i];
        printf("Name: %s\tType: %d\tIndex: %d\n", entry->name, entry->type, entry->index);
    }
}
