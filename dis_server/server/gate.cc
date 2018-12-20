#include "gate.h"
#include "poller.h"
#include <atomic>
using namespace std;

namespace dis_server {
	struct GateImp {
		Gate* _gate;
		PollerBase* _poller;
		std::atomic<bool> _exit;

		GateImp(Gate* gate);
		~GateImp();

		void init();
		Gate& exit() { _exit = true; return *_gate;}
		bool exited() { return _exit;}
		void loop();
		void loop_once(int waitMs) { _poller->loop_once(waitMs);}
	};

	Gate::Gate(){
		_imp.reset(new GateImp(this));
		_imp->init();
	}

	Gate::~Gate(){}

	void Gate::loop(){ _imp->loop();}

	Gate& Gate::exit() { return _imp->exit();}

	bool Gate::exited() { return _imp->exited();}

	GateImp::GateImp(Gate* gate):
		_gate(gate), _poller(createPoller()), _exit(false)
	{
	}

	GateImp::~GateImp() {}

	void GateImp::loop() {
		while ( !_exit)
			loop_once(10000);
	}

	void GateImp::init() {

	}

}