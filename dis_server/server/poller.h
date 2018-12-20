#pragma once
#include <poll.h>

namespace dis_server {
	const int kMaxEvents = 2000;
	const int kReadEvent = POLLIN;
	const int kWriteEvent = POLLOUT;

	struct PollerBase: private noncopyable {
		void loop_once(int waitMs){}
	};

	PollerBase* createPoller(){}
}