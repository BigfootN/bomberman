#include "libs.h"

#ifdef IS_WINDOWS
Thread thread_create(LP_THREAD_START_ROUTINE fct, LPVOID param) {
	HANDLE ret;

	ret = CreateThread(NULL, 0, fct, param, 0, NULL);

	return ret;
}

void thread_join(Thread thread) {
	WaitForSingleObject(thread, INFINITE);
}

#else
Thread thread_create(void* (*fct)(void*), void* param) {
	Thread ret;

	ret = malloc(sizeof(*ret));
	pthread_create(ret, NULL, fct, param);

	return ret;
}

void thread_join(Thread thread) {
	pthread_join(*thread, NULL);
}

#endif
