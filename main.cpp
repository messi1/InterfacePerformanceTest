#include <chrono>
#include <iostream>
#include <string>

#include "InterfaceVersion1.h"
#include "InterfaceVersion2.h"
#include "InterfaceVersion3.h"
#include "InterfaceVersion3b.h"
#include "InterfaceVersion3c.h"
#include "InterfaceVersion4.h"
#include "InterfaceVersion4b.h"



template<typename T>
void Test(const std::string& title, T&& testObject)
{
    const std::clock_t startTime = std::clock();

    for(unsigned long i = 0; i < 100'000'000; ++i) {
        testObject->read();
    }

    const std::clock_t endTime = std::clock();

    std::cout << "Execution time of " << title << " : "
              << 1000*(endTime-startTime) / CLOCKS_PER_SEC << " ms" << std::endl;
}

int main()
{
    std::shared_ptr<BasePublicVirtual>  basePublicVirtual  = std::make_shared<ChildPublicVirtual>();
    std::shared_ptr<BasePrivateVirtual> basePrivateVirtual = std::make_shared<ChildPrivateVirtual>();
    std::shared_ptr<BaseChildCrtp>      baseCrtp           = std::make_shared<BaseChildCrtp>();
    std::shared_ptr<BaseTemplateT>      baseTemplate       = std::make_shared<BaseTemplateT>();
    std::shared_ptr<BaseTemplate2T>     baseTemplate2      = std::make_shared<BaseTemplate2T>();
    std::shared_ptr<BaseLambda>         baseLambda         = std::make_shared<ChildLambda>();
    std::shared_ptr<BaseLambdaT>        baseLambdaTemplate = std::make_shared<BaseLambdaT>();

    Test("C++ Interface with virtual public method",  basePublicVirtual);
    Test("C++ Interface with virtual private method", basePrivateVirtual);
    Test("C++ Interface with CRTP",                   baseCrtp);
    Test("C++ Interface with Template",               baseTemplate);
    Test("C++ Interface with Template 2",             baseTemplate2);
    Test("C++ Interface with Lambda",                 baseLambda);
    Test("C++ Interface with Lambda and Template",    baseLambdaTemplate);

    return 0;
}

#if IVariant == 4
#include "InterfaceVersion3b.h"
#elif IVariant == 5
#include "InterfaceVersion3c.h"
#elif IVariant == 6
#include "InterfaceVersion4.h"
#elif IVariant == 7
#include "InterfaceVersion4b.h"
#endif

