#ifndef _ASYNC_PUSH_ROBOT_CB_H_
#define _ASYNC_PUSH_ROBOT_CB_H_

#include "RobotProto.h"
#include "RoomServant.h"

using namespace JFGame;
using namespace robot;

/**
* RoomSvr异步回调类
*/
class AsyncPushRobotCallback : public RoomServantPrxCallback
{
public:
    AsyncPushRobotCallback(const string &roomID);
    virtual ~AsyncPushRobotCallback();

public:
    //推送机器人回调
    virtual void callback_onPushRobot(tars::Int32 ret, const robot::TPushRobotRsp &rsp);
    //推送机器人异常
    virtual void callback_onPushRobot_exception(tars::Int32 ret);

private:
    //
    string sRoomID;
};

#endif