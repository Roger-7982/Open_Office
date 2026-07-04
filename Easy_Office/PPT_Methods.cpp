#include "PPT_Methods.h"

void PPT_Methods::PPT(const std::wstring& name)
{
    IUnknown* ptemplate=Opentemplate(L"PowerPoint.Application");
    Operation(name,ptemplate);
}