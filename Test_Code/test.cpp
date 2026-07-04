#include"Open.h"
#include<iostream>

int main()
{
    OpenOffice my_open;
    my_open.Excel(L"E_first");
    std::cout<<"first"<<std::endl;
    my_open.PPT(L"P_first");
    std::cout<<"second"<<std::endl;
    my_open.Word(L"W_first");
    std::cout<<"third"<<std::endl;
    my_open.Outlook(L"O_first");
    std::cout<<"fourth"<<std::endl;
    my_open.Excel(L"E_second");
    std::cout<<"second"<<std::endl;
    my_open.Excel(L"E_third");
    std::cout<<"fourth"<<std::endl;
    my_open.Excel(L"E_third");
    std::cout<<"fifth"<<std::endl;

    return 0;
}