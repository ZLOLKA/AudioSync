#include "StreamingAPI.hpp"

#include "Settings.hpp"
#include "UI.hpp"

#include <functional>
#include <map>

namespace AudioSync {

std::vector<std::unique_ptr<Target>> StreamingAPI::getStreamingServices(
) NOEXCEPT_T {
  const auto* settings = Settings::getSettings();
  std::vector<std::unique_ptr<Target>> res;
  for (const auto& nameStreamingService : settings->getStreamingServicesNames()) {
    auto streamingService = getStreamingServiceByName(nameStreamingService);
    if (streamingService) {
      res.push_back(std::move(streamingService));
    }
  }
  return res;
}

std::unique_ptr<StreamingAPI> StreamingAPI::getStreamingServiceByName(
    const std::string& name
) NOEXCEPT_T {
  using namespace std::string_literals;

  const auto ui = UI_Base::getUI();

  std::unique_ptr<StreamingAPI> res(nullptr);
  std::map<std::string, std::function<std::unique_ptr<StreamingAPI>()>> loadersByNames {
    // TODO: Create loaders in next format
    // { "YandexMusic", &YandexMusic::getTargetForYandexMusic }
  };
  const auto fullNameStr = "streaming service with name \""s + name + "\"";
  if (auto it = loadersByNames.find(name); it != loadersByNames.end()) {
    ui->informate("Loading information from "s + fullNameStr);
    res = ((*it).second)();
    ui->informate("Information from "s + fullNameStr + " loaded");
  } else {
    ui->warning("For "s + fullNameStr + " not exist loader");
  }
  return std::move(res);
}

}  // namespace AudioSync
