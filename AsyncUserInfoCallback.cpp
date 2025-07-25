#include "AsyncUserInfoCallback.h"
#include "OuterFactoryImp.h"
#include "AIServer.h"

/**
 *
*/
AsyncUserInfoCallback::AsyncUserInfoCallback(const userinfo::GetUserBasicReq &req): m_reqGUB(req)
{

}

/**
 *
*/
AsyncUserInfoCallback::AsyncUserInfoCallback(const userinfo::GetUserAccountReq &req, const CBatchRobotDataPtr &ptr,
        const CRobotPtr &robotPtr, eumActType actType): m_reqGUA(req), robotDataPtr(ptr), m_robotPtr(robotPtr), m_actType(actType)
{

}

/**
 *
*/
AsyncUserInfoCallback::AsyncUserInfoCallback(const userinfo::ModifyUserAccountReq &req, const CBatchRobotDataPtr &ptr,
        const CRobotPtr &robotPtr, eumActType actType)
    : m_reqMUA(req),
      robotDataPtr(ptr),
      m_robotPtr(robotPtr),
      m_actType(actType)
{
}

/**
 *
*/
AsyncUserInfoCallback::~AsyncUserInfoCallback()
{
}

//获取用户个人信息
void AsyncUserInfoCallback::callback_getUserBasic(tars::Int32 ret, const userinfo::GetUserBasicResp &resp)
{
    if (ret == 0)
    {
        LOG_DEBUG << m_reqGUB.uid << "|" << "get user basic callback success." << endl;
    }
    else
    {
        LOG_ERROR << m_reqGUB.uid << "|" << "get user basic callback error, ret : " << ret << endl;
    }
}

void AsyncUserInfoCallback::callback_getUserBasic_exception(tars::Int32 ret)
{
    LOG_ERROR << m_reqGUB.uid << "|" << "get user basic callback exception... ret : " << ret << endl;
}

//获取用户账号财富信息
void AsyncUserInfoCallback::callback_getUserAccount(tars::Int32 ret, const userinfo::GetUserAccountResp &resp)
{
    if (ret == 0)
    {
        LOG_DEBUG << m_reqGUA.uid << "|" << "get user account callback success." << endl;

        // switch (m_actType)
        // {
        // //E_ACT_TYPE_OFFLINE = 1,  //机器人下线
        // case E_ACT_TYPE_OFFLINE:
        // {
        //     //货币不在规定区间
        //     if ((resp.gold < robotDataPtr->getRobotConf().iMinCoins) || (resp.gold > robotDataPtr->getRobotConf().iMaxCoins) )
        //     {
        //         //
        //         ROLLLOG_ERROR << "user coins not in range, send user offline request, uid : " << m_reqGUA.uid
        //                       << ", room id : " << m_robotPtr->getRoomID() << endl;

        //         //发起掉线请求
        //         g_app.getOuterFactoryPtr()->asyncSend2RoomServerOffline(m_reqGUA.uid, m_robotPtr->getRoomID());

        //         //释放机器人
        //         m_robotPtr->setInuseFlag(E_FREE);
        //     }
        // }
        // break;

        // //E_ACT_TYPE_MODIFY_COIN = 2,  //修改机器人货币
        // case E_ACT_TYPE_MODIFY_COIN:
        // {
        //     if (robotDataPtr->getRechargeConfig().size() == 0)
        //     {
        //         if ((resp.gold < robotDataPtr->getRobotConf().iMinCoins) || (resp.gold > robotDataPtr->getRobotConf().iMaxCoins) )
        //         {
        //             //调整货币
        //             userinfo::ModifyUserAccountReq req;
        //             req.uid = m_reqGUA.uid;
        //             req.changeType = 30;
        //             long int coin = nnrand(robotDataPtr->getRobotConf().iMaxCoins, robotDataPtr->getRobotConf().iMinCoins);
        //             req.goldChange = coin - resp.gold;
        //             auto cb = new AsyncUserInfoCallback(req, robotDataPtr, m_robotPtr, E_ACT_TYPE_MODIFY_COIN);
        //             g_app.getOuterFactoryPtr()->getUserInfoServerPrx()->async_modifyUserAccount(cb, req);
        //         }
        //     }
        //     else
        //     {
        //         //调整货币
        //         userinfo::ModifyUserAccountReq req;
        //         req.uid = m_reqGUA.uid;
        //         req.changeType = 30;
        //         const vector<TRobotRechargeConfig> &rechargeConf = robotDataPtr->getRechargeConfig();
        //         for (auto it = rechargeConf.begin(); it != rechargeConf.end(); ++it)
        //         {
        //             switch (it->iCoinType)
        //             {
        //             case 0:
        //             {
        //                 //房卡
        //                 if ((resp.roomCard < it->iMinCoins) || (resp.roomCard > it->iMaxCoins) )
        //                 {
        //                     long int coin = nnrand(it->iMaxCoins, it->iMinCoins);
        //                     req.roomCardChange = coin - resp.roomCard;
        //                 }
        //             }
        //             break;

        //             case 1:
        //             {
        //                 //钻石
        //                 if ((resp.diamond < it->iMinCoins) || (resp.diamond > it->iMaxCoins))
        //                 {
        //                     long int coin = nnrand(it->iMaxCoins, it->iMinCoins);
        //                     req.diamondChange = coin - resp.roomCard;
        //                 }
        //             }
        //             break;

        //             case 2:
        //             {
        //                 //金币
        //                 if ((resp.gold < it->iMinCoins) || (resp.gold > it->iMaxCoins) )
        //                 {
        //                     long int coin = nnrand(it->iMaxCoins, it->iMinCoins);
        //                     req.goldChange = coin - resp.roomCard;
        //                 }
        //             }
        //             break;

        //             default:
        //                 break;
        //             }
        //         }
        //         //请求变更货币
        //         userinfo::UserInfoPrxCallbackPtr cb = new AsyncUserInfoCallback(req, robotDataPtr, m_robotPtr, E_ACT_TYPE_MODIFY_COIN);
        //         g_app.getOuterFactoryPtr()->getUserInfoServerPrx()->async_modifyUserAccount(cb, req);
        //     }
        // }
        // break;

        // default:
        //     LOG_DEBUG << "invalid action type, m_actType : " << m_actType << endl;
        //     break;
        // }
    }
    else
    {
        LOG_ERROR << m_reqGUA.uid << "|" << "get user account callback error, ret : " << ret << endl;
    }
}

void AsyncUserInfoCallback::callback_getUserAccount_exception(tars::Int32 ret)
{
    LOG_ERROR << m_reqGUA.uid << "|" << "get user account callback exception... ret : " << ret << endl;
}

//修改用户账号财富信息
void AsyncUserInfoCallback::callback_modifyUserAccount(tars::Int32 ret)
{
    if (ret == 0)
    {
        LOG_DEBUG << m_reqMUA.uid << "|" << "modify user account callback success." << endl;
    }
    else
    {
        LOG_ERROR << m_reqMUA.uid << "|" << "modify user account callback error, ret : " << ret << endl;
    }
}

void AsyncUserInfoCallback::callback_modifyUserAccount_exception(tars::Int32 ret)
{
    LOG_ERROR << m_reqMUA.uid << "|" << "modify user account callback exception... ret : " << ret << endl;
}
