//
// "$Id: Fl_Split.h,v 1.1 2001/07/23 09:50:04 spitzak Exp $"
//
// Tile header file for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-1999 by Bill Spitzak and others.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems to "fltk-bugs@easysw.com".
//

#ifndef Fl_Split_H
#define Fl_Split_H

#include <FL/Fl_Group.H>


class  Fl_Split : public Fl_Group {
protected:
  void layout();
public:
  int handle(int);
  Fl_Split(int X,int Y,int W,int H,const char*l=0) : Fl_Group(X,Y,W,H,l) {}
  void position(int, int, int, int);
  void resize(int X,int Y,int W,int H);

};

#endif

//
// End of "$Id: Fl_Split.h,v 1.1 2001/07/23 09:50:04 spitzak Exp $".
//
