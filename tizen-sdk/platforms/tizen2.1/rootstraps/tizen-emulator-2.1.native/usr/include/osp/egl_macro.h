//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef _EGL_MACRO_H_
#define _EGL_MACRO_H_

#define eglGetError _SglGetError
#define eglGetDisplay   _SglGetDisplay
#define eglInitialize   _SglInitialize
#define eglTerminate _SglTerminate
#define eglQueryString _SglQueryString
#define eglGetConfigs _SglGetConfigs
#define eglChooseConfig _SglChooseConfig
#define eglGetConfigAttrib _SglGetConfigAttrib
#define eglCreateWindowSurface _SglCreateWindowSurface
#define eglCreatePbufferSurface _SglCreatePbufferSurface
#define eglCreatePixmapSurface _SglCreatePixmapSurface
#define eglDestroySurface   _SglDestroySurface
#define eglQuerySurface _SglQuerySurface
#define eglBindAPI _SglBindAPI
#define eglQueryAPI _SglQueryAPI
#define eglWaitClient _SglWaitClient
#define eglReleaseThread _SglReleaseThread
#define eglCreatePbufferFromClientBuffer _SglCreatePbufferFromClientBuffer
#define eglSurfaceAttrib _SglSurfaceAttrib
#define eglBindTexImage _SglBindTexImage
#define eglReleaseTexImage _SglReleaseTexImage
#define eglSwapInterval _SglSwapInterval
#define eglCreateContext _SglCreateContext
#define eglDestroyContext _SglDestroyContext
#define eglMakeCurrent _SglMakeCurrent
#define eglGetCurrentContext _SglGetCurrentContext
#define eglGetCurrentSurface _SglGetCurrentSurface
#define eglGetCurrentDisplay _SglGetCurrentDisplay
#define eglQueryContext _SglQueryContext
#define eglWaitGL _SglWaitGL
#define eglWaitNative _SglWaitNative
#define eglSwapBuffers _SglSwapBuffers
#define eglCopyBuffers _SglCopyBuffers
#define eglGetProcAddress _SglGetProcAddress
#define eglUpdateBufferOSP _SglUpdateBufferOSP

#endif // _EGL_MACRO_H_
