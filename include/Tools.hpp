#pragma once

#include <memory>
#include <string>
#include <vector>

#include "AudioLibraryInfo.hpp"
#include "UI.hpp"

namespace AudioSync {

template<
    class Source
    , std::vector<std::unique_ptr<Source>> (getSources)()
    , AudioLibraryInfo (Source::* getInfo)() const
    , const std::string Source::* name
>
void baseSyncWith(AudioLibraryInfo& ourInfo) {
    using namespace std::string_literals;

    for (auto& source: getSources()) {
        const auto* const source_ptr = source.get();
        const auto sourceInfo = (source_ptr->*getInfo)();
        const auto difference = ourInfo.getDiffWith(sourceInfo);

        std::unique_ptr<UI_Base> ui = UI_Base::getUI();
        if (difference.empty()) {
            ui->informate(
                "No differences were found for the "s + source_ptr->*name + "\n"
            );
        }
        else {
            ui->informate(
                "Between"s + source_ptr->*name + " and local audio library were"
                + " found to be different\n"
            );
            
        }
    }
}

}

