#include "cep/NSCompCE.h"
#include "cep/CompCE.h"

#include <boost/filesystem.hpp>

namespace cep
{

size_t NSCompCE::GetBinSize(const std::string& dir) const
{
	return 0;
}

void NSCompCE::StoreToBin(const std::string& dir, bs::ExportStream& es) const
{
}

void NSCompCE::LoadFromBin(const std::string& dir, bs::ImportStream& is)
{
}

void NSCompCE::StoreToJson(const std::string& dir, rapidjson::Value& val, rapidjson::MemoryPoolAllocator<>& alloc) const
{
    val.SetObject();

    std::string relative = boost::filesystem::relative(m_filepath, dir).string();
    val.AddMember("filepath", rapidjson::Value(relative.c_str(), alloc), alloc);
}

void NSCompCE::LoadFromJson(mm::LinearAllocator& alloc, const std::string& dir, const rapidjson::Value& val)
{
    auto relative = val["filepath"].GetString();
    m_filepath = boost::filesystem::absolute(relative, dir).string();
}

void NSCompCE::StoreToMem(CompCE& comp) const
{
    comp.SetFilepath(m_filepath);
}

void NSCompCE::LoadFromMem(const CompCE& comp)
{
    m_filepath = comp.GetFilepath();
}

}