#pragma once

#include <node0/NodeComp.h>

#include <string>

namespace cga { class EvalRule; class EvalContext; }

namespace cgae
{
class CompCGA : public n0::NodeComp
{
public:
    virtual const char* Type() const override { return TYPE_NAME; }
    virtual n0::CompID TypeID() const override {
        return n0::GetCompTypeID<CompCGA>();
    }
    virtual std::unique_ptr<n0::NodeComp> Clone(const n0::SceneNode& node) const override;

    void SetFilepath(const std::string& filepath) { m_filepath = filepath; }
    const std::string& GetFilepath() const { return m_filepath; }

    void  SetRule(const std::shared_ptr<cga::EvalRule>& rule,
        const std::shared_ptr<cga::EvalContext>& rule_ctx);
    auto& GetRule() const { return m_rule; }
    auto& GetRuleCtx() const { return m_rule_ctx; }

    static constexpr char* const TYPE_NAME = "comp_cga";

private:
    std::string m_filepath;

    std::shared_ptr<cga::EvalContext> m_rule_ctx = nullptr;
    std::shared_ptr<cga::EvalRule>    m_rule     = nullptr;

}; // CompCGA

}