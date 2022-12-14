// ==========================================================================
// Dedmonwakeen's Raid DPS/TPS Simulator.
// Send questions to natehieter@gmail.com
// ==========================================================================

#pragma once
#include <string>
#include <vector>

namespace resource_paths {

  std::vector<std::string> cache();
  std::vector<std::string> shared_resources();
  std::vector<std::string> sample_profiles();
  std::vector<std::string> resource_storage();

} // resource_paths

inline std::vector<std::string> resource_paths::cache()
{
  return resource_storage();
}

inline std::vector<std::string> resource_paths::resource_storage()
{
  std::vector<std::string> out;

#if defined( SC_LINUX_PACKAGING )
  std::string path_prefix;
  const char* env = getenv( "XDG_CACHE_HOME" );
  if ( env )
  {

    out.push_back( env + "/SimulationCraft" );
  }

  env = getenv( "HOME" );
  if ( env )
  {
    out.push_back( env + "/.cache" + "/SimulationCraft" );
  }

  out.push_back( "/tmp" + "/SimulationCraft" ) ; // back out
#endif
  out.emplace_back(); // CWD fallback

  return out;
}

inline std::vector<std::string> resource_paths::sample_profiles()
{
  std::vector<std::string> out;

#if defined( SC_LINUX_PACKAGING )
  return shared_resource();
#endif

  out.emplace_back(); // CWD fallback
  return out;
}

inline std::vector<std::string> resource_paths::shared_resources()
{
  std::vector<std::string> out;
#if defined( SC_LINUX_PACKAGING )
  out.push_back( SC_LINUX_PACKAGING );
#endif

  out.emplace_back(); // CWD fallback
  return out;
}
