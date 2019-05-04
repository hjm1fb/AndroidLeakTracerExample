#include <jni.h>
#include <string>
#include <MemoryTrace.hpp>
#include <fstream>
#include "Log.h"

extern "C" JNIEXPORT void JNICALL
Java_leaktracer_example_com_androidleaktracerexample_MainActivity_testMemoryLeak(
        JNIEnv *env,jobject instance) {

    leaktracer::MemoryTrace::GetInstance().startMonitoringAllThreads();
    short*	buffer	=	new	short[8];
    //    delete buffer;
    leaktracer::MemoryTrace::GetInstance().stopAllMonitoring();
    std::ofstream out;
    out.open("/sdcard/leaktracer.log", std::ios_base::out);
    if (out.is_open()) {
        leaktracer::MemoryTrace::GetInstance().writeLeaks(out);
    } else {
        LOGE("Failed to write to /sdcard/leaktracer.log");
    }

}
