#include "cgaeasy/CompCGA.h"

namespace cgae
{

std::unique_ptr<n0::NodeComp> CompCGA::Clone(const n0::SceneNode& node) const
{
    auto comp = std::make_unique<CompCGA>();
    comp->SetRule(m_rule, m_rule_ctx);
    return comp;
}

void CompCGA::SetRule(const std::shared_ptr<cga::EvalRule>& rule,
                      const std::shared_ptr<cga::EvalContext>& rule_ctx)
{
    m_rule = rule;
    m_rule_ctx = rule_ctx;
}

}