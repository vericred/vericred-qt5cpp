/*
 * SWGCounty.h
 * 
 * 
 */

#ifndef SWGCounty_H_
#define SWGCounty_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGCounty: public SWGObject {
public:
    SWGCounty();
    SWGCounty(QString* json);
    virtual ~SWGCounty();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGCounty* fromJson(QString &jsonString);

    qint32 getId();
    void setId(qint32 id);
QString* getFipsCode();
    void setFipsCode(QString* fips_code);
QString* getName();
    void setName(QString* name);
QString* getStateCode();
    void setStateCode(QString* state_code);
qint32 getStateId();
    void setStateId(qint32 state_id);
bool getStateLive();
    void setStateLive(bool state_live);
bool getStateLiveForBusiness();
    void setStateLiveForBusiness(bool state_live_for_business);

private:
    qint32 id;
QString* fips_code;
QString* name;
QString* state_code;
qint32 state_id;
bool state_live;
bool state_live_for_business;
};

} /* namespace Swagger */

#endif /* SWGCounty_H_ */
