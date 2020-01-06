#include "cgaeasy/CGAEasy.h"
#include "cgaeasy/CompCGA.h"
#include "cgaeasy/NSCompCGA.h"

#include <ns/CompIdxMgr.h>
#include <ns/RegistCallback.h>

namespace cgae
{

void CGAEasy::Init()
{
    ns::CompIdxMgr::Instance()->AddExtTypeToIdx(CompCGA::TYPE_NAME, ns::COMP_INVALID);
    ns::RegistCallback::AddUniqueCB<CompCGA, NSCompCGA>();
}

}