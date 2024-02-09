#include <string>
#include "token.h"
using namespace std;

// Define HashTable items
typedef struct hashItem
{
    /* data */
    char* key;
    char* value;
};

// Define Table itself
                //should the items in table be tokens?
typedef struct hashTable
{
    // Contains array of pointers to items
    hashItem** items;
    int size;
    int count;
};



class symbolTable{
    private:
        //hashTable <token> symTab;
        hashTable symTab;
    public:
        token hashLook(string); // lookup the string in the hash table and call create function if not found
        void setToken(string); // change the token values for this symbol
};