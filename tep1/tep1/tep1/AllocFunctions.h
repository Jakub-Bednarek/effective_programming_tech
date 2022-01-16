#pragma once
#include <iostream>
#include "CTable.h"

#define DEFAULT_ARRAY_SIZE 10
#define NUMBER_TO_ADD 5

void v_alloc_table_add_5(int iSize);

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY);

bool b_dealloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY);

void v_mod_tab(CTable* pcTab, int iNewSize);

void v_mod_tab(CTable cTab, int iNewSize);

void v_fill_array(int** piArray, int iSizeX, int iSizeY);