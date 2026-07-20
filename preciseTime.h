// 5. preciseTime.h: timeOfDay를 공개적으로 상속하는 preciseTime 클래스 정의
// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버 
// -int형 second
// -testSecond: second은 0~59가 아니면 프로그램 종료
// public 멤버함수
// -생성자: 모든 멤버변수 초기화, 기본값 설정, timeOfDay 생성자 호출, testSecond함수 호출
// -접근함수들: getSecond, setSecond
// -출력연산자<<: timeOfDay의 출력연산자를 이용, hour:minute:second형식으로 출력, 공백채움문자'0'설정과 출력폭 2자리설정
// -print(재정의)
 
#pragma once
#include "timeOfDay.h"

namespace songjunga2549023
{
    class preciseTime : public timeOfDay
    {
    private: 
        int second;
        void testSecond(){
            if ((second<0) || (second >59)){
                std::cout << "invalid second!\n";
                std::exit(1);
            }
        }
    public: 
        preciseTime(int h =0, int m=0, int s=0) :timeOfDay{h, m}, second{s} 
        {
            testSecond();
        }
        int getSecond() const {return second;}
        void setSecond(int s) { second = s;}
        friend std::ostream& operator<<(std::ostream& os, const preciseTime& p)
        {
            os << static_cast<const timeOfDay&>(p) << ":";
            os << std::setw(2) << std::setfill('0') << p.second;
            return os;
        }
        // 출력연산자<<: timeOfDay의 출력연산자를 이용, hour:minute:second형식으로 출력, 공백채움문자'0'설정과 출력폭 2자리설정
        //-print(재정의)       

        virtual void print(std::ostream& os = std::cout) const override //virtual dks Tjeh dlal rmeofh virtual DLA 
        {
            timeOfDay::print(os); //hour:minute
            os << ":";
            os << std::setw(2) << std::setfill('0') << second <<std::endl;

        }
        virtual ~preciseTime(){}


    
    };
}