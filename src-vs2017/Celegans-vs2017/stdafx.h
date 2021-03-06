// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// TODO: reference additional headers your program requires here
#include <stdlib.h>
#include <assert.h>

#ifdef _DEBUG
#define LOG(func) func printf(#func"\n");
#define LOGD(data) printf(#data": %d\n", data);
#define LOGP(data) printf(#data": %p\n", data);
#define LOGS(data) printf(#data": %s\n", data);
#else
#define LOG(func) func
#define LOGD(data)
#define LOGP(data)
#define LOGS(data)
#endif
