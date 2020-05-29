//
// Created by Loboda Alexey on 29.05.2020.
//

#ifndef PCMAU_G711_H
#define PCMAU_G711_H

#include <vector>

class G711 {

public:

    //
    // Encoding
    //

    std::vector<uint8_t> encodeA(uint8_t *bytes, int length);
    std::vector<short> encodeA(short *shorts, int length);

    std::vector<uint8_t> encodeU(uint8_t *bytes, int length);
    std::vector<short> encodeU(short *shorts, int length);

    //
    // Decoding
    //

    std::vector<uint8_t> decodeA(uint8_t *bytes, int length);
    std::vector<short> decodeA(short *shorts, int length);

    std::vector<uint8_t> decodeU(uint8_t *bytes, int length);
    std::vector<short> decodeU(short *shorts, int length);

    //
    // Converting
    //

    std::vector<uint8_t> convertAtoU(uint8_t *bytes, int length);
    std::vector<short> convertAtoU(short *shorts, int length);

    std::vector<uint8_t> convertUtoA(uint8_t *bytes, int length);
    std::vector<short> convertUtoA(short *shorts, int length);
};

#endif //PCMAU_G711_H
