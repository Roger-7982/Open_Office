#include "Word_Methods.h"

void Word_Methods::Word(const std::wstring& name)
{
    IUnknown* ptemplate=Opentemplate(L"Word.Application");
    Operation(name,ptemplate);
}