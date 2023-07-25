#pragma once

#include "AudioLibraryInfo.hpp"
#include "UI.hpp"

#include <memory>
#include <string>
#include <vector>

namespace AudioSync {

template<
    class Source,
    std::vector<std::unique_ptr<Source>>(getSources)(),
    const AudioLibraryInfo& (Source::*getInfo)() const,
    std::string (Source::*getName)() const>
void baseSyncWith(AudioLibraryInfo& ourInfo) {
  using namespace std::string_literals;

  for (auto& source : getSources()) {
    const auto* const source_ptr = source.get();
    const auto& sourceInfo = (source_ptr->*getInfo)();
    const auto difference = ourInfo.getDiffWith(sourceInfo);

    std::unique_ptr<UI_Base> ui = UI_Base::getUI();
    if (difference.empty()) {
      ui->informate(
          "No differences were found for the "s + (source_ptr->*getName)() + "\n"
      );
    } else {
      ui->informate(
          "Between"s + (source_ptr->*getName)() + " and local audio "
          + "library were found to be different\n"
      );
    }
  }
}

}  // namespace AudioSync
