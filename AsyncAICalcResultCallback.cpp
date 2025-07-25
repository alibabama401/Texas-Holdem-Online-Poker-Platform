#include "AsyncAICalcResultCallback.h"
#include "globe.h"
#include "LogComm.h"
#include "PushRobotManager.h"

AsyncAICalcResultCallback::AsyncAICalcResultCallback(const string &roomID) : sRoomID(roomID)
{

}

AsyncAICalcResultCallback::~AsyncAICalcResultCallback()
{

}

void AsyncAICalcResultCallback::callback_onRoomAIDecide(tars::Int32 ret, const robot::TPushRobotRsp &rsp)
{
    if (ret == 0)
    {
        ROLLLOG_DEBUG << "push decide succ, ret: " << ret << ", sRoomID: " << sRoomID << endl;
    }
    else
    {
        ROLLLOG_ERROR << "push decide fail, ret: " << ret << ", sRoomID: " << sRoomID << endl;
    }
}

//推送机器人异常
void AsyncAICalcResultCallback::callback_onRoomAIDecide_exception(tars::Int32 ret)
{
    ROLLLOG_DEBUG << "push robot exception, ret: " << ret << ", sRoomID: " << sRoomID << endl;
}