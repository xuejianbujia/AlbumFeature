/* DO NOT EDIT THIS FILE - it is machine generated */


//#define PRINT_LOG



#ifdef PRINT_LOG

#ifndef LINUX
#include<process.h>
#include<windows.h>
#else
#include <sys/syscall.h>
 #include <sys/types.h>
 #include <linux/unistd.h>
 #include <errno.h>

#endif
#endif

#ifndef _WIN32

#include <jni.h>
#include "FaceAlbum.h"
#include "FaceTaggingCommonDef.h"

/* Header for class FaceTaggingInterface */


#ifndef _Included_FaceTaggingInterface
#define _Included_FaceTaggingInterface
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeGetVersion
    (JNIEnv *, jclass,long thiz);
    /*
 * Class:     FaceTaggingInterface
 * Method:    native_init_detect
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jlong JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeCreateObject
  (JNIEnv *, jclass);
    /*e
 * Class:     FaceTaggingInterface
 * Method:    nativeReleaseObject
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT void JNICALL  Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeReleaseObject
  (JNIEnv *, jclass,long);
/*
 * Class:     FaceTaggingInterface
 * Method:    native_init_detect
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL  Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeInitFaceDetect
  (JNIEnv *, jclass, long,jstring);

/*
 * Class:     FaceTaggingInterface
 * Method:    native_init_EyeLocation
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeInitEyeLocation
  (JNIEnv *, jclass, long,jstring);

/*
 * Class:     FaceTaggingInterface
 * Method:    native_init_FaceFeatureExtraction
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeInitFaceFeatureExtraction
  (JNIEnv *, jclass, long,jstring);

/*
 * Class:     FaceTaggingInterface
 * Method:    nativeRunFaceTaggingFromPath
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jobject JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeRunFaceTaggingFromPath
  (JNIEnv *, jclass, long,jstring,jint);

/*
 * Class:     FaceTaggingInterface
 * Method:    nativeRunFaceTaggingFromPath
 * Signature: (Ljava/lang/String;)I
 */
//JNIEXPORT jobject JNICALL  Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeRunFaceTaggingFromBuffer
 // (JNIEnv *env, jclass, long thiz,jbyteArray buffer,jint buffer_size,jint doType);

JNIEXPORT jobject JNICALL  Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeRunFaceTaggingFromBuffer
	(JNIEnv *env, jclass, long thiz,jbyteArray buffer,jint buffer_size,jint doType);
#ifdef __cplusplus
}
#endif




JNIEXPORT jlong JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeCreateObject
    (JNIEnv *, jclass)
{
    jlong result = 0;
   
    result =(jlong)new FaceAlbum();


    printf("nativeCreateObject exit\n");
    return result;
}
//获取版本号
JNIEXPORT jstring JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeGetVersion
    (JNIEnv *env, jclass,long thiz)
{
    
    string version = ((FaceAlbum*)thiz)->getVersion();
  
    
    jclass strClass = env->FindClass("Ljava/lang/String;");
    jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    jbyteArray bytes = env->NewByteArray(version.size());
    env->SetByteArrayRegion(bytes, 0, version.size(), (jbyte*)(version.c_str()) );
    jstring encoding = env->NewStringUTF("utf-8");
    return (jstring)env->NewObject(strClass, ctorID, bytes, encoding);
}

JNIEXPORT void JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeReleaseObject
    (JNIEnv *, jclass,long thiz)
{
    ((FaceAlbum*)thiz)->ReleaseFaceTagging();
}

JNIEXPORT jint JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeInitFaceDetect
  (JNIEnv *env, jclass obj,long thiz ,jstring classifierDir)
{
   
    const char *classifier = (env)->GetStringUTFChars(classifierDir,0);
    
    printf("nativeInitFaceDetect Enter ------ FaceDetect modePath %s\n",classifier);
    int res = ((FaceAlbum*)thiz)->FaceDetect_Init(classifier);
    printf("nativeInitFaceDetect exit ------------------Init result %d (0 success, -1 error)\n",res);
    return res;
    
    
}

JNIEXPORT jint JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeInitEyeLocation
    (JNIEnv *env, jclass obj,long thiz , jstring modePath)
{
    const char *EyeModelDir = (env)->GetStringUTFChars(modePath,0);
   

    printf("nativeInitEyeLocation Enter ------------------ EyeDetect modePath %s\n",EyeModelDir);
    int res = ((FaceAlbum*)thiz)->EyeDetect_Init(EyeModelDir);
    printf("nativeInitFaceDetect exit  ------------------ Init result %d(0 success, -1 error)\n",res);
    return res;
    
}

JNIEXPORT jint JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeInitFaceFeatureExtraction
    (JNIEnv *env, jclass obj,long thiz, jstring modelPath)
{
    const char *FeatureModelDir = (env)->GetStringUTFChars(modelPath,0);


    printf("nativeInitFaceFeatureExtraction Enter ------------------ EyeDetect modePath %s\n",FeatureModelDir);
    int res = ((FaceAlbum*)thiz)->FeatureExtractor_Init(FeatureModelDir);
    printf("nativeInitFaceFeatureExtraction exit  ------------------ Init result %d(0 success, -1 error)\n",res);
    return res;


}

jobject convertImageInfoFromCPlusPlusToJava(JNIEnv *env,long thiz,ImageInfo &imageInfo)
{
#ifdef PRINT_LOG
	ofstream &ofs_log = *((FaceAlbum*)thiz)->GetFileHandle();
#endif

    int len = imageInfo.mFaceNum;
    //   printf("detect Face Size : %d \n",len);


    //-----------------ImageInfo 函数方法和赋值--begin---------------------
    jclass imageinfoClass = (env)->FindClass("Lcom/xiaomi/micloud/thrift/gallery/face/ImageInfo;");
    if(imageinfoClass==NULL)
    {
        cout<<"Lcom/xiaomi/micloud/thrift/gallery/face/ImageInfo Class Is Null!!"<<endl;
    }
    //构造函数方法
    jmethodID image_costruct = env->GetMethodID(imageinfoClass , "<init>","()V"); //获得得构造函数Id  
    //创建Imageinfo 对象
    jobject  ImageInfo_obj =  env->NewObject(imageinfoClass, image_costruct);
    

    jmethodID setFaceNumMethodID = env->GetMethodID(imageinfoClass, "setFaceNum", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/ImageInfo;");
   
    env->CallObjectMethod(ImageInfo_obj,setFaceNumMethodID,imageInfo.mFaceNum);

    jmethodID setFaceVersionMethodID = env->GetMethodID(imageinfoClass, "setFaceVersion", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/ImageInfo;");

    env->CallObjectMethod(ImageInfo_obj,setFaceVersionMethodID,imageInfo.mFace_version);
    
    //jmethodID setFaceInfos = env->GetMethodID(imageinfoClass, "setFaceInfos", "(Lcom/xiaomi/micloud/thrift/gallery/face/FaceInfo;)Lcom/xiaomi/micloud/thrift/gallery/face/ImageInfo;");
    jmethodID addToFaceInfos = env->GetMethodID(imageinfoClass, "addToFaceInfos", "(Lcom/xiaomi/micloud/thrift/gallery/face/FaceInfo;)V");
    //-----------------ImageInfo 函数方法和赋值--end---------------------
   
    
    /*
    jfieldID FaceNumID = (env)->GetFieldID(imageinfoClass,"mFaceNum","I");
    (env)->SetShortField(ImageInfo_obj,FaceNumID,len);
    jfieldID versionID = (env)->GetFieldID(imageinfoClass,"mFaceVersion","I");
    (env)->SetShortField(ImageInfo_obj,versionID,imageInfo.mFace_version);
    */

#ifdef PRINT_LOG
    ofs_log<<"JNI end set FaceNum and version"<<endl;
#endif
     //-----------------FaceInfo 函数方法--begin---------------------
    jclass FaceInfoClass = (env)->FindClass("Lcom/xiaomi/micloud/thrift/gallery/face/FaceInfo;");

    if(FaceInfoClass==NULL)
    {
        cout<<"FaceInfoClass Is Null!!"<<endl;
    }

    //FaceInfo 构造函数方法
    jmethodID FaceInfo_costruct = env->GetMethodID(FaceInfoClass , "<init>","()V"); //获得得构造函数Id  

    jmethodID setFaceFeature = env->GetMethodID(FaceInfoClass, "setFaceFeature", "(Ljava/lang/String;)Lcom/xiaomi/micloud/thrift/gallery/face/FaceInfo;");

    jmethodID setFacePos = env->GetMethodID(FaceInfoClass, "setFacePos", "(Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;)Lcom/xiaomi/micloud/thrift/gallery/face/FaceInfo;");


    //-----------------FaceInfo 函数方法--end-----------------------//


    //--------------FacePos method 方法---begin----------------

    jclass FacePosClass = (env)->FindClass("Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");

    if(FacePosClass==NULL)
    {
        cout<<"FacePosClass Is Null!!"<<endl;
    }
    jmethodID FacePos_costruct = env->GetMethodID(FacePosClass , "<init>","()V"); //获得得构造函数


    jmethodID setFaceX = env->GetMethodID(FacePosClass, "setFaceX", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setFaceY = env->GetMethodID(FacePosClass, "setFaceY", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setFaceH = env->GetMethodID(FacePosClass, "setFaceH", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setFaceW = env->GetMethodID(FacePosClass, "setFaceW", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");

    jmethodID setEyeLeftX = env->GetMethodID(FacePosClass, "setEyeLeftX", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setEyeLeftY = env->GetMethodID(FacePosClass, "setEyeLeftY", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setEyeRightX = env->GetMethodID(FacePosClass, "setEyeRightX", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setEyeRightY = env->GetMethodID(FacePosClass, "setEyeRightY", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");

    jmethodID setFaceXScale = env->GetMethodID(FacePosClass, "setFaceXScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setFaceYScale = env->GetMethodID(FacePosClass, "setFaceYScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setFaceWScale = env->GetMethodID(FacePosClass, "setFaceWScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setFaceHScale = env->GetMethodID(FacePosClass, "setFaceHScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");

    jmethodID setEyeLeftXScale = env->GetMethodID(FacePosClass, "setEyeLeftXScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setEyeLeftYScale = env->GetMethodID(FacePosClass, "setEyeLeftYScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setEyeRightXScale = env->GetMethodID(FacePosClass, "setEyeRightXScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setEyeRightYScale = env->GetMethodID(FacePosClass, "setEyeRightYScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");

    //--------------FacePos method 方法----end---------------//

#ifdef PRINT_LOG
    ofs_log<<"JNI end method define"<<endl;
#endif

    for(int fi = 0; fi<len;++fi)
    {
        FaceInfo &faceInfo = imageInfo.mFaceInfo[fi];


        //--------------创建FacePos 对象 并对对象赋值-------------
        jobject  FacePos_obj =  env->NewObject(FacePosClass, FacePos_costruct);
        
#ifdef PRINT_LOG
        ofs_log<<"JNI end  FacePos_obj  "<<endl;
#endif
        //face scale
        env->CallObjectMethod(FacePos_obj,setFaceX,faceInfo.Face_X);
        env->CallObjectMethod(FacePos_obj,setFaceY,faceInfo.Face_Y);
        env->CallObjectMethod(FacePos_obj,setFaceW,faceInfo.Face_W);
        env->CallObjectMethod(FacePos_obj,setFaceH,faceInfo.Face_H);
#ifdef PRINT_LOG
        ofs_log<<"JNI end  setFace  "<<endl;
#endif        
        //eye 
        env->CallObjectMethod(FacePos_obj,setEyeLeftX,faceInfo.Eye_left_x);
        env->CallObjectMethod(FacePos_obj,setEyeLeftY,faceInfo.Eye_left_y);
        env->CallObjectMethod(FacePos_obj,setEyeRightX,faceInfo.Eye_right_x);
        env->CallObjectMethod(FacePos_obj,setEyeRightY,faceInfo.Eye_right_y);
#ifdef PRINT_LOG
        ofs_log<<"JNI end  setEyeLeft  "<<endl;
#endif             
        //face scale
        env->CallObjectMethod(FacePos_obj,setFaceXScale,faceInfo.FaceXScale);
        env->CallObjectMethod(FacePos_obj,setFaceYScale,faceInfo.FaceYScale);
        env->CallObjectMethod(FacePos_obj,setFaceWScale,faceInfo.FaceWScale);
        env->CallObjectMethod(FacePos_obj,setFaceHScale,faceInfo.FaceHScale);
#ifdef PRINT_LOG
        ofs_log<<"JNI end  setFaceScale  "<<endl;
#endif        
        //eye scale
        env->CallObjectMethod(FacePos_obj,setEyeLeftXScale,faceInfo.EyeLeftXScale);
        env->CallObjectMethod(FacePos_obj,setEyeLeftYScale,faceInfo.EyeLeftYScale);
        env->CallObjectMethod(FacePos_obj,setEyeRightXScale,faceInfo.EyeRightXScale);
        env->CallObjectMethod(FacePos_obj,setEyeRightYScale,faceInfo.EyeRightYScale);
#ifdef PRINT_LOG
        ofs_log<<"JNI end set setEyeScale  "<<endl;
#endif
        //--------------创建FacePos 对象 并对对象赋值------------*//

        //-------------创建FaceInfo 对象 并对 FaceInfo 赋值-----
        jobject  FaceInfo_obj =  env->NewObject(FaceInfoClass, FaceInfo_costruct);
           //-----set feature------
        jstring face_feature = env->NewStringUTF(faceInfo.faceFeature.c_str());
        env->CallObjectMethod(FaceInfo_obj,setFaceFeature,face_feature);
     //   env->DeleteLocalRef(face_feature);   
        //-----set facePos------
        env->CallObjectMethod(FaceInfo_obj,setFacePos,FacePos_obj);
#ifdef PRINT_LOG
        ofs_log<<"JNI end set FaceInfo  "<<endl;
#endif
        //-------------结束 创建FaceInfo 对象 并对 FaceInfo 赋值-----//

        //------------- ImageInfo 赋值 List FaceInfo-----
        env->CallObjectMethod(ImageInfo_obj,addToFaceInfos,FaceInfo_obj);


        /*
        FaceInfo &faceInfo = imageInfo.mFaceInfo[fi];
        env->CallVoidMethod(ImageInfo_obj,setFaceRectMethodID,fi,faceInfo.Face_X,faceInfo.Face_Y,faceInfo.Face_W,faceInfo.Face_H);
        env->CallVoidMethod(ImageInfo_obj,setEyePtMethodID,fi,faceInfo.Eye_left_x,faceInfo.Eye_left_y,faceInfo.Eye_right_x,faceInfo.Eye_right_y);

        env->CallVoidMethod(ImageInfo_obj,setFaceRectScaleMethodID,fi,faceInfo.FaceXScale,faceInfo.FaceYScale,faceInfo.FaceWScale,faceInfo.FaceHScale);
        env->CallVoidMethod(ImageInfo_obj,setEyePtScaleMethodID,fi,faceInfo.EyeLeftXScale,faceInfo.EyeLeftYScale,faceInfo.EyeRightXScale,faceInfo.EyeRightYScale);


        jstring face_feature = env->NewStringUTF(faceInfo.faceFeature.c_str());


        env->CallVoidMethod(ImageInfo_obj,setFeatureMethodID,fi,face_feature);

        env->DeleteLocalRef(face_feature);
        */
    }
   #ifdef PRINT_LOG
        ofs_log<<"JNI convertImageInfoFromCPlusPlusToJava return  "<<endl;
		
#endif
    return ImageInfo_obj;
}

//Allen debug

jobject convertImageInfoFromCPlusPlusToJava_test(JNIEnv *env,long thiz)
{
	ImageInfo imageInfo;
	imageInfo.mFaceNum = 0;
	imageInfo.mFace_version = 1001;

#ifdef PRINT_LOG
	ofstream &ofs_log = *((FaceAlbum*)thiz)->GetFileHandle();
#endif

    int len = imageInfo.mFaceNum;
    //   printf("detect Face Size : %d \n",len);


    //-----------------ImageInfo 函数方法和赋值--begin---------------------
    jclass imageinfoClass = (env)->FindClass("Lcom/xiaomi/micloud/thrift/gallery/face/ImageInfo;");
    if(imageinfoClass==NULL)
    {
        cout<<"Lcom/xiaomi/micloud/thrift/gallery/face/ImageInfo Class Is Null!!"<<endl;
    }
    //构造函数方法
    jmethodID image_costruct = env->GetMethodID(imageinfoClass , "<init>","()V"); //获得得构造函数Id  
    //创建Imageinfo 对象
    jobject  ImageInfo_obj =  env->NewObject(imageinfoClass, image_costruct);
    

    jmethodID setFaceNumMethodID = env->GetMethodID(imageinfoClass, "setFaceNum", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/ImageInfo;");
   
    env->CallObjectMethod(ImageInfo_obj,setFaceNumMethodID,imageInfo.mFaceNum);

    jmethodID setFaceVersionMethodID = env->GetMethodID(imageinfoClass, "setFaceVersion", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/ImageInfo;");

    env->CallObjectMethod(ImageInfo_obj,setFaceVersionMethodID,imageInfo.mFace_version);
    
    //jmethodID setFaceInfos = env->GetMethodID(imageinfoClass, "setFaceInfos", "(Lcom/xiaomi/micloud/thrift/gallery/face/FaceInfo;)Lcom/xiaomi/micloud/thrift/gallery/face/ImageInfo;");
    jmethodID addToFaceInfos = env->GetMethodID(imageinfoClass, "addToFaceInfos", "(Lcom/xiaomi/micloud/thrift/gallery/face/FaceInfo;)V");
    //-----------------ImageInfo 函数方法和赋值--end---------------------
   
    
    /*
    jfieldID FaceNumID = (env)->GetFieldID(imageinfoClass,"mFaceNum","I");
    (env)->SetShortField(ImageInfo_obj,FaceNumID,len);
    jfieldID versionID = (env)->GetFieldID(imageinfoClass,"mFaceVersion","I");
    (env)->SetShortField(ImageInfo_obj,versionID,imageInfo.mFace_version);
    */

#ifdef PRINT_LOG
    ofs_log<<"JNI end set FaceNum and version"<<endl;
#endif
     //-----------------FaceInfo 函数方法--begin---------------------
    jclass FaceInfoClass = (env)->FindClass("Lcom/xiaomi/micloud/thrift/gallery/face/FaceInfo;");

    if(FaceInfoClass==NULL)
    {
        cout<<"FaceInfoClass Is Null!!"<<endl;
    }

    //FaceInfo 构造函数方法
    jmethodID FaceInfo_costruct = env->GetMethodID(FaceInfoClass , "<init>","()V"); //获得得构造函数Id  

    jmethodID setFaceFeature = env->GetMethodID(FaceInfoClass, "setFaceFeature", "(Ljava/lang/String;)Lcom/xiaomi/micloud/thrift/gallery/face/FaceInfo;");

    jmethodID setFacePos = env->GetMethodID(FaceInfoClass, "setFacePos", "(Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;)Lcom/xiaomi/micloud/thrift/gallery/face/FaceInfo;");


    //-----------------FaceInfo 函数方法--end-----------------------//


    //--------------FacePos method 方法---begin----------------

    jclass FacePosClass = (env)->FindClass("Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");

    if(FacePosClass==NULL)
    {
        cout<<"FacePosClass Is Null!!"<<endl;
    }
    jmethodID FacePos_costruct = env->GetMethodID(FacePosClass , "<init>","()V"); //获得得构造函数


    jmethodID setFaceX = env->GetMethodID(FacePosClass, "setFaceX", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setFaceY = env->GetMethodID(FacePosClass, "setFaceY", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setFaceH = env->GetMethodID(FacePosClass, "setFaceH", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setFaceW = env->GetMethodID(FacePosClass, "setFaceW", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");

    jmethodID setEyeLeftX = env->GetMethodID(FacePosClass, "setEyeLeftX", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setEyeLeftY = env->GetMethodID(FacePosClass, "setEyeLeftY", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setEyeRightX = env->GetMethodID(FacePosClass, "setEyeRightX", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setEyeRightY = env->GetMethodID(FacePosClass, "setEyeRightY", "(I)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");

    jmethodID setFaceXScale = env->GetMethodID(FacePosClass, "setFaceXScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setFaceYScale = env->GetMethodID(FacePosClass, "setFaceYScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setFaceWScale = env->GetMethodID(FacePosClass, "setFaceWScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setFaceHScale = env->GetMethodID(FacePosClass, "setFaceHScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");

    jmethodID setEyeLeftXScale = env->GetMethodID(FacePosClass, "setEyeLeftXScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setEyeLeftYScale = env->GetMethodID(FacePosClass, "setEyeLeftYScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setEyeRightXScale = env->GetMethodID(FacePosClass, "setEyeRightXScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");
    jmethodID setEyeRightYScale = env->GetMethodID(FacePosClass, "setEyeRightYScale", "(D)Lcom/xiaomi/micloud/thrift/gallery/face/FacePosition;");

    //--------------FacePos method 方法----end---------------//

#ifdef PRINT_LOG
    ofs_log<<"JNI end method define"<<endl;
#endif

    for(int fi = 0; fi<len;++fi)
    {
        FaceInfo &faceInfo = imageInfo.mFaceInfo[fi];


        //--------------创建FacePos 对象 并对对象赋值-------------
        jobject  FacePos_obj =  env->NewObject(FacePosClass, FacePos_costruct);
        
#ifdef PRINT_LOG
        ofs_log<<"JNI end  FacePos_obj  "<<endl;
#endif
        //face scale
        env->CallObjectMethod(FacePos_obj,setFaceX,faceInfo.Face_X);
        env->CallObjectMethod(FacePos_obj,setFaceY,faceInfo.Face_Y);
        env->CallObjectMethod(FacePos_obj,setFaceW,faceInfo.Face_W);
        env->CallObjectMethod(FacePos_obj,setFaceH,faceInfo.Face_H);
#ifdef PRINT_LOG
        ofs_log<<"JNI end  setFace  "<<endl;
#endif        
        //eye 
        env->CallObjectMethod(FacePos_obj,setEyeLeftX,faceInfo.Eye_left_x);
        env->CallObjectMethod(FacePos_obj,setEyeLeftY,faceInfo.Eye_left_y);
        env->CallObjectMethod(FacePos_obj,setEyeRightX,faceInfo.Eye_right_x);
        env->CallObjectMethod(FacePos_obj,setEyeRightY,faceInfo.Eye_right_y);
#ifdef PRINT_LOG
        ofs_log<<"JNI end  setEyeLeft  "<<endl;
#endif             
        //face scale
        env->CallObjectMethod(FacePos_obj,setFaceXScale,faceInfo.FaceXScale);
        env->CallObjectMethod(FacePos_obj,setFaceYScale,faceInfo.FaceYScale);
        env->CallObjectMethod(FacePos_obj,setFaceWScale,faceInfo.FaceWScale);
        env->CallObjectMethod(FacePos_obj,setFaceHScale,faceInfo.FaceHScale);
#ifdef PRINT_LOG
        ofs_log<<"JNI end  setFaceScale  "<<endl;
#endif        
        //eye scale
        env->CallObjectMethod(FacePos_obj,setEyeLeftXScale,faceInfo.EyeLeftXScale);
        env->CallObjectMethod(FacePos_obj,setEyeLeftYScale,faceInfo.EyeLeftYScale);
        env->CallObjectMethod(FacePos_obj,setEyeRightXScale,faceInfo.EyeRightXScale);
        env->CallObjectMethod(FacePos_obj,setEyeRightYScale,faceInfo.EyeRightYScale);
#ifdef PRINT_LOG
        ofs_log<<"JNI end set setEyeScale  "<<endl;
#endif
        //--------------创建FacePos 对象 并对对象赋值------------*//

        //-------------创建FaceInfo 对象 并对 FaceInfo 赋值-----
        jobject  FaceInfo_obj =  env->NewObject(FaceInfoClass, FaceInfo_costruct);
           //-----set feature------
        jstring face_feature = env->NewStringUTF(faceInfo.faceFeature.c_str());
        env->CallObjectMethod(FaceInfo_obj,setFaceFeature,face_feature);
     //   env->DeleteLocalRef(face_feature);   
        //-----set facePos------
        env->CallObjectMethod(FaceInfo_obj,setFacePos,FacePos_obj);
#ifdef PRINT_LOG
        ofs_log<<"JNI end set FaceInfo  "<<endl;
#endif
        //-------------结束 创建FaceInfo 对象 并对 FaceInfo 赋值-----//

        //------------- ImageInfo 赋值 List FaceInfo-----
        env->CallObjectMethod(ImageInfo_obj,addToFaceInfos,FaceInfo_obj);
    }
   #ifdef PRINT_LOG
        ofs_log<<"JNI convertImageInfoFromCPlusPlusToJava return  "<<endl<<endl<<endl<<endl;
		
#endif

		
    return ImageInfo_obj;
}


JNIEXPORT jobject JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeRunFaceTaggingFromPath
    (JNIEnv *env, jclass, long thiz,jstring ImagePath,jint doType)
{
    const char *imagePath = (env)->GetStringUTFChars(ImagePath,0);
//	printf("image_Path is %s\n",imagePath);
    ((FaceAlbum*)thiz)->RunFaceTaggingFromPath(imagePath,doType);
	ImageInfo imageInfo;
	((FaceAlbum*)thiz)->GetProcessResult(imageInfo);

    return convertImageInfoFromCPlusPlusToJava(env, thiz,imageInfo);

    //return ImageInfo_obj;
}
JNIEXPORT jobject JNICALL Java_com_xiaomi_micloud_gallery_face_tagging_FaceTaggingInterface_nativeRunFaceTaggingFromBuffer
    (JNIEnv *env, jclass, long thiz,jbyteArray buffer,jint buffer_size,jint doType)
{ 
#ifdef PRINT_LOG
	ofstream &ofs_log = *((FaceAlbum*)thiz)->GetFileHandle();
#endif
	unsigned char* jimgData =(unsigned char*)env-> GetByteArrayElements(buffer, 0);
	if(jimgData==NULL ) 
    {
        cout<<"jimgData Is Null!!"<<endl;
    }
	
#ifdef PRINT_LOG
	ofs_log<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"JNI  1 buffer_size="<<buffer_size<<endl;
#endif
	((FaceAlbum*)thiz)->RunFaceTagging_ProcessExif( jimgData,buffer_size,doType );
	ImageInfo imageInfo;
	((FaceAlbum*)thiz)->GetProcessResult(imageInfo);

#ifdef PRINT_LOG
	ofs_log<<"JNI  2  "<<endl;
	ofs_log<<"  imageInfo.mFaceNum  ="<<imageInfo.mFaceNum<<"  imageInfo.mImageFlag  ="<<imageInfo.mImageFlag<<"  imageInfo.mFace_version  ="<<imageInfo.mFace_version<<endl;
	if(imageInfo.mFaceNum>0)
	{
			ofs_log<<"  imageInfo.mFaceInfo[0].Eye_left_x="<<imageInfo.mFaceInfo[0].Eye_left_x<<"   imageInfo.mFaceInfo[0].Eye_left_y ="<<imageInfo.mFaceInfo[0].Eye_left_y<<endl;
			ofs_log<<"  imageInfo.mFaceInfo[0].Eye_right_x="<<imageInfo.mFaceInfo[0].Eye_right_x<<"   imageInfo.mFaceInfo[0].Eye_right_y="<<imageInfo.mFaceInfo[0].Eye_right_y<<endl;
	}
	
#endif
    return convertImageInfoFromCPlusPlusToJava(env, thiz,imageInfo);

   // return ImageInfo_obj;
}


#endif


#endif