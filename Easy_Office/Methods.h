#pragma once
#include "Open.h"
#include<map>
#include<windows.h>
#include<string>

class Methods
{
public:
    virtual ~Methods();

    IUnknown* Opentemplate(LPCOLESTR value)const;

    void Operation(const std::wstring& name,IUnknown* ptemplate);

    [[nodiscard]] IUnknown* Find(const std::wstring& name) const;

protected:
    std::map<std::wstring,IUnknown*> remember;
};

