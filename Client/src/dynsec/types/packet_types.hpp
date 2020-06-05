#pragma once
#include "stdafx.hpp"

namespace Dynsec::PacketTypes {
	namespace Request {
		struct EncryptionKeys {
			// ...
		};
		
		struct UserIdentification {
			// ...
		};

		struct GameInformation {
			uint8_t m_GameID;							// ID of the game
			uint16_t m_GameVersion;						// Games version, given to us in InitializeClient
		};

		struct NetworkBaseHeader { // not encrypted
			uint32_t m_Magic;							// Magic for verifying request | 0x44534143 - "DSAC"
			uint32_t m_Size;							// Size of the request after the header
			uint8_t m_Packet;							// ID of the packet that's being sent. Will most likely be static for init, and dynamic for the rest
			uint8_t m_SessionToken[0x20];				// Session token generated by our server
			uint8_t m_RequestHMAC[0x20];				// HMAC of the request after the header to verify it hasn't been tampered
			EncryptionKeys m_Encryption;				// Keys for the encryption used
		};

		struct NetworkHeader : NetworkBaseHeader { // encrypted
			GameInformation m_GameInfo;					// Information on the game, could be modified though so shouldn't be trusted
		};
	}
}