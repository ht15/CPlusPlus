#pragma once
#include "handy_imp.h"
#include "poller.h"
namespace dis_server {

	// typedef std::shared_ptr<TcpConn> TcpConnPtr;
	// typedef std::shared_ptr<TcpServer> TcpServerPtr;
	struct BaseGate: private noncopyable {
		virtual Gate* allocGate() = 0;
	};

	struct Gate: public BaseGate {
		Gate();
		~Gate();

		void loop();

		Gate& exit();
		bool exited();

		virtual Gate* allocGate() { return this;}

	public:
		std::unique_ptr<GateImp> _imp;
	};

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