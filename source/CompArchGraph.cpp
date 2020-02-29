#include "easyarchgraph/CompArchGraph.h"

namespace easyarchgraph
{

std::unique_ptr<n0::NodeComp> CompArchGraph::Clone(const n0::SceneNode& node) const
{
    auto comp = std::make_unique<CompArchGraph>();
    comp->SetRule(m_rule, m_rule_ctx);
    return comp;
}

void CompArchGraph::SetRule(const std::shared_ptr<archgraph::EvalRule>& rule,
                      const std::shared_ptr<archgraph::EvalContext>& rule_ctx)
{
    m_rule = rule;
    m_rule_ctx = rule_ctx;
}

}