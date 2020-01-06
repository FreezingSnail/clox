#include <stdio.h>                      

#include "memory.h"                     
#include "value.h"

void initValueArray(ValueArray* array) {
	array->count = 0;
	array->capacity = 0;
	array->values = NULL;
}

void freeValueArray(ValueArray * array){
	FREE_ARRAY(Value, array->values, array->capacity);
	initValueArray(array);
}

void writeValueArray(ValueArray* array, Value byte){
	if(array->capacity < array->count + 1){
		int oldCapacity = array->capacity;
		array->capacity = GROW_CAPACITY(oldCapacity);
		array->values = GROW_ARRAY(array->values, Value, oldCapacity, array->capacity);
	}

	array->values[array->count] = byte;
	array->count++;
}

void printValue(Value value){
    printf("%g", value);
}