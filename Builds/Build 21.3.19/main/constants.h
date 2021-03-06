/**************************************************************************************************
 * constants.h
 * Constant Header File
 * This file containts all the packet types, commands
 * and status constants
**************************************************************************************************/
#ifndef __CONSTANTS_INC__
#define __CONSTANTS_INC__

//motor pins
#define M1F 6
#define M1R 5
#define M2F 9
#define M2R 10

// Direction values
typedef enum dir {
  STOP,
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
} dir;

//serial.h
//#define PACKET_SIZE 12

// Packet types
typedef enum
{
  PACKET_TYPE_COMMAND = 0,
  PACKET_TYPE_RESPONSE = 1,
  PACKET_TYPE_ERROR = 2,
  PACKET_TYPE_MESSAGE = 3,
  PACKET_TYPE_HELLO = 4
} TPacketType;

// Response types. This goes into the command field
typedef enum
{
  RESP_OK = 0,
  RESP_STATUS=1,
  RESP_BAD_PACKET = 2,
  RESP_BAD_CHECKSUM = 3,
  RESP_BAD_COMMAND = 4,
  RESP_BAD_RESPONSE = 5 
} TResponseType;


// Commands
// For direction commands, param[0] = distance in cm to move
// param[1] = speed
typedef enum
{
  COMMAND_FORWARD = 0,
  COMMAND_REVERSE = 1,
  COMMAND_TURN_LEFT = 2,
  COMMAND_TURN_RIGHT = 3,
  COMMAND_STOP = 4,
  COMMAND_GET_STATS = 5,
  COMMAND_CLEAR_STATS = 6
} TCommandType;


typedef enum
{
  PACKET_OK = 0,
  PACKET_BAD = 1,
  PACKET_CHECKSUM_BAD = 2,
  PACKET_INCOMPLETE = 3,
  PACKET_COMPLETE = 4
} TResult;

#endif
