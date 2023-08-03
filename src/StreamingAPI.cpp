#include "StreamingAPI.hpp"

#include "Settings.hpp"
#include "UI.hpp"

#include <functional>
#include <map>

namespace AudioSync {

std::vector<std::unique_ptr<Target>> StreamingAPI::getStreamingServices() {
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
) {
  std::unique_ptr<StreamingAPI> res(nullptr);
  std::map<std::string, std::function<std::unique_ptr<StreamingAPI>()>> loadersByNames {
    // TODO: Create loaders in next format
    // { "YandexMusic", &YandexMusic::getTargetForYandexMusic }
  };
  if (auto it = loadersByNames.find(name); it != loadersByNames.end()) {
    res = ((*it).second)();
  } else {
    using namespace std::string_literals;

    const auto ui = UI_Base::getUI();
    ui->informate(
        "For streaming service with name \""s + name + "\" not exist loader"
    );
  }
  return std::move(res);
}

}  // namespace AudioSync
