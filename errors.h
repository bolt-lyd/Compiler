#include <string>
using namespace std;

class errors{
    private:
        bool errorStatus = false;
    public:
        void reportError(char *message);
        void reportWarning(char *message);
        bool getErrorStatus();
};