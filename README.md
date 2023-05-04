# android-g711-codec
Android wrapper around [g711.c](http://www.speech.kth.se/cost250/refsys/v1.0/src/g711.c) written on C++ and Kotlin.

## Supported features:
1. Encoding PCM audio into G711A, G711U.
2. Decoding G711A or G711U audio into PCM.
3. Converting from G711A to G711U and vice versa.
4. Mono or stereo input audio.
5. Input in bytes or shorts.
6. Output in bytes or shorts.
7. Convert from bytes to shorts and vice versa.

## Supported ABIs:
armeabi-v7a, arm64-v8a, x86, x86_64

## How to use

#### Init encoder and decoder:
```kotlin
val codec = G711()                                    // getting Codec instance
```

#### Encoding:
```kotlin
val frame = ...                                       // get a chunk of audio from some source as an array of bytes or shorts
val encoded = codec.encodeA(frame)                    // encode the audio chunk into G711A (for G711U use encodeU(...) method) 
if (encoded != null) Log.d("G711", "encoded chunk size: ${encoded.size}")
```

#### Decoding:
```kotlin
val decoded = codec.decodeA(encoded)                  // decode a chunk of audio from G711A (for G711U use decodeU(...) method) into PCM
if (decoded != null) Log.d("G711", "decoded chunk size: ${decoded.size}")
```

## Project structure
#### Project consists of two modules:
- **app** - here you can find a sample app that demonsrates ecoding, decoding and converting procedures by capturing an audio from device's mic and play it from a loud speaker. I recommend to check this app using a headphones, otherwise there may be echo in a hight levels of volume.
- **pcmau** - here you can find a C++ class that interacts with [g711.c](http://www.speech.kth.se/cost250/refsys/v1.0/src/g711.c) and JNI wrapper for interacting with it from Java/Kotlin layer.

#### Compiled library:
- **pcmau.aar** - it's a compiled library of **pcmau** module that mentioned above, it placed in the root directory of the project, you can easily add it to your project using gradle dependencies. First you have to place **pcmau.aar** in the libs folder of your project and then add to your build.gradle the following:
````groovy
dependencies {
    api fileTree(dir: 'libs', include: '*.jar')       // this line is necessary in order to allow gradle to take pcmau.aar from "libs" dir
    api files('libs/pcmau.aar')                       // dependency for pcmau.aar library
    ...                                               // other dependencies
}
````
