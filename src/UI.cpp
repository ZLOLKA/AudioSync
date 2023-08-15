#include "UI.hpp"

#include <algorithm>
#include <memory>

namespace AudioSync {

std::unique_ptr<UI_Base> UI_Base::getUI() NOEXCEPT_T {
  std::unique_ptr<UI_Base> ui;
  return std::move(ui);  // TODO: Incorrect return value
}

}  // namespace AudioSync
