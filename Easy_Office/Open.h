#pragma once

class OpenOffice;
extern thread_local OpenOffice Office;

class OpenOffice //it can just use once
{
public:
    OpenOffice();

    ~OpenOffice();
    [[nodiscard]] bool GetFlag()const;

    [[nodiscard]] bool GetAgreement()const;

    void ChangeAgreement(bool temp);

    //first know cpp can delete the operation
    OpenOffice(const OpenOffice&)=delete;
    OpenOffice& operator=(const OpenOffice&)=delete;

private:
    bool flag=true;
    bool agreement=true;
};