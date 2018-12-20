#pragma once
#include "handy_imp.h"
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


}