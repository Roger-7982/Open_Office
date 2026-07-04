#include"Methods.h"
#include<iostream>
Methods::~Methods()
{
    if (Office.GetFlag()==false)
        return;

    for (const auto &pair: remember)
    {
        IUnknown* pUnk=pair.second;
        if (pUnk!=nullptr)
        {
            pUnk->Release();
        }
    }
    remember.clear();
}

IUnknown* Methods::Opentemplate(LPCOLESTR value)const
{
    if (Office.GetFlag()==false)
    {
        std::cout<<"error:OpenOffice false!"<<std::endl;
        return nullptr;
    }
    IUnknown* ptemplate=nullptr;
    CLSID clsid;
    HRESULT hr=CLSIDFromProgID(value,&clsid);
    if (FAILED(hr))
    {
        std::cout<<"Error:no find office"<<std::endl;
        return nullptr;
    }
    hr=CoCreateInstance(clsid,nullptr,CLSCTX_LOCAL_SERVER,IID_IUnknown,reinterpret_cast<void **>(&ptemplate));
    if (FAILED(hr))
    {
        std::cout<<"Error in CoCreateInstance() office"<<std::endl;
        return nullptr;
    }
    return ptemplate;
}

void Methods::Operation(const std::wstring& name,IUnknown* ptemp)
{
    if (Office.GetFlag()==false)
    {
        std::cout<<"error:OpenOffice false!"<<std::endl;
        return;
    }
    if (ptemp!=nullptr)
    {
        IDispatch* ptemplate;
        ptemp->QueryInterface(IID_IDispatch,reinterpret_cast<void **>(&ptemplate));
        if (ptemplate!=nullptr)
        {
            auto res=remember.insert({name,ptemplate});
        }
        ptemp->Release();//if false,it will be 0,if success,it will be 1
    }
}

IUnknown* Methods::Find(const std::wstring& name)const
{
    auto res=remember.find(name);
    if (res==remember.end())
    {
        std::cout<<"error:No Find The Name!"<<std::endl;
        return nullptr;
    }
    return res->second;
}