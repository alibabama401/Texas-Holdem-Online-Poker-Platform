#include "AsyncPushRobotCallback.h"
#include "globe.h"
#include "LogComm.h"
#include "PushRobotManager.h"

AsyncPushRobotCallback::AsyncPushRobotCallback(const string &roomID) : sRoomID(roomID)
{

}

AsyncPushRobotCallback::~AsyncPushRobotCallback()
{

}

//推送机器人回调
void AsyncPushRobotCallback::callback_onPushRobot(tars::Int32 ret, const robot::TPushRobotRsp &rsp)
{
    // if (rsp.iResult == 0)
    // {
    //     int iRet = pushRobotManagerSingleton::getInstance()->syncRoomSvrRobot(sRoomID, rsp.mapRobotBatch);
    //     if (iRet != 0)
    //     {
    //         ROLLLOG_DEBUG << "push robot callback, sync room server data errr. iRet: " << iRet << endl;
    //     }

    //     ROLLLOG_DEBUG << "push robot ok, ret: " << ret << ", sRoomID: " << sRoomID << ", iResult: " << rsp.iResult << ", mapRobotBatch size: " << rsp.mapRobotBatch.size() << endl;
    // }
    // else
    // {
    //     ROLLLOG_ERROR << "push robot err, rsp.iResult: " << rsp.iResult << ", sRoomID: " << sRoomID << endl;
    // }
}

//推送机器人异常
void AsyncPushRobotCallback::callback_onPushRobot_exception(tars::Int32 ret)
{
    ROLLLOG_DEBUG << "push robot exception, ret: " << ret << ", sRoomID: " << sRoomID << endl;
}