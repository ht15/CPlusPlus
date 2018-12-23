#include "poller.h"
#include <sys/epoll.h>
#include <set>
#include <memory.h>
#include "gate.h"

namespace dis_server {

	struct PollerEpoll: public PollerBase {
		int _fd;
		std::set<Channel*> _liveChannels;
		struct epoll_event _activeEvs[kMaxEvents];
		PollerEpoll();
		~PollerEpoll();
		void addChannel(Channel* ch) override;
		void removeChannel(Channel* ch) override;
		void updateChannel(Channel* ch) override;
		void loop_once(int waitMs) override;
	};

	PollerBase* createPoller() { return new PollerEpoll();}

	PollerEpoll::PollerEpoll() {
		_fd = epoll_create1(EPOLL_CLOEXEC); //  it will not work when using EXEC
	}

	PollerEpoll::~PollerEpoll() {
		while(_liveChannels.size()) {
			(*_liveChannels.begin())->close();
		}
		::close(_fd);
	}

	void PollerEpoll::addChannel(Channel* ch) {
		struct epoll_event ev;
		memset(&ev, 0, sizeof(ev));
		ev.events = ch->events();
		ev.data.ptr = ch;

		int ret = epoll_ctl(_fd, EPOLL_CTL_ADD, ch->fd(), &ev);
		if(ret) {
			printf("epoll_ctl error\n");
			fflush(stdout);
		}
		_liveChannels.insert(ch);
	}

	void PollerEpoll::removeChannel(Channel* ch) {
		_liveChannels.erase(ch);
		for( int i = _lastActive; i>=0; i--) {
			if(_activeEvs[i].data.ptr == ch) {
				_activeEvs[i].data.ptr = nullptr;
				break;
			}
		}
	}

	void PollerEpoll::updateChannel(Channel* ch) {
		return;
	}

	void PollerEpoll::loop_once(int waitMs) {
		_lastActive = epoll_wait(_fd, _activeEvs, kMaxEvents, waitMs);
		while(--_lastActive >= 0) {
			Channel* ch = (Channel*) _activeEvs[_lastActive].data.ptr;
			int events = _activeEvs[_lastActive].events
			if(ch) {
				if(events & (kReadEvent | POLLERR)) {
					ch->handleRead();
				}
				else if(events & kWriteEvent) {
					ch->handleWrite();
				}
				else {
					printf("error\n");
					fflush(stdout);
				}
			}
		}
	}
}