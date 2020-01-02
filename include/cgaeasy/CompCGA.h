#pragma once

#include <node0/NodeComp.h>

namespace cga { class EvalRule; }

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

    void  SetRule(const std::shared_ptr<cga::EvalRule>& rule);
    auto& GetRule() const { return m_rule; }

    static constexpr char* const TYPE_NAME = "comp_cga";

private:
    std::shared_ptr<cga::EvalRule> m_rule = nullptr;

}; // CompCGA

}