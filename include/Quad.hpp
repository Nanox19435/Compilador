#include <string>
using namespace std;

enum OPERATOR {
    /*operadores*/
};

class Quad
{
    private:
        OPERATOR op;
        string arg1;
        string arg2;
        string res;

        int type;

        bool mutArg1;
        bool mutArg2;
    public:
        Quad();
        Quad(OPERATOR op, string arg1, string arg2, string res);
        Quad(OPERATOR op, string arg1, bool typeArg1, string arg2, bool typeArg2, string res, int type);
        ~Quad();
        void print();
};
