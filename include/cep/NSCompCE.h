#pragma once

#include <ns/NodeComponent.h>

namespace cep
{

class CompCE;

class NSCompCE : public ns::NodeComponent
{
public:
    NSCompCE() {}

    //
    // bin
    //
    virtual size_t GetBinSize(const std::string& dir) const override;
    virtual void   StoreToBin(const std::string& dir, bs::ExportStream& es) const override;
    virtual void   LoadFromBin(const std::string& dir, bs::ImportStream& is) override;

    //
    // json
    //
    virtual void StoreToJson(const std::string& dir, rapidjson::Value& val, rapidjson::MemoryPoolAllocator<>& alloc) const override;
    virtual void LoadFromJson(mm::LinearAllocator& alloc, const std::string& dir, const rapidjson::Value& val) override;

    //
    // memory
    //
    void StoreToMem(CompCE& comp) const;
    void LoadFromMem(const CompCE& comp);

private:
    std::string m_filepath;

}; // NSCompCE

}
