#include <stdint.h>

struct PCMHeader{
    char   chunkID[4];       // "RIFF" for little-endian
    uint32_t chunkSize;      // Total file size - 8 bytes
    char   format[4];        // "WAVE"
    char   subChunk1ID[4];   // "fmt "
    uint32_t subChunk1Size;  // Size of the fmt sub-chunk (16 for PCM)
    uint16_t audioFormat;    // PCM = 1
    uint16_t numChannels;    // Number of channels (e.g., 1 for mono, 2 for stereo)
    uint32_t sampleRate;     // Sample rate (e.g., 44100)
    uint32_t byteRate;       // Sample rate * numChannels * bitsPerSample / 8
    uint16_t blockAlign;     // numChannels * bitsPerSample / 8
    uint16_t bitsPerSample;  // Bits per sample (e.g., 16)
    char   subChunk2ID[4];   // "data"
    uint32_t subChunk2Size;  // Size of the audio data (fileSize - 44 bytes)
};