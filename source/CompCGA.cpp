#include "cgaeasy/CompCGA.h"

namespace cgae
{

std::unique_ptr<n0::NodeComp> CompCGA::Clone(const n0::SceneNode& node) const
{
    auto comp = std::make_unique<CompCGA>();
    comp->SetRule(m_rule);
    return comp;
}

void CompCGA::SetRule(const std::shared_ptr<cga::EvalRule>& rule)
{
    m_rule = rule;
}

}