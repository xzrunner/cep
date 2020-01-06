#include "cgaeasy/NSCompCGA.h"
#include "cgaeasy/CompCGA.h"

#include <boost/filesystem.hpp>

namespace cgae
{

size_t NSCompCGA::GetBinSize(const std::string& dir) const
{
	return 0;
}

void NSCompCGA::StoreToBin(const std::string& dir, bs::ExportStream& es) const
{
}

void NSCompCGA::LoadFromBin(const std::string& dir, bs::ImportStream& is)
{
}

void NSCompCGA::StoreToJson(const std::string& dir, rapidjson::Value& val, rapidjson::MemoryPoolAllocator<>& alloc) const
{
    val.SetObject();

    std::string relative = boost::filesystem::relative(m_filepath, dir).string();
    val.AddMember("filepath", rapidjson::Value(relative.c_str(), alloc), alloc);
}

void NSCompCGA::LoadFromJson(mm::LinearAllocator& alloc, const std::string& dir, const rapidjson::Value& val)
{
    auto relative = val["filepath"].GetString();
    m_filepath = boost::filesystem::absolute(relative, dir).string();
}

void NSCompCGA::StoreToMem(CompCGA& comp) const
{
    comp.SetFilepath(m_filepath);
}

void NSCompCGA::LoadFromMem(const CompCGA& comp)
{
    m_filepath = comp.GetFilepath();
}

}