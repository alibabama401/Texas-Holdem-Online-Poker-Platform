#ifndef _ASYNC_AI_CALC_RESULT_CB_H_
#define _ASYNC_AI_CALC_RESULT_CB_H_

#include "RobotProto.h"
#include "RoomServant.h"

using namespace JFGame;
using namespace robot;

/**
* RoomSvr异步回调类
*/
class AsyncAICalcResultCallback : public RoomServantPrxCallback
{
public:
    AsyncAICalcResultCallback(const string &roomID);
    virtual ~AsyncAICalcResultCallback();

public:
    //推送决策结果回调
    virtual void callback_onRoomAIDecide(tars::Int32 ret, const robot::TPushRobotRsp &rsp);
    //推送决策结果异常
    virtual void callback_onRoomAIDecide_exception(tars::Int32 ret);

private:
    //
    string sRoomID;
};

#endif