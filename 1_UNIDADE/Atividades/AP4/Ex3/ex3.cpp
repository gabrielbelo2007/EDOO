#include <iostream>
#include "article_plus.h"
using namespace std;

ArticlePlus a1;

void test();
void copy_test(ArticlePlus);

int main(){

//    Article a2(10, "first article", 99.9);
//    a2.display();

//    test();
//    test();

//    a2.set_name("last article");
//    a2.set_number(a2.get_number() + 1);
//    a2.set_price(10);

//   a2.display();

    copy_test(a1);
    ArticlePlus::get_count();

    return 0;
}

void test(){

    static ArticlePlus a3(11, "Static Article", 80);
    ArticlePlus a4(789, "test article");

    a3.display();
    a4.display();

    a3.set_number(a3.get_number() + 1);
    a4.set_number(a4.get_number() + 1);

    cout << "end of test!" << endl;
}

void copy_test(ArticlePlus copy_article){

    copy_article.display();
}