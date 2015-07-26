/*
Copyright 2015 Johan Gunnarsson <johan.gunnarsson@gmail.com>

This file is part of BTFS.

BTFS is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

BTFS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with BTFS.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BTFS_H
#define BTFS_H

#include <libtorrent/peer_request.hpp>

#define BTFS_VERSION_MAJOR 1
#define BTFS_VERSION_MINOR 0

namespace btfs
{

class Part;
class Read;

typedef std::vector<Part>::iterator parts_iter;
typedef std::list<Read*>::iterator reads_iter;

class Part
{
	friend class Read;

public:
	Part(libtorrent::peer_request p, char *b) : part(p), buf(b),
			filled(false) {
	}

private:
	libtorrent::peer_request part;

	char *buf;

	bool filled;
};

class Read
{
public:
	Read(char *buf, int index, int offset, int size);

	void copy(int piece, char *buffer, int size);

	void trigger();

	bool finished();

	int size();

	int read();

private:
	std::vector<Part> parts;
};

}

#endif
