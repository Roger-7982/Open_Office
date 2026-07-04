#include"Open.h"
#include<iostream>
#include<unknwn.h>
static thread_local bool agreement=true;


OpenOffice::OpenOffice()
    {
        if (!agreement)
        {
            std::cout<<"OpenOffice can just use once!"<<std::endl;
            return;
        }
        HRESULT hr=CoInitializeEx(nullptr,COINIT_APARTMENTTHREADED);
        if(FAILED(hr))
        {
            std::cout<<"Error in CoInitialize()"<<std::endl;
            flag=false;
        }
        agreement=false;
    }

OpenOffice::~OpenOffice()
{
    if (flag==false)
        return;

    for (auto& [name,pUnk]:remember)
    {
        if (pUnk!=nullptr)
        {
            pUnk->Release();
        }
    }
    remember.clear();
    CoUninitialize();
}

IUnknown* OpenOffice::Opentemplate(LPCOLESTR value)const
    {
        if (flag==false)
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

void OpenOffice::Excel(const std::wstring& name)
    {
        IUnknown* ptemplate=Opentemplate(L"Excel.Application");
        Operation(name,ptemplate);
    }

void OpenOffice::Word(const std::wstring& name)
    {
        IUnknown* ptemplate=Opentemplate(L"Word.Application");
        Operation(name,ptemplate);
    }

void OpenOffice::PPT(const std::wstring& name)
    {
        IUnknown* ptemplate=Opentemplate(L"PowerPoint.Application");
        Operation(name,ptemplate);
    }

void OpenOffice::Outlook(const std::wstring& name)
{
    IUnknown* ptemplate=Opentemplate(L"Outlook.Application");
    Operation(name,ptemplate);
}

void OpenOffice::Operation(const std::wstring& name,IUnknown* ptemplate)
{
    auto res=remember.insert({name,ptemplate});
    if (res.second==false)
    {
        std::cout<<"error:Seem the name have lived,no make a new one!"<<std::endl;
        ptemplate->Release();//easy to forget release;
    }
}

IUnknown* OpenOffice::Find(const std::wstring& name)const
{
    auto res=remember.find(name);
    if (res==remember.end())
    {
        std::cout<<"error:No Find The Name!"<<std::endl;
        return nullptr;
    }
    return res->second;
}
