#include "channel.h"

namespace dis_server {

	Channel::Channel(Gate* gete, int fd, int events): _gate(gate), _fd(fd), _events(events) {
		_poller = _gate->_imp->_poller;
		_poller->addChannel(this);
	}

	Channel::~Channel() {
		close();
	}

	void Channel::close() {
		if( _fd >= 0) {
			_poller->removeChannel(this);
			::close(_fd);
			_fd = -1;
			handleRead();
		}
	}
}