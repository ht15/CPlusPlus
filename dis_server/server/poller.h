#pragma once
#include <poll.h>
#include <unistd.h>
#include "handy_imp.h"

namespace dis_server {
	const int kMaxEvents = 2000;
	const int kReadEvent = POLLIN;
	const int kWriteEvent = POLLOUT;

	struct PollerBase: private noncopyable {
		int _lastActive;
		PollerBase():_lastActive(-1){}
		virtual void loop_once(int waitMs) = 0;
		virtual void addChannel(Channel* ch) = 0;
		virtual void removeChannel(Channel* ch) = 0;
		virtual void updateChannel(Channel* ch) = 0;
	};

	PollerBase* createPoller();
}