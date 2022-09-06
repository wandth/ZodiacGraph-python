//
//    ZodiacGraph - A general-purpose, circular node graph UI module.
//    Copyright (C) 2015  Clemens Sielaff
//
//    The MIT License
//
//    Permission is hereby granted, free of charge, to any person obtaining a copy of
//    this software and associated documentation files (the "Software"), to deal in
//    the Software without restriction, including without limitation the rights to
//    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
//    of the Software, and to permit persons to whom the Software is furnished to do so,
//    subject to the following conditions:
//
//    The above copyright notice and this permission notice shall be included in all
//    copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//    SOFTWARE.
//

#ifndef ZODIAC_NODEUTILS_H
#define ZODIAC_NODEUTILS_H

///
/// \file utils.h
///
/// \brief Common utils and enums that are used throughout the code.
///

#include <QRectF>
#include <QtGlobal>

namespace zodiac
{
	Q_NAMESPACE

	///
	/// \brief Z-Positions of items in the node view.
	///
	/// Is not an enum class, because this enum is often used with QGraphicItem's setZValue(), which requires an integer.
	/// And using a pure enum is easier.
	///
	enum zStack
	{
		EDGE = -10,  ///< Edges are all the way in the background.
		NODE_CLOSED = 0,    ///< A closed Node is the base line depth at zero.
		NODE_EXPANDED = 10,   ///< An expanded Node automatically overlays a closed one.
		NODE_ACTIVE = 20,   ///< The active Node (the last selected one) overlays other expanded Nodes.
		EDGE_LABEL = 30,   ///< EdgeLabel%s overlay all Node%s.
		DRAW_EDGE = 40    ///< The DrawEdge is drawn in front of overthing.
	};
	Q_ENUM_NS(zStack)

	///
	/// \enum NodeExpansion
	///
	/// Describes, whether the incoming or the outgoing Plug%s of a Node are displayed -- or both or none.
	///
	/// Note that the state change is immediate, so a Node might be in a NodeExpansion::NONE state, while its Plug%s are
	/// still displaying the collapse-animation.
	///
	enum class NodeExpansion
	{
		NONE = 0, ///< No expansion.
		IN = 1, ///< Incoming Plug%s are expanded.
		OUT = 2, ///< Outgoing Plug%s are expanded.
		BOTH = 3  ///< Both types of Plug are expanded.
	};
	Q_ENUM_NS(NodeExpansion)

	///
	/// \brief There are currently 2 visually different types of EdgeArrow%s used in the graph.
	///
	/// Even though they are drawn differently, both are functionally the same.
	/// The only difference is the original arrow shape they use for generating their own. <br>
	/// This enum is a numeration of these original arrow shapes.
	///
	enum class ArrowKind
	{
		SINGLE = 0, ///< A single triangle pointing into the direction of the edge.
		DOUBLE = 1, ///< Two mirrored triangles, pointing along different directions of the edge.
	};
	Q_ENUM_NS(ArrowKind)

	///
	/// \brief The direction in which a Plug leads in relation to its Node.
	///
	enum class PlugDirection
	{
		IN = 0, ///< INcoming Plug%s only accept incoming PlugEdge%s.
		OUT = 1, ///< OUTcoming Plug%s only accept outoing PlugEdge%s.
		BOTH = 2, ///< Plug%s cannot work in BOTH directions, but BOTH can be used as an argument.
	};
	Q_ENUM_NS(PlugDirection)

} // namespace zodiac


///
/// \brief Constructs a quadrat with a given side length.
///
/// Solely a convenience function as the Zodiac Graph design requires many quadratic QRectF%s of various sidelengths.
///
/// \param sidelength   Length of one side of the quadrat
///
/// \return             Rectangle around zero with given side length.
///
Q_DECL_EXPORT inline QRectF quadrat(qreal sidelength)
{
	return QRectF(-sidelength, -sidelength, sidelength * 2, sidelength * 2);
}

#endif // ZODIAC_NODEUTILS_H
