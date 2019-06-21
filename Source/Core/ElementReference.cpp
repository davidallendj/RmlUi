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

#include "precompiled.h"
#include "../../Include/RmlUi/Core/ElementReference.h"
#include "../../Include/RmlUi/Core/Element.h"

namespace Rml {
namespace Core {

ElementReference::ElementReference(Element* _element)
{
	element = NULL;
	*this = _element;
}

ElementReference::ElementReference(const ElementReference& copy)
{
	element = NULL;
	*this = copy;
}

ElementReference::~ElementReference()
{
	*this = NULL;
}

// Returns true if this reference is bound to an element.
ElementReference::operator bool() const
{
	return (element != NULL);
}

// Assigns a new element for this reference to point to.
ElementReference& ElementReference::operator=(Element* _element)
{
	if (_element != NULL)
		_element->AddReference();

	if (element != NULL)
		element->RemoveReference();

	element = _element;
	return *this;
}

// Assigns a new element for this reference, from another reference.
ElementReference& ElementReference::operator=(const ElementReference& element_reference)
{
	*this = (element_reference.element);
	return *this;
}

// Returns a reference to the underlying element.
Element* ElementReference::operator*()
{
	return element;
}

// Returns a reference to the underlying element.
Element* ElementReference::operator->()
{
	return element;
}

// Equality operator for the reference. Used for STL containers.
bool ElementReference::operator==(const ElementReference& rhs) const
{
	return element == rhs.element;
}

// Equality operator for the reference.
bool ElementReference::operator==(const Element* rhs) const
{
	return element == rhs;
}

// Less-than operator for the reference. Used for STL containers.
bool ElementReference::operator<(const ElementReference& rhs) const
{
	return element < rhs.element;
}

// Inequality operator for the reference.
bool ElementReference::operator!=(const ElementReference& rhs) const
{
	return element != rhs.element;
}

// Inequality operator for the reference.
bool ElementReference::operator!=(const Element* rhs) const
{
	return element != rhs;
}

}
}
