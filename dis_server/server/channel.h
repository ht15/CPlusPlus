#pragma once 
#include "gate.h"
#include "poller.h"

namespace dis_server {
	struct Channel: private noncopyable {
		Channel(Gate* gete, int fd, int events);
		~Channel();
		Gate* getGate() { return _gate;}
		int fd() { return _fd;}  // in python can set as property
		short events() { return _events;}

		void close();
		void onRead(Task&& readcb) { _readcb = std::move(readcb);}
		void onWrite(Task&& writecb) { _writecb = std::move(writecb);}

		void handleRead() { _readcb();}
		void handeWrite() { _writecb();}

	protected:
		Gate* _gate;
		PollerBase* _poller;
		int _fd;
		short _events;
		//int64_t _id;
		std::function<void()> _readcb, _writecb, _errorcb;  // #include <functional>
	};
}