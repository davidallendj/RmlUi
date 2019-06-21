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
#include "StyleSheetNodeSelectorNthChild.h"
#include "../../Include/RmlUi/Core/ElementText.h"
#include "../../Include/RmlUi/Core/Log.h"
#include "../../Include/RmlUi/Core/StyleSheetKeywords.h"

namespace Rml {
namespace Core {

StyleSheetNodeSelectorNthChild::StyleSheetNodeSelectorNthChild()
{
}

StyleSheetNodeSelectorNthChild::~StyleSheetNodeSelectorNthChild()
{
}

// Returns true if the element index is (n * a) + b for a given integer value of n.
bool StyleSheetNodeSelectorNthChild::IsApplicable(const Element* element, int a, int b)
{
	Element* parent = element->GetParentNode();
	if (parent == NULL)
		return false;

	// Start counting elements until we find this one.
	int element_index = 1;
	for (int i = 0; i < parent->GetNumChildren(); i++)
	{
		Element* child = parent->GetChild(i);

		// Skip text nodes.
		if (dynamic_cast< ElementText* >(child) != NULL)
			continue;

		// If we've found our element, then break; the current index is our element's index.
		if (child == element)
			break;

		// Skip nodes without a display type.
		if (child->GetDisplay() == DISPLAY_NONE)
			continue;

		element_index++;
	}

	return IsNth(a, b, element_index);
}

}
}
