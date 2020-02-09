#include "cep/CEP.h"
#include "cep/CompCE.h"
#include "cep/NSCompCE.h"

#include <ns/CompIdxMgr.h>
#include <ns/RegistCallback.h>

namespace cep
{

void CEP::Init()
{
    ns::CompIdxMgr::Instance()->AddExtTypeToIdx(CompCE::TYPE_NAME, ns::COMP_INVALID);
    ns::RegistCallback::AddUniqueCB<CompCE, NSCompCE>();
}

}