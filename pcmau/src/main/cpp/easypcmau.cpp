#include <jni.h>
#include <string>
#include "codec/G711.h"
#include "utils/SamplesConverter.h"

//
// Created by Loboda Alexey on 29.05.2020.
//

G711 codec;

//
// Encoding
//

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_theeasiestway_pcmau_G711_encodeA___3B(JNIEnv *env, jobject thiz, jbyteArray bytes) {
    int length = env->GetArrayLength(bytes);
    jbyte *nativeBytes = env->GetByteArrayElements(bytes, 0);
    std::vector<uint8_t> encodedData = codec.encodeA((uint8_t*) nativeBytes, length);

    int encodedSize = encodedData.size();
    if (encodedSize <= 0) return nullptr;

    jbyteArray result = env->NewByteArray(encodedSize);
    env->SetByteArrayRegion(result, 0, encodedSize, (jbyte *) encodedData.data());
    env->ReleaseByteArrayElements(bytes, nativeBytes, 0);

    return result;
}

extern "C"
JNIEXPORT jshortArray JNICALL
Java_com_theeasiestway_pcmau_G711_encodeA___3S(JNIEnv *env, jobject thiz, jshortArray shorts) {
    int length = env->GetArrayLength(shorts);
    jshort *nativeShorts = env->GetShortArrayElements(shorts, 0);
    std::vector<short> encodedData = codec.encodeA(nativeShorts, length);

    int encodedSize = encodedData.size();
    if (encodedSize <= 0) return nullptr;

    jshortArray result = env->NewShortArray(encodedSize);
    env->SetShortArrayRegion(result, 0, encodedSize, encodedData.data());
    env->ReleaseShortArrayElements(shorts, nativeShorts, 0);

    return result;
}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_theeasiestway_pcmau_G711_encodeU___3B(JNIEnv *env, jobject thiz, jbyteArray bytes) {
    int length = env->GetArrayLength(bytes);
    jbyte *nativeBytes = env->GetByteArrayElements(bytes, 0);
    std::vector<uint8_t> encodedData = codec.encodeU((uint8_t*) nativeBytes, length);

    int encodedSize = encodedData.size();
    if (encodedSize <= 0) return nullptr;

    jbyteArray result = env->NewByteArray(encodedSize);
    env->SetByteArrayRegion(result, 0, encodedSize, (jbyte *) encodedData.data());
    env->ReleaseByteArrayElements(bytes, nativeBytes, 0);

    return result;
}

extern "C"
JNIEXPORT jshortArray JNICALL
Java_com_theeasiestway_pcmau_G711_encodeU___3S(JNIEnv *env, jobject thiz, jshortArray shorts) {
    int length = env->GetArrayLength(shorts);
    jshort *nativeShorts = env->GetShortArrayElements(shorts, 0);
    std::vector<short> encodedData = codec.encodeU(nativeShorts, length);

    int encodedSize = encodedData.size();
    if (encodedSize <= 0) return nullptr;

    jshortArray result = env->NewShortArray(encodedSize);
    env->SetShortArrayRegion(result, 0, encodedSize, encodedData.data());
    env->ReleaseShortArrayElements(shorts, nativeShorts, 0);

    return result;
}

//
// Decoding
//

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_theeasiestway_pcmau_G711_decodeA___3B(JNIEnv *env, jobject thiz, jbyteArray bytes) {
    int length = env->GetArrayLength(bytes);
    jbyte *nativeBytes = env->GetByteArrayElements(bytes, 0);
    std::vector<uint8_t> encodedData = codec.decodeA((uint8_t*) nativeBytes, length);

    int encodedSize = encodedData.size();
    if (encodedSize <= 0) return nullptr;

    jbyteArray result = env->NewByteArray(encodedSize);
    env->SetByteArrayRegion(result, 0, encodedSize, (jbyte *) encodedData.data());
    env->ReleaseByteArrayElements(bytes, nativeBytes, 0);

    return result;
}

extern "C"
JNIEXPORT jshortArray JNICALL
Java_com_theeasiestway_pcmau_G711_decodeA___3S(JNIEnv *env, jobject thiz, jshortArray shorts) {
    int length = env->GetArrayLength(shorts);
    jshort *nativeShorts = env->GetShortArrayElements(shorts, 0);
    std::vector<short> encodedData = codec.decodeA(nativeShorts, length);

    int encodedSize = encodedData.size();
    if (encodedSize <= 0) return nullptr;

    jshortArray result = env->NewShortArray(encodedSize);
    env->SetShortArrayRegion(result, 0, encodedSize, encodedData.data());
    env->ReleaseShortArrayElements(shorts, nativeShorts, 0);

    return result;
}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_theeasiestway_pcmau_G711_decodeU___3B(JNIEnv *env, jobject thiz, jbyteArray bytes) {
    int length = env->GetArrayLength(bytes);
    jbyte *nativeBytes = env->GetByteArrayElements(bytes, 0);
    std::vector<uint8_t> encodedData = codec.decodeU((uint8_t*) nativeBytes, length);

    int encodedSize = encodedData.size();
    if (encodedSize <= 0) return nullptr;

    jbyteArray result = env->NewByteArray(encodedSize);
    env->SetByteArrayRegion(result, 0, encodedSize, (jbyte *) encodedData.data());
    env->ReleaseByteArrayElements(bytes, nativeBytes, 0);

    return result;
}

extern "C"
JNIEXPORT jshortArray JNICALL
Java_com_theeasiestway_pcmau_G711_decodeU___3S(JNIEnv *env, jobject thiz, jshortArray shorts) {
    int length = env->GetArrayLength(shorts);
    jshort *nativeShorts = env->GetShortArrayElements(shorts, 0);
    std::vector<short> encodedData = codec.decodeU(nativeShorts, length);

    int encodedSize = encodedData.size();
    if (encodedSize <= 0) return nullptr;

    jshortArray result = env->NewShortArray(encodedSize);
    env->SetShortArrayRegion(result, 0, encodedSize, encodedData.data());
    env->ReleaseShortArrayElements(shorts, nativeShorts, 0);

    return result;
}

//
// Converting
//

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_theeasiestway_pcmau_G711_convertAtoU___3B(JNIEnv *env, jobject thiz, jbyteArray bytes) {
    int length = env->GetArrayLength(bytes);
    jbyte *nativeBytes = env->GetByteArrayElements(bytes, 0);
    std::vector<uint8_t> encodedData = codec.convertAtoU((uint8_t*) nativeBytes, length);

    int encodedSize = encodedData.size();
    if (encodedSize <= 0) return nullptr;

    jbyteArray result = env->NewByteArray(encodedSize);
    env->SetByteArrayRegion(result, 0, encodedSize, (jbyte *) encodedData.data());
    env->ReleaseByteArrayElements(bytes, nativeBytes, 0);

    return result;
}

extern "C"
JNIEXPORT jshortArray JNICALL
Java_com_theeasiestway_pcmau_G711_convertAtoU___3S(JNIEnv *env, jobject thiz, jshortArray shorts) {
    int length = env->GetArrayLength(shorts);
    jshort *nativeShorts = env->GetShortArrayElements(shorts, 0);
    std::vector<short> encodedData = codec.convertAtoU(nativeShorts, length);

    int encodedSize = encodedData.size();
    if (encodedSize <= 0) return nullptr;

    jshortArray result = env->NewShortArray(encodedSize);
    env->SetShortArrayRegion(result, 0, encodedSize, encodedData.data());
    env->ReleaseShortArrayElements(shorts, nativeShorts, 0);

    return result;
}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_theeasiestway_pcmau_G711_convertUtoA___3B(JNIEnv *env, jobject thiz, jbyteArray bytes) {
    int length = env->GetArrayLength(bytes);
    jbyte *nativeBytes = env->GetByteArrayElements(bytes, 0);
    std::vector<uint8_t> encodedData = codec.convertUtoA((uint8_t*) nativeBytes, length);

    int encodedSize = encodedData.size();
    if (encodedSize <= 0) return nullptr;

    jbyteArray result = env->NewByteArray(encodedSize);
    env->SetByteArrayRegion(result, 0, encodedSize, (jbyte *) encodedData.data());
    env->ReleaseByteArrayElements(bytes, nativeBytes, 0);

    return result;
}

extern "C"
JNIEXPORT jshortArray JNICALL
Java_com_theeasiestway_pcmau_G711_convertUtoA___3S(JNIEnv *env, jobject thiz, jshortArray shorts) {
    int length = env->GetArrayLength(shorts);
    jshort *nativeShorts = env->GetShortArrayElements(shorts, 0);
    std::vector<short> encodedData = codec.convertUtoA(nativeShorts, length);

    int encodedSize = encodedData.size();
    if (encodedSize <= 0) return nullptr;

    jshortArray result = env->NewShortArray(encodedSize);
    env->SetShortArrayRegion(result, 0, encodedSize, encodedData.data());
    env->ReleaseShortArrayElements(shorts, nativeShorts, 0);

    return result;
}

extern "C"
JNIEXPORT jshortArray JNICALL
Java_com_theeasiestway_pcmau_G711_convert___3B(JNIEnv *env, jobject thiz, jbyteArray bytes) {
    uint8_t *nativeBytes = (uint8_t *) env->GetByteArrayElements(bytes, 0);
    jint length = env->GetArrayLength(bytes);

    std::vector<short> shorts = SamplesConverter::convert(&nativeBytes, length);
    int size = shorts.size();
    if (!size) return nullptr;

    jshortArray result = env->NewShortArray(size);
    env->SetShortArrayRegion(result, 0, size, shorts.data());
    env->ReleaseByteArrayElements(bytes, (jbyte *) nativeBytes, 0);

    return result;
}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_theeasiestway_pcmau_G711_convert___3S(JNIEnv *env, jobject thiz, jshortArray shorts) {
    short *nativeShorts = env->GetShortArrayElements(shorts, 0);
    jint length = env->GetArrayLength(shorts);

    std::vector<uint8_t> bytes = SamplesConverter::convert(&nativeShorts, length);
    int size = bytes.size();
    if (!size) return nullptr;

    jbyteArray result = env->NewByteArray(size);
    env->SetByteArrayRegion(result, 0, size, (jbyte *) bytes.data());
    env->ReleaseShortArrayElements(shorts, nativeShorts, 0);

    return result;
}