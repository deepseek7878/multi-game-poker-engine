#ifndef _Processor_H_
#define _Processor_H_

//
#include <util/tc_singleton.h>
#include "GameRecordServant.h"

//
using namespace tars;

/**
 *请求处理类
 *
 */
class Processor
{
public:
    /**
     *
    */
    Processor();

    /**
     *
    */
    ~Processor();

public://经典场用户行为信息
    //查询
    int selectQSUserActInfo(const gamerecord::QSUserActInfoReq &req, gamerecord::QSUserActInfoResp &resp);
    //增加
    int UpdateQSUserActInfo(const gamerecord::UpdateQSUserActInfoReq &req);
    //上报
    int UpdateQSUserActInfo(const gamerecord::ReportQSUserActInfoReq &req);

public: //比赛场用户行为信息
    //查询
    int selectKOUserActInfo(const gamerecord::KOUserActInfoReq &req, gamerecord::KOUserActInfoResp &resp);
    //增加
    int UpdateKOUserActInfo(const gamerecord::UpdateKOUserActInfoReq &req);
    //上报
    int UpdateKOUserActInfo(const gamerecord::ReportKOUserActInfoReq &req);

    int ReadPrGameInfo(const string& sRoomKey, gamerecord::RoomCalStatReq& stat, long zerotime, bool link = false);
    int WritePrGameInfo(const string& sRoomKey, gamerecord::RoomCalStatReq& stat, long zerotime);
    int updatePrGameInfo(const gamerecord::RoomCalStatReq &req);
public:
    //查询用户行为信息
    int selectAIUserActInfo(const gamerecord::AIUserActInfoReq &req, gamerecord::AIUserActInfoResp &resp);
    //上报用户行为信息
    int UpdateAIUserActInfo(const gamerecord::ReportAIUserActInfoReq &req);
    int WritePrUserRoomKey(const string& sRoomKey, long uid, bool replace = false);
    //新增用户行为信息
    int InsertAIUserActInfo(const gamerecord::ReportAIUserActInfoReq &req);
    //上报用户基础数据
    int UpdateAIUserBaseInfo(const gamerecord::ReportAIUserActInfoReq &req);
    //新增用户基础数据
    int InsertAIUserBaseInfo(const gamerecord::ReportAIUserActInfoReq &req, std::string key);
    //上报用户牌数据
    int UpdateAIUserCardInfo(const gamerecord::ReportAIUserCardInfoReq &req);
    //新增用户牌数据
    int InsertAIUserCardInfo(const gamerecord::ReportAIUserCardInfoReq &req);
    //查询用户排名数据
    int selectAIUserRankInfo(long uid, long &score, std::string &tmstr, int &hdcount);
    //上报用户排名数据
    int UpdateAIUserRankInfo(const gamerecord::ReportAIUserActInfoReq &req);
    //新增用户排名数据
    int InsertAIUserRankInfo(const gamerecord::ReportAIUserActInfoReq &req);
    //查询用户是否有当天数据
    int IsAIUserBaseInfoExist(long uid, std::string key, std::string date, int level);
    //查询AI用户基础管理数据
    int SelectAIUserBaseManageInfo(long uid, int level);
    //更新AI用户基础管理数据
    int UpdateAIUserBaseManageInfo(long uid, int level, int lastid);
    //新增AI用户基础管理数据
public:
    //更新用户key数据
    int UpdateAIUserKeyInfo(long uid, int type, std::string key);
    //新增用户key数据
    int InsertAIUserKeyInfo(long uid, int type, std::string key);
    //查询用户key数据
    int SelectAIUserKeyInfo(long uid, gamerecord::AIUserKeyInfoRsp &resp);
    //删除用户key数据
    int DeleteAIUserBaseKeyInfo(long uid, int type, std::string key);
    //修改用户key数据接口
    int AlertAIUserKeyInfo(long uid, int type, std::string key);

    bool getShowDataFlag(long uid);
public:
    //计算牌大小
    std::string GetCardFace(short card);
    //计算是否同花
    int BSameSuit(std::vector<short> cards);
    //计算是否对子
    int BSameFace(std::vector<short> cards);
};

//singleton
typedef TC_Singleton<Processor, CreateStatic, DefaultLifetime> ProcessorSingleton;

#endif

