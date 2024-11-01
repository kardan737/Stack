#ifndef COMPIL_H
#define COMPIL_H

struct signature
    {
    long long sig;
    size_t versComand;
    int sizee;
    };

struct masks
    {
    char name[50];
    int index;
    };

struct listMarks
    {
    masks listt[LENGTH_ARRAY_MASKS];
    size_t index;
    };

struct ass_mas
    {
    int* code;
    size_t capasity;
    int sizee;
    };
