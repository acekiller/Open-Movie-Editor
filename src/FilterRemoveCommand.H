/*  FilterRemoveCommand.H
 *
 *  Copyright (C) 2007 Richard Spindler <richard.spindler AT gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _FILTER_REMOVE_COMMAND_H_
#define _FILTER_REMOVE_COMMAND_H_

#include "Command.H"

#include <string>
using namespace std;

namespace nle
{

class FilterClip;
class FilterData;

class FilterRemoveCommand : public Command
{
	public:
		FilterRemoveCommand( FilterClip* clip, int filter );
		~FilterRemoveCommand();
		void doo();
		void undo();
	private:
		int m_clip;
		int m_track;
		int m_filterNr;
		string m_identifier;
		FilterData* m_data;
};

} /* namespace nle */

#endif /* _FILTER_REMOVE_COMMAND_H_ */
