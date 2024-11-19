#pragma once

class Packet
{
public:
	enum PacketType
	{
		Req,
		Ack,
		Nak,
		Ntf,
	};
protected:
	uint16_t m_u16Size;
	uint16_t m_u16Type;
	uint16_t m_u16Pack;
	uint16_t m_u16Reserved;
	uint32_t m_u32Index;
};