#include "cep/CompCE.h"

namespace cep
{

std::unique_ptr<n0::NodeComp> CompCE::Clone(const n0::SceneNode& node) const
{
    auto comp = std::make_unique<CompCE>();
    comp->SetRule(m_rule, m_rule_ctx);
    return comp;
}

void CompCE::SetRule(const std::shared_ptr<ce::EvalRule>& rule,
                      const std::shared_ptr<ce::EvalContext>& rule_ctx)
{
    m_rule = rule;
    m_rule_ctx = rule_ctx;
}

}