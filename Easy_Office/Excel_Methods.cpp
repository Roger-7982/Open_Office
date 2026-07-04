#include"Excel_Methods.h"

void Excel_Methods::Excel(const std::wstring& name)
{
    IUnknown* ptemplate=Opentemplate(L"Excel.Application");
    Operation(name,ptemplate);
}

