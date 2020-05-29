//
// Created by User on 29.05.2020.
//

#ifndef PCMAU_CORE_H
#define PCMAU_CORE_H

unsigned char linear2alaw(int pcm_val);

int alaw2linear(unsigned char a_val);

unsigned char linear2ulaw(int pcm_val);

int ulaw2linear(unsigned char u_val);

unsigned char alaw2ulaw(unsigned char aval);

unsigned char ulaw2alaw(unsigned char uval);

#endif //PCMAU_CORE_H
