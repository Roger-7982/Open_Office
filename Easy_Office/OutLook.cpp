#include "OutLook.h"

void OutLook_Methods::Outlook(const std::wstring& name)
{
    IUnknown* ptemplate=Opentemplate(L"Outlook.Application");
    Operation(name,ptemplate);
}