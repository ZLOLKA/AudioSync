#include "AudioLibraryInfo.hpp"
#include "BaseFunctions.hpp"
#include "Settings.hpp"

#include <vector>

int main() {
  auto ourInfo = AudioSync::AudioLibraryInfo::getOurAudioLibraryInfo();
  AudioSync::syncWithStreamingServices(ourInfo);
  AudioSync::syncWithLocalDirectories(ourInfo);

  return 0;
}
