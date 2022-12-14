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

#ifndef NODECTRL_H
#define NODECTRL_H

#include <QObject>
#include <QHash>

#include "ZodiacGraph/nodehandle.h"
#include "ZodiacGraph/plughandle.h"

class MainCtrl;

///
/// \brief Controller class for managing a single node in the graph.
///
class NodeCtrl : public QObject
{
Q_OBJECT

public: // methods

	///
	/// \brief Constructor.
	///
	/// \param [in] manager Manager for all NodeCtrls.
	/// \param [in] node    Handle for the zodiac::Node of this logical node.
	///
	explicit NodeCtrl(MainCtrl *manager, zodiac::NodeHandle node);

	///
	/// \brief Returns the name of the controlled node.
	///
	/// \return The name of the controlled node.
	///
	inline QString getName() const { return m_node.getName(); }

	///
	/// \brief Sets s new name for this NodeCtrl.
	///
	/// \param [in] name    New name of this NodeCtrl.
	///
	void rename(const QString &name);

	///
	/// \brief Direct access to the zodiac::NodeHandle of this NodeCtrl.
	///
	/// \return The managed zodiac::NodeHandle.
	///
	inline zodiac::NodeHandle getNodeHandle() const { return m_node; }

	///
	/// \brief Returns a list of PlugHandle%s to all zodiac::Plug%s of the managed Node.
	///
	/// \return Handles to all zodiac::Plug%s of the managed Node.
	///
	inline QList<zodiac::PlugHandle> getPlugHandles() const { return m_node.getPlugs(); }

	///
	/// \brief Only nodes with no connections can be removed.
	///
	/// \return <i>true</i> if the node could be removed -- <i>false</i> otherwise.
	///
	inline bool isRemovable() const { return m_node.isRemovable(); }

	///
	/// \brief Add a new incoming plug to the logical node and its representations.
	///
	/// \param [in] name        The proposed name of the plug.
	///
	/// \return                 Handle of the created Plug.
	///
	inline zodiac::PlugHandle addIncomingPlug(const QString &name) { return addPlug(name, true); }

	///
	/// \brief Add a new outgoing plug to the logical node and its representations.
	///
	/// \param [in] name        The proposed name of the plug.
	///
	/// \return                 Handle of the created Plug.
	///
	inline zodiac::PlugHandle addOutgoingPlug(const QString &name) { return addPlug(name, false); }

	///
	/// \brief Renames an existing plug of this logical node.
	///
	/// If the given name does not name a plug of this node, the method returns the empty string.
	///
	/// \param [in] oldName Current name of the the plug to be renamed.
	/// \param [in] newName New name proposal for the plug.
	///
	/// \return             Actual new name of the plug.
	///
	QString renamePlug(const QString &oldName, const QString &newName);

	///
	/// \brief Changes the direction of a Plug from incoming to outgoing or vice-versa.
	///
	/// This works only on Plug%s that have no existing connections.
	///
	/// \param [in] name        Name of the plug to toggle.
	///
	/// \return <i>true</i> if the Plug was able to change its direction -- <i>false</i> otherwise.
	///
	bool togglePlugDirection(const QString &name);

	///
	/// \brief Removes a plug from the logical node.
	///
	/// If the given name does not name a plug of this node, the method returns <i>true</i>.
	///
	/// \param [in] name    Name of the the plug to remove.
	///
	/// \return             <i>true</i> if the plug was removed -- <i>false</i> otherwise.
	///
	bool removePlug(const QString &name);

	///
	/// \brief Forces a node in the Zodiac Graph to become selected or unselected.
	///
	/// \param [in] isSelected  <i>true</i> if the managed Node is to be selected -- <i>false</i> otherwise.
	///
	void setSelected(bool isSelected);

public slots:

	///
	/// \brief Tries to remove this logical node from the graph.
	///
	/// \return <i>true</i> if the node was removed -- <i>false</i> otherwise.
	///
	bool remove();

private: // methods

	///
	/// \brief Creates a new incoming Plug for the managed Node.
	///
	/// \param [in] name        The proposed name of the plug.
	/// \param [in] incoming    <i>true</i> if the created Plug could be incoming -- <i>false</i> to be ougoing.
	///
	/// \return                 Handle of the created Plug.
	///
	zodiac::PlugHandle addPlug(const QString &name, bool incoming);

private slots:

	///
	/// \brief Is emitted, when an incoming plug of the managed Node has been connected to an outgoing plug of another
	/// Node.
	///
	/// \param [out] myInput        The input plug of the managed Node.
	/// \param [out] otherOutput    The output plug of the source Node.
	///
	void inputConnected(zodiac::PlugHandle myInput, zodiac::PlugHandle otherOutput);

	///
	/// \brief Is emitted, when an outgoing plug of the managed Node has been connected to an incoming plug of another
	/// Node.
	///
	/// \param [out] myOutput   The output plug of the managed Node.
	/// \param [out] otherInput The input plug of the target Node.
	///
	void outputConnected(zodiac::PlugHandle myOutput, zodiac::PlugHandle otherInput);

	///
	/// \brief Is emitted, when a connection from an incoming plug of the managed Node was removed.
	///
	/// \param [out] myInput        The input plug of the managed Node.
	/// \param [out] otherOutput    The output plug of the source Node.
	///
	void inputDisconnected(zodiac::PlugHandle myInput, zodiac::PlugHandle otherOutput);

	///
	/// \brief Is emitted, when a connection from an outgoing plug of the managed Node was removed.
	///
	/// \param [out] myOutput   The output plug of the managed Node.
	/// \param [out] otherInput The input plug of the target Node.
	///
	void outputDisconnected(zodiac::PlugHandle myOutput, zodiac::PlugHandle otherInput);

private: // members

	///
	/// \brief NodeManager owning this NodeCtrl.
	///
	MainCtrl *m_manager;

	///
	/// \brief Handle to a zodiac::Node.
	///
	zodiac::NodeHandle m_node;

	///
	/// \brief All Plug%s of the zodiac::Node managed by this logical node.
	///
	/// The value of the hash is a list of all connected plugs, so they can update when a plug is renamed.
	///
	QHash<zodiac::PlugHandle, QList<zodiac::PlugHandle>> m_plugs;
};

#endif // NODECTRL_H
