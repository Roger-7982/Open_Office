#pragma once
#include<windows.h>
#include<string>
#include<map>

//1.first ,you need to OpenOffice a class;
//2.then ,you can use Excel(),PPT(),NX(),Word() directly;

class OpenOffice //it can just use once
{
public:
    OpenOffice();

    ~OpenOffice();

    IUnknown* Opentemplate(LPCOLESTR value)const;

    void Excel(const std::wstring& name);

    void Word(const std::wstring& name);

    void PPT(const std::wstring& name);

    void Outlook(const std::wstring& name);

    void Operation(const std::wstring& name,IUnknown* ptemplate);

    [[nodiscard]] IUnknown* Find(const std::wstring& name) const;

private:
    std::map<std::wstring,IUnknown*> remember;
    bool flag=true;
};