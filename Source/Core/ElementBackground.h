/*
 * This source file is part of RmlUi, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://github.com/mikke89/RmlUi
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 * Copyright (c) 2019 The RmlUi Team, and contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef RMLUICOREELEMENTBACKGROUND_H
#define RMLUICOREELEMENTBACKGROUND_H

#include "../../Include/RmlUi/Core/Box.h"
#include "../../Include/RmlUi/Core/Geometry.h"

namespace Rml {
namespace Core {

class Element;

/**
	@author Peter Curry
 */

class ElementBackground
{
public:
	ElementBackground(Element* element);
	~ElementBackground();

	/// Renders the element's border, if it has one.
	void RenderBackground();

	/// Marks the border geometry as dirty.
	void DirtyBackground();

private:
	// Generates the border geometry for the element.
	void GenerateBackground();
	// Generates the border geometry for a single box.
	void GenerateBackground(Vertex*& vertices, int*& indices, int& index_offset, const Box& box, const Colourb& colour);

	Element* element;

	// The background geometry.
	Geometry geometry;

	bool background_dirty;
};

}
}

#endif
