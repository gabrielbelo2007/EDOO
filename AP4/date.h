#ifndef DATE_H
#define DATE_H

class Date {
    private:

        int day;
        int month;
        int year;

    public:

        Date();

        Date(int day, int month, int year);

        void display();
};

#endif