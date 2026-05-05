#include <string>
#ifndef ARTICLE_PLUS_H
#define ARTICLE_PLUS_H
using namespace std;

class ArticlePlus{

    private:

        static int articles_counter;
        long number;
        string name;
        double price;

    public:
    
        ~ArticlePlus();
        ArticlePlus(long number = 0, const string& name = "default", double price = 0.0);
        ArticlePlus(const ArticlePlus &obj);
        void display();
        
        void set_number(long number);
        void set_name(const string& name);
        void set_price(double price);

        long get_number() const;
        const string& get_name() const;
        double get_price() const;

        static int get_count();
};

inline long ArticlePlus::get_number() const{
    return number;
}

inline const string& ArticlePlus::get_name() const{
    return name;
}

inline double ArticlePlus::get_price() const{
    return price;
}

inline int ArticlePlus::get_count(){
    return articles_counter;
}

#endif