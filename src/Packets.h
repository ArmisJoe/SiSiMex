#pragma once
#include "Globals.h"
#include "AgentLocation.h"

/**
 * Enumerated type for packets.
 * There must be a value for each kind of packet
 * containing extra data besides the Header.
 */
enum class PacketType
{
	// MCC <-> YP
	RegisterMCC,
	RegisterMCCAck,
	UnregisterMCC,
	UnregisterMCCAck,
	Last
};

/**
 * Standard information used by almost all messages in the system.
 * Agents will be communicating among each other, so in many cases,
 * besides the packet type, a header containing the source and the
 * destination agents involved is needed.
 */
class PacketHeader {
public:
	PacketType packetType; // Which type is this packet
	uint16_t srcAgentId;   // Which agent sent this packet?
	uint16_t dstAgentId;   // Which agent is expected to receive the packet?
	PacketHeader() :
		packetType(PacketType::Last),
		srcAgentId(NULL_AGENT_ID),
		dstAgentId(NULL_AGENT_ID)
	{ }
	void Read(InputMemoryStream &stream) {
		// TODO: Deserialize fields
		stream.Read(packetType);
		stream.Read(srcAgentId);
		stream.Read(dstAgentId);
	}
	void Write(OutputMemoryStream &stream) {
		// TODO: Serialize fields
		stream.Write(packetType);
		stream.Write(srcAgentId);
		stream.Write(dstAgentId);
	}
};

// TODO: PacketRegisterMCC

/*
To register a MCC we need to know which resource/item is
being provided by the MCC agent
*/
class PacketRegisterMCC {
public:
	uint16_t itemId; // Which item has to be registered?
	void Read(InputMemoryStream &stream) 
	{
		// TODO
		stream.Read(stream);
	}
	void Write(OutputMemoryStream &stream) 
	{
		// TODO
		stream.Write(stream);
	}
};

// TODO: PacketRegisterMCCAck   <-- Do we need an actual data packet? Think...
class PacketRegisterMCCAck {
public:
	uint16_t itemId; // Which item has to be registered?
	void Read(InputMemoryStream &stream)
	{
		// TODO
		stream.Read(stream);
	}
	void Write(OutputMemoryStream &stream)
	{
		// TODO
		stream.Write(stream);
	}
};

// TODO: PacketUnregisterMCC

// TODO: PacketUnregisterMCCAck <-- Do we need an actual data packet? Think...
