// The MIT License (MIT)
//
// Copyright (c) 2013 Dan Ginsburg, Budirijanto Purnomo
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

//
// Book:      OpenGL(R) ES 3.0 Programming Guide, 2nd Edition
// Authors:   Dan Ginsburg, Budirijanto Purnomo, Dave Shreiner, Aaftab Munshi
// ISBN-10:   0-321-93388-5
// ISBN-13:   978-0-321-93388-1
// Publisher: Addison-Wesley Professional
// URLs:      http://www.opengles-book.com
//            http://my.safaribooksonline.com/book/animation-and-3d/9780133440133
//
// ESUtil.c
//
//    A utility library for OpenGL ES.  This library provides a
//    basic common framework for the example applications in the
//    OpenGL ES 3.0 Programming Guide.
//

///
//  Includes
//
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "es_util.h"
#include "es_util_win.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image_write.h"

#ifdef ANDROID
#include <android/log.h>
#include <android_native_app_glue.h>
#include <android/asset_manager.h>
typedef AAsset esFile;
#else
typedef FILE esFile;
#endif

#ifdef __APPLE__
#include "FileWrapper.h"
#endif


#ifndef __APPLE__

///
// GetContextRenderableType()
//
//    Check whether EGL_KHR_create_context extension is supported.  If so,
//    return EGL_OPENGL_ES3_BIT_KHR instead of EGL_OPENGL_ES2_BIT
//
EGLint GetContextRenderableType(EGLDisplay eglDisplay) {
#ifdef EGL_KHR_create_context
    const char *extensions = eglQueryString(eglDisplay, EGL_EXTENSIONS);

    // check whether EGL_KHR_create_context is in the extension string
    if (extensions != NULL && strstr(extensions, "EGL_KHR_create_context")) {
        // extension is supported
        return EGL_OPENGL_ES3_BIT_KHR;
    }
#endif
    // extension is not supported
    return EGL_OPENGL_ES2_BIT;
}

#endif

//////////////////////////////////////////////////////////////////
//
//  Public Functions
//
//

///
//  esCreateWindow()
//
//      title - name for title bar of window
//      width - width of window to create
//      height - height of window to create
//      flags  - bitwise or of window creation flags
//          ES_WINDOW_ALPHA       - specifies that the framebuffer should have alpha
//          ES_WINDOW_DEPTH       - specifies that a depth buffer should be created
//          ES_WINDOW_STENCIL     - specifies that a stencil buffer should be created
//          ES_WINDOW_MULTISAMPLE - specifies that a multi-sample buffer should be created
//
GLboolean ESUTIL_API esCreateWindow(ESContext *esContext, const char *title, GLint width, GLint height, GLuint flags) {
#ifndef __APPLE__
    EGLConfig config;
    EGLint majorVersion;
    EGLint minorVersion;
    EGLint contextAttribs[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};

    if (esContext == NULL) {
        return GL_FALSE;
    }

#ifdef ANDROID
    // For Android, get the width/height from the window rather than what the
    // application requested.
    esContext->width = ANativeWindow_getWidth ( esContext->eglNativeWindow );
    esContext->height = ANativeWindow_getHeight ( esContext->eglNativeWindow );
#else
    esContext->width = width;
    esContext->height = height;
#endif

    if (!WinCreate(esContext, title)) {
        return GL_FALSE;
    }

    esContext->eglDisplay = eglGetDisplay(esContext->eglNativeDisplay);
    if (esContext->eglDisplay == EGL_NO_DISPLAY) {
        return GL_FALSE;
    }

    // Initialize EGL
    if (!eglInitialize(esContext->eglDisplay, &majorVersion, &minorVersion)) {
        return GL_FALSE;
    }

    {
        EGLint numConfigs = 0;
        EGLint attribList[] =
                {
                        EGL_RED_SIZE, 5,
                        EGL_GREEN_SIZE, 6,
                        EGL_BLUE_SIZE, 5,
                        EGL_ALPHA_SIZE, (flags & ES_WINDOW_ALPHA) ? 8 : EGL_DONT_CARE,
                        EGL_DEPTH_SIZE, (flags & ES_WINDOW_DEPTH) ? 8 : EGL_DONT_CARE,
                        EGL_STENCIL_SIZE, (flags & ES_WINDOW_STENCIL) ? 8 : EGL_DONT_CARE,
                        EGL_SAMPLE_BUFFERS, (flags & ES_WINDOW_MULTISAMPLE) ? 1 : 0,
                        // if EGL_KHR_create_context extension is supported, then we will use
                        // EGL_OPENGL_ES3_BIT_KHR instead of EGL_OPENGL_ES2_BIT in the attribute list
                        EGL_RENDERABLE_TYPE, GetContextRenderableType(esContext->eglDisplay),
                        EGL_NONE
                };

        // Choose config
        if (!eglChooseConfig(esContext->eglDisplay, attribList, &config, 1, &numConfigs)) {
            return GL_FALSE;
        }

        if (numConfigs < 1) {
            return GL_FALSE;
        }
    }


#ifdef ANDROID
    // For Android, need to get the EGL_NATIVE_VISUAL_ID and set it using ANativeWindow_setBuffersGeometry
    {
       EGLint format = 0;
       eglGetConfigAttrib ( esContext->eglDisplay, config, EGL_NATIVE_VISUAL_ID, &format );
       ANativeWindow_setBuffersGeometry ( esContext->eglNativeWindow, 0, 0, format );
    }
#endif // ANDROID

    // Create a surface
    esContext->eglSurface = eglCreateWindowSurface(esContext->eglDisplay, config,
                                                   esContext->eglNativeWindow, NULL);

    if (esContext->eglSurface == EGL_NO_SURFACE) {
        return GL_FALSE;
    }

    // Create a GL context
    esContext->eglContext = eglCreateContext(esContext->eglDisplay, config,
                                             EGL_NO_CONTEXT, contextAttribs);

    if (esContext->eglContext == EGL_NO_CONTEXT) {
        return GL_FALSE;
    }

    // Make the context current
    if (!eglMakeCurrent(esContext->eglDisplay, esContext->eglSurface,
                        esContext->eglSurface, esContext->eglContext)) {
        return GL_FALSE;
    }

#endif // #ifndef __APPLE__

    return GL_TRUE;
}

///
//  esRegisterDrawFunc()
//
void ESUTIL_API esRegisterDrawFunc(ESContext *esContext, void ( ESCALLBACK *drawFunc )(ESContext *)) {
    esContext->drawFunc = drawFunc;
}

///
//  esRegisterShutdownFunc()
//
void ESUTIL_API esRegisterShutdownFunc(ESContext *esContext, void ( ESCALLBACK *shutdownFunc )(ESContext *)) {
    esContext->shutdownFunc = shutdownFunc;
}

///
//  esRegisterUpdateFunc()
//
void ESUTIL_API esRegisterUpdateFunc(ESContext *esContext, void ( ESCALLBACK *updateFunc )(ESContext *, float)) {
    esContext->updateFunc = updateFunc;
}


///
//  esRegisterKeyFunc()
//
void ESUTIL_API esRegisterKeyFunc(ESContext *esContext,
                                  void ( ESCALLBACK *keyFunc )(ESContext *, unsigned char, int, int)) {
    esContext->keyFunc = keyFunc;
}


///
// esLogMessage()
//
//    Log an error message to the debug output for the platform
//
void ESUTIL_API esLogMessage(const char *formatStr, ...) {
    va_list params;
    char buf[BUFSIZ];

    va_start (params, formatStr);
    vsprintf(buf, formatStr, params);

#ifdef ANDROID
    __android_log_print ( ANDROID_LOG_INFO, "esUtil" , "%s", buf );
#else
    printf("%s", buf);
#endif

    va_end (params);
}

///
// esFileRead()
//
//    Wrapper for platform specific File open
//
static esFile *esFileOpen(void *ioContext, const char *fileName) {
    esFile *pFile = NULL;

#ifdef ANDROID

    if ( ioContext != NULL )
    {
       AAssetManager *assetManager = ( AAssetManager * ) ioContext;
       pFile = AAssetManager_open ( assetManager, fileName, AASSET_MODE_BUFFER );
    }

#else
#ifdef __APPLE__
    // iOS: Remap the filename to a path that can be opened from the bundle.
    fileName = GetBundleFileName ( fileName );
#endif

    pFile = fopen(fileName, "rb");
#endif

    return pFile;
}

///
// esFileRead()
//
//    Wrapper for platform specific File close
//
static void esFileClose(esFile *pFile) {
    if (pFile != NULL) {
#ifdef ANDROID
        AAsset_close ( pFile );
#else
        fclose(pFile);
        pFile = NULL;
#endif
    }
}

///
// esFileRead()
//
//    Wrapper for platform specific File read
//
static int esFileRead(esFile *pFile, int bytesToRead, void *buffer) {
    int bytesRead = 0;

    if (pFile == NULL) {
        return bytesRead;
    }

#ifdef ANDROID
    bytesRead = AAsset_read ( pFile, buffer, bytesToRead );
#else
    bytesRead = fread(buffer, bytesToRead, 1, pFile);
#endif

    return bytesRead;
}

static long esFileGetLength(esFile *pFile) {
    long length;
#ifdef ANDROID
    length = AAsset_getLength(pFile);
#else
    fseek(pFile, 0, SEEK_END);
    length = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);
#endif
    return length;
}

static int esFileSeek(esFile *pFile, long offset, int origin) {
    int pos = 0;

    if (pFile == NULL) {
        return pos;
    }

#ifdef ANDROID
    pos = AAsset_seek ( pFile, offset, origin );
#else
    pos = fseek(pFile, offset, origin);
#endif

    return pos;
}


///
// esLoadImage()
//
//    Loads a 8-bit, 24-bit or 32-bit image from a file
//
unsigned char *ESUTIL_API esLoadImage(void *ioContext, const char *fileName, int *width, int *height,
                                      int *channels_in_file) {
    // Open the file for reading
    esFile *fp = esFileOpen(ioContext, fileName);
    if (fp == NULL) {
        // Log error as 'error in opening the input file from apk'
        esLogMessage("esLoadImage FAILED to load : { %s }\n", fileName);
        return NULL;
    }
    unsigned char *buffer = stbi_load_from_file(fp, width, height, channels_in_file, 0);
    esFileClose(fp);
    return buffer;
}

//
///
/// \brief Load a shader, check for compile errors, print error messages to output log
/// \param type Type of shader (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER)
/// \param shaderSrc Shader source string
/// \return A new shader object on success, 0 on failure
//
GLuint ESUTIL_API esLoadShader(GLenum type, const char *shaderSrc) {
    GLuint shader;
    GLint compiled;

    // Create the shader object
    shader = glCreateShader(type);

    if (shader == 0) {
        return 0;
    }

    // Load the shader source
    glShaderSource(shader, 1, &shaderSrc, NULL);

    // Compile the shader
    glCompileShader(shader);

    // Check the compile status
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

    if (!compiled) {
        GLint infoLen = 0;

        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1) {
            char *infoLog = (char *) (malloc(sizeof(char) * infoLen));

            glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
            esLogMessage("Error compiling shader:\n%s\n", infoLog);

            free(infoLog);
        }

        glDeleteShader(shader);
        return 0;
    }

    return shader;

}


//
///
/// \brief Load a vertex and fragment shader, create a program object, link program.
//         Errors output to log.
/// \param vertShaderSrc Vertex shader source code
/// \param fragShaderSrc Fragment shader source code
/// \return A new program object linked with the vertex/fragment shader pair, 0 on failure
//
GLuint ESUTIL_API esLoadProgram(const char *vertShaderSrc, const char *fragShaderSrc) {
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programObject;
    GLint linked;

    // Load the vertex/fragment shaders
    vertexShader = esLoadShader(GL_VERTEX_SHADER, vertShaderSrc);

    if (vertexShader == 0) {
        return 0;
    }

    fragmentShader = esLoadShader(GL_FRAGMENT_SHADER, fragShaderSrc);

    if (fragmentShader == 0) {
        glDeleteShader(vertexShader);
        return 0;
    }

    // Create the program object
    programObject = glCreateProgram();

    if (programObject == 0) {
        return 0;
    }

    glAttachShader(programObject, vertexShader);
    glAttachShader(programObject, fragmentShader);

    // Link the program
    glLinkProgram(programObject);

    // Check the link status
    glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

    if (!linked) {
        GLint infoLen = 0;

        glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1) {
            char *infoLog = (char *) (malloc(sizeof(char) * infoLen));

            glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
            esLogMessage("Error linking program:\n%s\n", infoLog);

            free(infoLog);
        }

        glDeleteProgram(programObject);
        return 0;
    }

    // Free up no longer needed shader resources
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return programObject;
}


bool ESUTIL_API esGenerateTexture(Texture *texture) {
    if ((texture->width >= MaxSlideLimit || texture->height >= MaxSlideLimit))
        return kFailure;
    GLint filtering = texture->filter == TEXTURE_FILTER_LINEAR ? GL_LINEAR : GL_NEAREST;
    GLint internal_format = 0;
    GLenum format = 0;
    int channel = 0;
    switch (texture->format) {
        case TEXTURE_FORMAT_RGBA:
            internal_format = format = GL_RGBA;
            channel = 4;
            break;
        case TEXTURE_FORMAT_RGB:
            internal_format = format = GL_RGB;
            channel = 3;
            break;
        case TEXTURE_FORMAT_LUMINANCE:
            internal_format = format = GL_RED;
            channel = 1;
            break;
        default:
            esLogMessage("Error texture (%s) format.\n", texture->name);
            return kFailure;
    }
    GLint wrap = GL_CLAMP_TO_EDGE;
    switch (texture->wrap) {
        case TEXTURE_WRAP_CLAMP:
            wrap = GL_CLAMP_TO_EDGE;
            break;
        case TEXTURE_WRAP_REPEAT:
            wrap = GL_REPEAT;
            break;
        case TEXTURE_WRAP_MIRRORED:
            wrap = GL_MIRRORED_REPEAT;
            break;
        default:
            return kFailure;
    }
    if (texture->channel != channel) {
        esLogMessage("Error texture (%s) channel.\n", texture->name);
        return kFailure;
    }
    glGenTextures(1, &texture->id);
    glBindTexture(GL_TEXTURE_2D, texture->id);
    glTexImage2D(GL_TEXTURE_2D, 0, internal_format, texture->width, texture->height, 0, format, GL_UNSIGNED_BYTE,
                 texture->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtering);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtering);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);

    return kSuccess;
}

///
// Load texture from disk
//
bool ESUTIL_API esLoadTexture(void *ioContext, Texture *texture, const char *filename) {
    texture->data = (unsigned char *) (esLoadImage(ioContext, filename, &texture->width,
                                                   &texture->height, &texture->channel));
    if (texture->data == NULL) {
        esLogMessage("Error loading (%s) image.\n", filename);
        return kFailure;
    }
    bool ret = esGenerateTexture(texture);
    free(texture->data);
    texture->data = NULL;
    return ret;
}

int ESUTIL_API esSaveTextureToPng(unsigned char *data, int width, int height, int channel, const char *filename) {
    return stbi_write_png(filename, width, height, channel, data, 0);
}
