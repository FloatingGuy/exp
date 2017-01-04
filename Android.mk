LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	exp.c \


LOCAL_SHARED_LIBRARIES := \
	liblog \

##root...
LOCAL_STATIC_LIBRARIES := 

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/ \
	bionic \
	
	 # $(LOCAL_PATH)/../root_utils \

ifeq ($(shell expr $(PLATFORM_SDK_VERSION) "<" 23), 1)
	LOCAL_SHARED_LIBRARIES += libstlport
	LOCAL_C_INCLUDES += \
		bionic/libstdc++/include \
		external/stlport/stlport
endif

LOCAL_C_INCLUDES += \

LOCAL_MODULE:= exp

include $(BUILD_EXECUTABLE)