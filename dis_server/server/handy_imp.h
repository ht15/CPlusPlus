#pragma once
#include <memory>
#include <functional>

namespace dis_server {
	struct Channel;
	struct TcpConn;
	struct TcpServer;
	struct Gate;
	struct GateImp;

	typedef std::function<void()> Task;

	struct noncopyable {
	    noncopyable() {};
	    noncopyable(const noncopyable&) = delete;
	    noncopyable& operator=(const noncopyable&) = delete;
	};
	
}