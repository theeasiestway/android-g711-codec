package com.theeasiestway.pcmau

import android.util.Log

class G711 {
    companion object {

        val TAG = "CodecOpus"

        init {
            try { System.loadLibrary("easypcmau") }
            catch (e: Exception) { Log.e(TAG, "Couldn't load pcmau library: $e") }
        }
    }

    //
    // Encoding
    //

    external fun encodeA(bytes: ByteArray): ByteArray
    external fun encodeA(shorts: ShortArray): ShortArray

    external fun encodeU(bytes: ByteArray): ByteArray
    external fun encodeU(shorts: ShortArray): ShortArray

    //
    // Decoding
    //

    external fun decodeA(bytes: ByteArray): ByteArray
    external fun decodeA(shorts: ShortArray): ShortArray

    external fun decodeU(bytes: ByteArray): ByteArray
    external fun decodeU(shorts: ShortArray): ShortArray

    //
    // Converting
    //

    external fun convertAtoU(bytes: ByteArray): ByteArray
    external fun convertAtoU(shorts: ShortArray): ShortArray

    external fun convertUtoA(bytes: ByteArray): ByteArray
    external fun convertUtoA(shorts: ShortArray): ShortArray

    external fun convert(bytes: ByteArray): ShortArray
    external fun convert(shorts: ShortArray): ByteArray
}