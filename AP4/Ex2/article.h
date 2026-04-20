#include <string>
#ifndef ARTICLE_H
#define ARTICLE_H
using namespace std;

inline int counter = 0;

class Article{

    private:

        long number;
        string name;
        double price;

    public:
    
        ~Article();
        Article(long number = 0, const string& name = "default", double price = 0.0);
        void display();
        
        void set_number(long number);
        void set_name(const string& name);
        void set_price(double price);

        long get_number() const;
        const string& get_name() const;
        double get_price() const;
};

inline long Article::get_number() const{
    return number;
}

inline const string& Article::get_name() const{
    return name;
}

inline double Article::get_price() const{
    return price;
}

#endif