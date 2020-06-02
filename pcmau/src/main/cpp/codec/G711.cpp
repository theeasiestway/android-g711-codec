//
// Created by Loboda Alexey on 29.05.2020.
//

#include "G711.h"
#include "../utils/SamplesConverter.h"
extern "C" {
#include "core.h"
};

//
// Encoding
//

std::vector<uint8_t> G711::encodeA(uint8_t *bytes, int length) {
    std::vector<short> rawShorts = SamplesConverter::convert(&bytes, length);
    std::vector<short> encodedShorts = encodeA(rawShorts.data(), rawShorts.size());
    short *data = encodedShorts.data();
    return SamplesConverter::convert(&data, encodedShorts.size());
}

std::vector<short> G711::encodeA(short *shorts, int length) {
    std::vector<short> result;
    for (int i = 0; i < length; ++i) {
        result.push_back(linear2alaw(shorts[i]));
    }
    return result;
}

std::vector<uint8_t> G711::encodeU(uint8_t *bytes, int length) {
    std::vector<short> rawShorts = SamplesConverter::convert(&bytes, length);
    std::vector<short> encodedShorts = encodeU(rawShorts.data(), rawShorts.size());
    short *data = encodedShorts.data();
    return SamplesConverter::convert(&data, encodedShorts.size());
}

std::vector<short> G711::encodeU(short *shorts, int length) {
    std::vector<short> result;
    for (int i = 0; i < length; ++i) {
        result.push_back(linear2ulaw(shorts[i]));
    }
    return result;
}

//
// Decoding
//

std::vector<uint8_t> G711::decodeA(uint8_t *bytes, int length) {
    std::vector<short> rawShorts = SamplesConverter::convert(&bytes, length);
    std::vector<short> decodedShorts = decodeA(rawShorts.data(), rawShorts.size());
    short *data = decodedShorts.data();
    return SamplesConverter::convert(&data, decodedShorts.size());
}

std::vector<short> G711::decodeA(short *shorts, int length) {
    std::vector<short> result;
    for (int i = 0; i < length; ++i) {
        result.push_back((short) alaw2linear((uint8_t) shorts[i]));
    }
    return result;
}

std::vector<uint8_t> G711::decodeU(uint8_t *bytes, int length) {
    std::vector<short> rawShorts = SamplesConverter::convert(&bytes, length);
    std::vector<short> decodedShorts = decodeU(rawShorts.data(), rawShorts.size());
    short *data = decodedShorts.data();
    return SamplesConverter::convert(&data, decodedShorts.size());
}

std::vector<short> G711::decodeU(short *shorts, int length) {
    std::vector<short> result;
    for (int i = 0; i < length; ++i) {
        result.push_back((short) ulaw2linear((uint8_t) shorts[i]));
    }
    return result;
}

//
// Converting
//

std::vector<uint8_t> G711::convertAtoU(uint8_t *bytes, int length) {
    std::vector<short> rawShorts = SamplesConverter::convert(&bytes, length);
    std::vector<short> convertedShorts = convertAtoU(rawShorts.data(), rawShorts.size());
    short *data = convertedShorts.data();
    return SamplesConverter::convert(&data, convertedShorts.size());
}

std::vector<short> G711::convertAtoU(short *shorts, int length) {
    std::vector<short> result;
    for (int i = 0; i < length; ++i) {
        result.push_back((short) alaw2ulaw((uint8_t) shorts[i]));
    }
    return result;
}

std::vector<uint8_t> G711::convertUtoA(uint8_t *bytes, int length) {
    std::vector<short> rawShorts = SamplesConverter::convert(&bytes, length);
    std::vector<short> convertedShorts = convertUtoA(rawShorts.data(), rawShorts.size());
    short *data = convertedShorts.data();
    return SamplesConverter::convert(&data, convertedShorts.size());
}

std::vector<short> G711::convertUtoA(short *shorts, int length) {
    std::vector<short> result;
    for (int i = 0; i < length; ++i) {
        result.push_back((short) ulaw2alaw((uint8_t) shorts[i]));
    }
    return result;
}