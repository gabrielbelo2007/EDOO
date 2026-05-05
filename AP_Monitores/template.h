#include <iostream>
using namespace std;

template<typename T, typename U>
class Par{
    private:
        T primeiro;
        U segundo;

    public:
        Par(T primeiro, U segundo) : primeiro(primeiro), segundo(segundo){};

        T getPrimeiro() const{
            return primeiro;
        }

        U getSegundo() const{
            return segundo;
        }

        void setPrimeiro(T primeiro){
            this->primeiro = primeiro;
        }

        void setSegundo(U segundo){
            this->segundo = segundo;
        }

        Par<U, T> invertido() const{
            return Par<U, T>(segundo, primeiro);
        }

        friend ostream& operator<<(ostream& os, const Par<T, U>& par){
            // Pode utilizar os .primeiro e .segundo, por ser Friend
            os << "(" << par.getPrimeiro() << ", " << par.getSegundo() << ")";
            return os;
        }
};
