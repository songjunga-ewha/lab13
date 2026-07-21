#include "preciseTime.h"
#include <memory>
#include <vector>

int main()
{

// -slicing problem

// preciseTime 객체를 원하는 값으로 초기화하여 선언한 후 print함수 호출

// timeOfDay 객체를 preciseTime 객체로 초기화하여 선언한 후 print함수 호출

// -slicing problem defeated (pointer)

// preciseTime 객체을 가리키는 포인터변수 선언한 후 print함수 호출

// timeOfDay를 가리키는 포인터변수를 선언, preciseTime 객체을 가리키는 포인터변수를 할당 후 print함수 호출

// -slicing problem defeated (dynamic)

// timeOfDay를 가리키는 포인터변수를 선언, preciseTime으로 동적할당, print함수 호출, 동적할당 해제

// -slicing problem defeated (smart pointer)

// 스마트포인터로도 테스트



// 5. main.cpp: 테스트파일

// -try구문안에 객체를 입력받고, 출력하는 테스트를 해보기 

// -catch구문에서는 예외클래스를 잡습니다. 

// cerr을 이용해 메시지를 콘솔창으로 출력합니다. 

    using namespace songjunga2549023;
    try {

        // std::cout << "slicing problem\n";
        // preciseTime p{3,3,3};
        // p.print();
        // timeOfDay t{p};
        // t.print(); std::cout << '\n';

        // std::cout << "slicing problem defeated(pointer)\n";
        // preciseTime* pp{&p}; 
        // pp->print();

        // timeOfDay* pt{pp};
        // pt->print();

        // std::cout << "slicing problem defeated(dynamic)\n";
        // timeOfDay* pd{ new preciseTime{5,5,5} }; 
        // pd->print();

        // std::cout << "slicing problem defeated (smart pointer)\n";
        // std::unique_ptr<timeOfDay> pu{ std::make_unique<preciseTime>(1, 30, 0) };
        // pu->print();

        // std::vector<timeOfDay> vv;
        // vv.push_back(t); vv[0].print(); std::cout << '\n';
        // vv.push_back(p); vv[1].print(); std::cout << '\n';

        // std::vector<timeOfDay*> vp;
        // vp.push_back(pt); vp[0]->print();
        // vp.push_back(pp); vp[1]->print();
        // vp.push_back(pd); vp[2]->print();
        // delete pd;


        // std::vector<std::unique_ptr<timeOfDay>> vu;
        // vu.push_back(std::move(pu)); vu[0] -> print();

        preciseTime time;
        std::cin >> time;
        std::cout <<time;
    }
    catch(timeException& e)
    {
        std::cerr << e.getMessage();

    }
    return 0;


}