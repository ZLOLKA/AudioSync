#include <vector>

#include "AudioLibraryInfo.hpp"
#include "BaseFunctions.hpp"

int main() {
    auto ourInfo = AudioSync::AudioLibraryInfo::getOurAudioLibraryInfo();
    AudioSync::syncWithStreamingServices(ourInfo);
    AudioSync::syncWithLocalDirectories(ourInfo);

	return 0;
}

