#ifndef FIGURA_H
#define FIGURA_H

class FiguraGeometrica{

    private:
        int x, y;

    public:

        FiguraGeometrica(int x, int y) : x(x), y(y){}
        virtual ~FiguraGeometrica(){};

        virtual int area() = 0;
};

#endif