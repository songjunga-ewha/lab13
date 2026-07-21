#pragma once
#include <iostream>
#include <iomanip>
#include "timeException.h"

namespace songjunga2549023
{
    class timeOfDay
    {
    protected: 
        int hour{};
        int minute{};
        void testHour(){
            if ( hour< 0 || hour > 23 ) 
            //std::cout << "invalid hour\n"; std::exit(1);
            throw timeException{"invalid hour\n"};
            
            
        }
        
        void testMinute(){
            if( minute< 0 || minute >59 ) 
            //std::cout << "invalid hour\n"; std::exit(1);
            throw timeException{"invalid minute\n"};
            
            
        }
// 3. timeOfDay.h: 지난 실습에서 만든 클래스에 다음을 변경

// std::exit함수를 호출하는 부분을 예외클래스에 메시지를 넣어 던지게 변경


    public: 
        timeOfDay(int h=0, int m =0): hour{h}, minute{m} {
            testHour();
            testMinute();
        }

        virtual void input(std::istream& is = std::cin){
            std::cout << " enter hour(0-23): ";
            is >> hour;
            testHour();
            std::cout << "enter a minute(0-59): ";
            is >> minute;
            testMinute();
            
        }
        //std::istream -> std:;cin(standard input)
        //             ->  std::ifstream (+file)
        virtual void print(std::ostream& os = std::cout) const 
        {
            os << std::setw(2) << std::setfill('0') << hour << ':';
            os << std::setw(2) << std::setfill('0') << minute;

            // if (hour < 10) std::cout << "0";
            // std::cout << hour << ":";
            // if (minute < 10) std::cout << "0";
            // std::cout << minute;
        }
        void setHour(int h){
            hour = h;
            testHour();
        }

        
        void setMinute(int m){
            minute = m;
            testMinute();
        }

        
        virtual ~timeOfDay(){} 
        int getHour() const {
            return hour;
        }
        int getMinute() const {
            return minute;
        }

        timeOfDay& operator++()
        {
            ++minute;//0=59
            if (minute == 60) {minute =0; ++hour;}
            if (hour == 24) { hour =0; }
            return *this;
        }
        timeOfDay operator++(int)
        {
            timeOfDay temp{*this};//this 이용
            ++(*this);
            return temp;
        }
        timeOfDay& operator+=(int m)
        {
            minute += m;
            if (minute >= 60) {hour+= minute/60; minute %=60; }
            if (hour >= 24) { hour %= 24; }
            return *this;
        }

        friend std::istream& operator>>(std::istream& is, timeOfDay& t)
        {
            //std::cin(input()) --> is
            t.input(is);
            return is;
        }

        //std::ostream --> std::cout(standard output) , std::ofstream(+file)
        friend std::ostream& operator<<(std::ostream& os, const timeOfDay& t)
        {
            //std::cout(print()) --> os

            //if (t.hour < 10) os << "0"; os << t.hour << ":";
            //if (t.minute < 10) os << "0"; os << t.minute;

            // os.width(2);
            // os.fill('0');
            // os << t.hour << ":";
            // os << std::setw(2) << std::setfill('0') << t.minute;
            t.print(os);
            return os;
        }
        friend bool operator==(const timeOfDay& t1, const timeOfDay& t2)
        {
            return t1.hour == t2.hour && t1.minute == t2.minute;
        }
        friend timeOfDay operator+(const timeOfDay& t1, const timeOfDay& t2)
        {
            int minute1 {t1.minute + t1.hour*60 };
            int minute2 {t2.minute + t2.hour*60 };
            int totalMinute{minute1 + minute2};
            int newMinute{totalMinute%60};
            int newHour{totalMinute/60};
            if (newHour >= 24) newHour %= 24;

            return timeOfDay{newHour, newMinute};

        }

    };
}