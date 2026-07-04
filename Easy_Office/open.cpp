#include"Open.h"
#include<iostream>
#include<unknwn.h>

thread_local OpenOffice Office;

OpenOffice::OpenOffice()
    {
        if (GetAgreement())
        {
            HRESULT hr=CoInitializeEx(nullptr,COINIT_APARTMENTTHREADED);
            if(FAILED(hr))
            {
                std::cout<<"Error in CoInitialize()"<<std::endl;
                flag=false;
            }
            ChangeAgreement(false);
        }
    }

OpenOffice::~OpenOffice()
{
    if (flag&&!GetAgreement())
    CoUninitialize();
}

bool OpenOffice::GetFlag()const
{
    return flag;
}

bool OpenOffice::GetAgreement()const
{
    return agreement;
}

void OpenOffice::ChangeAgreement(bool temp)
{
    agreement=temp;
}



