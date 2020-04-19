#include "easyarchgraph/NSCompArchGraph.h"
#include "easyarchgraph/CompArchGraph.h"

#include <boost/filesystem.hpp>

namespace easyarchgraph
{

size_t NSCompArchGraph::GetBinSize(const std::string& dir) const
{
	return 0;
}

void NSCompArchGraph::StoreToBin(const std::string& dir, bs::ExportStream& es) const
{
}

void NSCompArchGraph::LoadFromBin(const ur2::Device& dev, const std::string& dir, bs::ImportStream& is)
{
}

void NSCompArchGraph::StoreToJson(const std::string& dir, rapidjson::Value& val, rapidjson::MemoryPoolAllocator<>& alloc) const
{
    val.SetObject();

    std::string relative = boost::filesystem::relative(m_filepath, dir).string();
    val.AddMember("filepath", rapidjson::Value(relative.c_str(), alloc), alloc);
}

void NSCompArchGraph::LoadFromJson(const ur2::Device& dev, mm::LinearAllocator& alloc, const std::string& dir, const rapidjson::Value& val)
{
    auto relative = val["filepath"].GetString();
    m_filepath = boost::filesystem::absolute(relative, dir).string();
}

void NSCompArchGraph::StoreToMem(const ur2::Device& dev, CompArchGraph& comp) const
{
    comp.SetFilepath(m_filepath);
}

void NSCompArchGraph::LoadFromMem(const CompArchGraph& comp)
{
    m_filepath = comp.GetFilepath();
}

}