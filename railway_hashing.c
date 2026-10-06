#include <stdio.h>

#define SIZE 11
#define EMPTY -1

int hash1(int key)
{
    return key % SIZE;
}

int hash2(int key)
{
    return 7 - (key % 7);
}

void initialize(int table[])
{
    for (int i = 0; i < SIZE; i++)
        table[i] = EMPTY;
}

void linearInsert(int table[], int key)
{
    int h = hash1(key);
    int i = 0;

    while (table[(h + i) % SIZE] != EMPTY)
        i++;

    table[(h + i) % SIZE] = key;
}

void quadraticInsert(int table[], int key)
{
    int h = hash1(key);
    int i = 0;

    while (table[(h + i * i) % SIZE] != EMPTY)
        i++;

    table[(h + i * i) % SIZE] = key;
}

void doubleInsert(int table[], int key)
{
    int h1 = hash1(key);
    int h2 = hash2(key);
    int i = 0;

    while (table[(h1 + i * h2) % SIZE] != EMPTY)
        i++;

    table[(h1 + i * h2) % SIZE] = key;
}

int linearSearch(int table[], int key)
{
    int h = hash1(key);

    for (int i = 0; i < SIZE; i++)
    {
        int index = (h + i) % SIZE;

        if (table[index] == EMPTY)
            return i + 1;

        if (table[index] == key)
            return i + 1;
    }

    return SIZE;
}

int quadraticSearch(int table[], int key)
{
    int h = hash1(key);

    for (int i = 0; i < SIZE; i++)
    {
        int index = (h + i * i) % SIZE;

        if (table[index] == EMPTY)
            return i + 1;

        if (table[index] == key)
            return i + 1;
    }

    return SIZE;
}

int doubleSearch(int table[], int key)
{
    int h1 = hash1(key);
    int h2 = hash2(key);

    for (int i = 0; i < SIZE; i++)
    {
        int index = (h1 + i * h2) % SIZE;

        if (table[index] == EMPTY)
            return i + 1;

        if (table[index] == key)
            return i + 1;
    }

    return SIZE;
}

void display(int table[])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] == EMPTY)
            printf("[%d] : EMPTY\n", i);
        else
            printf("[%d] : %d\n", i, table[i]);
    }
}

int main()
{
    int keys[] = {23, 43, 13, 33, 53, 63, 73};
    int n = 7;

    int linear[SIZE], quadratic[SIZE], doubleHash[SIZE];

    initialize(linear);
    initialize(quadratic);
    initialize(doubleHash);

    for (int i = 0; i < n; i++)
    {
        linearInsert(linear, keys[i]);
        quadraticInsert(quadratic, keys[i]);
        doubleInsert(doubleHash, keys[i]);
    }

    printf("LINEAR PROBING\n");
    display(linear);

    printf("\nQUADRATIC PROBING\n");
    display(quadratic);

    printf("\nDOUBLE HASHING\n");
    display(doubleHash);

    printf("\nLOAD FACTOR = %.4f\n", (float)n / SIZE);

    int searchKeys[] = {53, 73, 12};

    printf("\nSEARCH RESULTS\n");
    printf("Key\tLinear\tQuadratic\tDouble Hash\n");

    for (int i = 0; i < 3; i++)
    {
        int key = searchKeys[i];

        printf("%d\t%d\t%d\t\t%d\n",
               key,
               linearSearch(linear, key),
               quadraticSearch(quadratic, key),
               doubleSearch(doubleHash, key));
    }

    return 0;
}