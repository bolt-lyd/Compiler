#include <string>
using namespace std;

class symbolTable{
    private:
        hashTable<token> symTab;
    public:
        token hashLook(string); // lookup the string in the hash table
        void setToken(string); // change the token values for this symbol
};