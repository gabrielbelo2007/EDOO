#include <string>
#ifndef ARTICLE_H
#define ARTICLE_H
using namespace std;

class Article{

    private:

        long number;
        string name;
        double price;

    public:

        Article();
        ~Article();
        Article(long number, const string& name, double price);
        void display();
        
        void set_number(long number);
        void set_name(string name);
        void set_price(double price);

        long get_number();
        string get_name();
        double get_price();
};

#endif