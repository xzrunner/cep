#pragma once

#include <node0/NodeComp.h>

#include <string>

namespace archgraph { class EvalRule; class EvalContext; }

namespace easyarchgraph
{
class CompArchGraph : public n0::NodeComp
{
public:
    virtual const char* Type() const override { return TYPE_NAME; }
    virtual n0::CompID TypeID() const override {
        return n0::GetCompTypeID<CompArchGraph>();
    }
    virtual std::unique_ptr<n0::NodeComp> Clone(const n0::SceneNode& node) const override;

    void SetFilepath(const std::string& filepath) { m_filepath = filepath; }
    const std::string& GetFilepath() const { return m_filepath; }

    void  SetRule(const std::shared_ptr<archgraph::EvalRule>& rule,
        const std::shared_ptr<archgraph::EvalContext>& rule_ctx);
    auto& GetRule() const { return m_rule; }
    auto& GetRuleCtx() const { return m_rule_ctx; }

    static constexpr char* const TYPE_NAME = "comp_cga";

private:
    std::string m_filepath;

    std::shared_ptr<archgraph::EvalContext> m_rule_ctx = nullptr;
    std::shared_ptr<archgraph::EvalRule>    m_rule     = nullptr;

}; // CompArchGraph

}