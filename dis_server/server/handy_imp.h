#pragma once
#include <memory>
#include <functional>
#include <utility>

namespace dis_server {
	struct Channel;
	struct TcpConn;
	struct TcpServer;
	struct Gate;
	struct GateImp;

	struct noncopyable {
	    noncopyable() {};
	    noncopyable(const noncopyable&) = delete;
	    noncopyable& operator=(const noncopyable&) = delete;
	};
	
}