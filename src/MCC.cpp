#include "MCC.h"
#include "Application.h"
#include "ModuleAgentContainer.h"

// With these states you have enough so far...
enum State
{
	ST_INIT,
	ST_REGISTERING,
	ST_IDLE,
	ST_UNREGISTERING,
	ST_FINISHED
};

MCC::MCC(Node *node, uint16_t contributedItemId, uint16_t constraintItemId) :
	Agent(node),
	_contributedItemId(contributedItemId),
	_constraintItemId(constraintItemId)
{
}


MCC::~MCC()
{
}

void MCC::start()
{
	// TODO: Set the initial state
	setState(ST_IDLE);
}

void MCC::update()
{
	switch (state())
	{
		// TODO:
		// - Register or unregister into/from YellowPages depending on the state
		//       Use the functions registerIntoYellowPages and unregisterFromYellowPages
		//       so that this switch statement remains clean and readable
		// - Set the next state when needed ...
	}
}

void MCC::stop()
{
	unregisterFromYellowPages();
	setState(ST_UNREGISTERING);
}


void MCC::OnPacketReceived(TCPSocketPtr socket, const PacketHeader &packetHeader, InputMemoryStream &stream)
{
	// Taking the state into account, receive and deserialize packets (Ack packets) and set next state
	if (state() == ST_REGISTERING && packetHeader.packetType == PacketType::RegisterMCCAck)
	{
		// TODO: Set the next state (Idle in this case)
		setState(ST_IDLE);
		// TODO: Disconnect the socket (we don't need it anymore)
		socket->Disconnect();
	}

	// TODO: Do the same for unregistering
}

bool MCC::negotiationFinished() const
{
	return false;
}

bool MCC::negotiationAgreement() const
{
	return false;
}

bool MCC::registerIntoYellowPages()
{
	// TODO: Create a PacketHeader (make it in Packets.h)
	PacketHeader packetHeader;

	// TODO: Create a PacketRegisterMCC (make it in Packets.h)
	PacketRegisterMCC inPacketData;

	// TODO: Serialize both packets into an OutputMemoryStream
	OutputMemoryStream outMemStream(sizeof(packetHeader) + sizeof(inPacketData));
	outMemStream.Write(packetHeader);
	outMemStream.Write(inPacketData);

	// TODO: Send the stream (Agent::sendPacketToYellowPages)
	sendPacketToYellowPages(outMemStream);
	return false;
}

bool MCC::unregisterFromYellowPages()
{
	// TODO: Create a PacketHeader (make it in Packets.h)
	PacketHeader packetHeader;

	// TODO: Create a PacketUnregisterMCC (make it in Packets.h)
	PacketUnregisterMCC outPacketData;

	// TODO: Serialize both packets into an OutputMemoryStream
	OutputMemoryStream outMemStream(sizeof(packetHeader) + sizeof(outPacketData));
	outMemStream.Write(packetHeader);
	outMemStream.Write(outPacketData);

	// TODO: Send the stream (Agent::sendPacketToYellowPages)
	sendPacketToYellowPages(outMemStream);
	return false;
}
