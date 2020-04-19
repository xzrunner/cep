#pragma once

#include <ns/NodeComponent.h>

namespace easyarchgraph
{

class CompArchGraph;

class NSCompArchGraph : public ns::NodeComponent
{
public:
    NSCompArchGraph() {}

    //
    // bin
    //
    virtual size_t GetBinSize(const std::string& dir) const override;
    virtual void   StoreToBin(const std::string& dir, bs::ExportStream& es) const override;
    virtual void   LoadFromBin(const ur2::Device& dev, const std::string& dir, bs::ImportStream& is) override;

    //
    // json
    //
    virtual void StoreToJson(const std::string& dir, rapidjson::Value& val, rapidjson::MemoryPoolAllocator<>& alloc) const override;
    virtual void LoadFromJson(const ur2::Device& dev, mm::LinearAllocator& alloc, const std::string& dir, const rapidjson::Value& val) override;

    //
    // memory
    //
    void StoreToMem(const ur2::Device& dev, CompArchGraph& comp) const;
    void LoadFromMem(const CompArchGraph& comp);

private:
    std::string m_filepath;

}; // NSCompArchGraph

}
