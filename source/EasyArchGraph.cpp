#include "easyarchgraph/EasyArchGraph.h"
#include "easyarchgraph/CompArchGraph.h"
#include "easyarchgraph/NSCompArchGraph.h"

#include <ns/CompIdxMgr.h>
#include <ns/RegistCallback.h>

namespace easyarchgraph
{

void EasyArchGraph::Init()
{
    ns::CompIdxMgr::Instance()->AddExtTypeToIdx(CompArchGraph::TYPE_NAME, ns::COMP_INVALID);
    ns::RegistCallback::AddUniqueCB<CompArchGraph, NSCompArchGraph>();
}

}