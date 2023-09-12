#include "AudioLibraryInfo.hpp"
#include "BaseFunctions.hpp"
#include "DebugTools/ASSERT.hpp"
#include "Settings.hpp"

#include <vector>

int main() ASSERT_AS_THROW_BEGIN {
  auto ourInfo = AudioSync::AudioLibraryInfo::getOurAudioLibraryInfo();
  AudioSync::syncWithStreamingServices(ourInfo);
  AudioSync::syncWithLocalDirectories(ourInfo);

  return 0;
}
ASSERT_AS_THROW_END
