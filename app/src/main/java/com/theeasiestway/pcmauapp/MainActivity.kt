package com.theeasiestway.pcmauapp

import android.content.pm.PackageManager
import android.os.Build
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.CheckBox
import android.widget.RadioButton
import android.widget.Toast
import com.theeasiestway.opusapp.mic.ControllerAudio
import com.theeasiestway.pcmau.G711

class MainActivity : AppCompatActivity() {

    private val TAG = "OpusActivity"
    private val audioPermission = android.Manifest.permission.RECORD_AUDIO
    private val readPermission = android.Manifest.permission.READ_EXTERNAL_STORAGE
    private val writePermission = android.Manifest.permission.WRITE_EXTERNAL_STORAGE

    private enum class ProcessType { A, U, AtoU, UtoA }
    private lateinit var PROCESS_TYPE: ProcessType

    private val SAMPLE_RATE = 8000
    private val CHUNK_SIZE = 160
    private var CHANNELS = 1

    private val codec = G711()

    private lateinit var vPlay: Button
    private lateinit var vStop: Button
    private lateinit var vPcma: RadioButton
    private lateinit var vPcmu: RadioButton
    private lateinit var vPcmaToU: RadioButton
    private lateinit var vPcmuToA: RadioButton
    private lateinit var vMono: RadioButton
    private lateinit var vStereo: RadioButton
    private lateinit var vBytes: RadioButton
    private lateinit var vShorts: RadioButton
    private lateinit var vConvert: CheckBox

    private var runLoop = false
    private var needToConvert = false

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        vPlay = findViewById(R.id.vPlay)
        vStop = findViewById(R.id.vStop)

        vPcma = findViewById(R.id.vPcma)
        vPcmu = findViewById(R.id.vPcmu)

        vPcmaToU = findViewById(R.id.vPcmaToU)
        vPcmuToA = findViewById(R.id.vPcmuToA)

        vMono = findViewById(R.id.vMono)
        vStereo = findViewById(R.id.vStereo)

        vBytes = findViewById(R.id.vBytes)
        vShorts = findViewById(R.id.vShorts)

        vConvert = findViewById(R.id.vConvert)

        vPlay.setOnClickListener { requestPermissions() }
        vStop.setOnClickListener { stopRecording() }
    }

    private fun stopRecording() {
        vStop.visibility = View.GONE
        vPlay.visibility = View.VISIBLE
        stopLoop()
        ControllerAudio.stopRecord()
        ControllerAudio.stopTrack()
        vBytes.isEnabled = true
        vShorts.isEnabled = true
        vMono.isEnabled = true
        vStereo.isEnabled = true
    }

    private fun startLoop() {
        stopLoop()

        vBytes.isEnabled = false
        vShorts.isEnabled = false
        vMono.isEnabled = false
        vStereo.isEnabled = false

        CHANNELS = if (vMono.isChecked) 1 else 2
        PROCESS_TYPE = getProcessType()

        val handleShorts = vShorts.isChecked

        ControllerAudio.initRecorder(SAMPLE_RATE, CHUNK_SIZE, CHANNELS == 1)
        ControllerAudio.initTrack(SAMPLE_RATE, CHANNELS == 1)
        ControllerAudio.startRecord()
        runLoop = true
        Thread { while (runLoop) { if (handleShorts) handleShorts() else handleBytes() } }.start()
    }

    private fun getProcessType(): ProcessType {
        return ProcessType.U
    }

    private fun stopLoop() {
        runLoop = false
    }

    private fun handleShorts() {
        val frame = ControllerAudio.getFrameShort() ?: return
        val encoded = codec.encodeA(frame)
        Log.d(TAG, "encoded: ${frame.size} shorts of ${if (CHANNELS == 1) "MONO" else "STEREO"} audio into ${encoded.size} shorts")
        val decoded = codec.decodeA(encoded)
        Log.d(TAG, "decoded: ${decoded.size} shorts")

        if (needToConvert) {
            val converted = codec.convert(decoded)
            Log.d(TAG, "converted: ${decoded.size} shorts into ${converted.size} bytes")
            ControllerAudio.write(converted)
        } else ControllerAudio.write(decoded)
        Log.d(TAG, "===========================================")
    }

    private fun handleBytes() {
        val frame = ControllerAudio.getFrame() ?: return
        val encoded = codec.encodeA(frame)
        Log.d(TAG, "encoded: ${frame.size} bytes of ${if (CHANNELS == 1) "MONO" else "STEREO"} audio into ${encoded.size} bytes")
        val decoded = codec.decodeA(encoded)
        Log.d(TAG, "decoded: ${decoded.size} bytes")

        if (needToConvert) {
            val converted = codec.convert(decoded)
            Log.d(TAG, "converted: ${decoded.size} bytes into ${converted.size} shorts")
            ControllerAudio.write(converted)
        } else ControllerAudio.write(decoded)
        Log.d(TAG, "===========================================")
    }

    private fun requestPermissions() {
        if (Build.VERSION.SDK_INT <= Build.VERSION_CODES.M) startLoop()
        else if (checkSelfPermission(audioPermission) != PackageManager.PERMISSION_GRANTED ||
            checkSelfPermission(readPermission) != PackageManager.PERMISSION_GRANTED ||
            checkSelfPermission(writePermission) != PackageManager.PERMISSION_GRANTED) {
            requestPermissions(arrayOf(audioPermission, readPermission, writePermission), 123)
        } else startLoop()
    }

    override fun onRequestPermissionsResult(requestCode: Int, permissions: Array<out String>, grantResults: IntArray) {
        if (permissions[0] == audioPermission &&
            permissions[1] == readPermission &&
            permissions[3] == writePermission &&
            requestCode == 123) {
            if (grantResults[0] == PackageManager.PERMISSION_GRANTED &&
                grantResults[1] == PackageManager.PERMISSION_GRANTED &&
                grantResults[2] == PackageManager.PERMISSION_GRANTED) startLoop()
            else Toast.makeText(this, "App doesn't have enough permissions to continue", Toast.LENGTH_LONG).show()
        }
    }

    override fun onPause() {
        super.onPause()
        stopRecording()
    }
}
