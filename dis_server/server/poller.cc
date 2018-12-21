#include "poller.h"

namespace dis_server {

	struct PollerEpoll: public PollerBase {
		void loop_once(int waitMs) override;
	};

	PollerBase* createPoller() { return new PollerEpoll();}

	void PollerEpoll::loop_once(int waitMs) {
		return;
	}
}