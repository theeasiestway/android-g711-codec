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
    std::vector<uint8_t> result;
    for (int i = 0; i < length; ++i) {
        result.push_back(linear2alaw(bytes[i]));
    }
    return result;
}

std::vector<short> G711::encodeA(short *shorts, int length) {
    std::vector<short> result;
    for (int i = 0; i < length; ++i) {
        result.push_back(SamplesConverter::convert(linear2alaw(shorts[i])));
    }
    return result;
}

std::vector<uint8_t> G711::encodeU(uint8_t *bytes, int length) {
    std::vector<uint8_t> result;
    for (int i = 0; i < length; ++i) {
        result.push_back(linear2ulaw(bytes[i]));
    }
    return result;
}

std::vector<short> G711::encodeU(short *shorts, int length) {
    std::vector<short> result;
    for (int i = 0; i < length; ++i) {
        result.push_back(SamplesConverter::convert(linear2ulaw(shorts[i])));
    }
    return result;
}

//
// Decoding
//

std::vector<uint8_t> G711::decodeA(uint8_t *bytes, int length) {
    std::vector<uint8_t> result;
    for (int i = 0; i < length; ++i) {
        result.push_back((uint8_t) alaw2linear(bytes[i]));
    }
    return result;
}

std::vector<short> G711::decodeA(short *shorts, int length) {
    std::vector<short> result;
    for (int i = 0; i < length; ++i) {
        std::vector<uint8_t> bytes = SamplesConverter::convert(shorts[i]);
        int bytesLength = bytes.size();
        for (int j = 0; j < bytesLength; ++j) {
            result.push_back((short) alaw2linear(bytes[j]));
        }
    }
    return result;
}

std::vector<uint8_t> G711::decodeU(uint8_t *bytes, int length) {
    std::vector<uint8_t> result;
    for (int i = 0; i < length; ++i) {
        result.push_back((uint8_t) ulaw2linear(bytes[i]));
    }
    return result;
}

std::vector<short> G711::decodeU(short *shorts, int length) {
    std::vector<short> result;
    for (int i = 0; i < length; ++i) {
        std::vector<uint8_t> bytes = SamplesConverter::convert(shorts[i]);
        int bytesLength = bytes.size();
        for (int j = 0; j < bytesLength; ++j) {
            result.push_back((short) ulaw2linear(bytes[j]));
        }
    }
    return result;
}

//
// Converting
//

std::vector<uint8_t> G711::convertAtoU(uint8_t *bytes, int length) {
    std::vector<uint8_t> result;
    for (int i = 0; i < length; ++i) {
        result.push_back((uint8_t) alaw2ulaw(bytes[i]));
    }
    return result;
}

std::vector<short> G711::convertAtoU(short *shorts, int length) {
    std::vector<short> result;
    for (int i = 0; i < length; ++i) {
        std::vector<uint8_t> bytes = SamplesConverter::convert(shorts[i]);
        int bytesLength = bytes.size();
        for (int j = 0; j < bytesLength; ++j) {
            result.push_back((short) alaw2ulaw(bytes[j]));
        }
    }
    return result;
}

std::vector<uint8_t> G711::convertUtoA(uint8_t *bytes, int length) {
    std::vector<uint8_t> result;
    for (int i = 0; i < length; ++i) {
        result.push_back((uint8_t) ulaw2alaw(bytes[i]));
    }
    return result;
}

std::vector<short> G711::convertUtoA(short *shorts, int length) {
    std::vector<short> result;
    for (int i = 0; i < length; ++i) {
        std::vector<uint8_t> bytes = SamplesConverter::convert(shorts[i]);
        int bytesLength = bytes.size();
        for (int j = 0; j < bytesLength; ++j) {
            result.push_back((short) ulaw2alaw(bytes[j]));
        }
    }
    return result;
}