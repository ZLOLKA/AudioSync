#include "Tools.hpp"

#include "Target.hpp"
#include "UI.hpp"

namespace AudioSync {

void baseSyncWith(
    AudioLibraryInfo& ourInfo,
    std::vector<std::unique_ptr<Target>> sources
) NOEXCEPT_T {
  using namespace std::string_literals;

  for (auto& source : sources) {
    const auto& sourceInfo = source->getInfo();
    const auto difference = ourInfo.getDiffWith(sourceInfo);

    std::unique_ptr<UI_Base> ui = UI_Base::getUI();
    if (difference.empty()) {
      ui->informate(
          "No differences were found for the "s + source->getName() + "\n"
      );
    } else {
      ui->informate(
          "Between"s + source->getName() + " and local audio "
          + "library were found to be different\n"
      );
    }
  }
}

}  // namespace AudioSync
