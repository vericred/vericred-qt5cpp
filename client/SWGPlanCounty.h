/*
 * SWGPlanCounty.h
 * 
 * 
 */

#ifndef SWGPlanCounty_H_
#define SWGPlanCounty_H_

#include <QJsonObject>



#include "SWGObject.h"


namespace Swagger {

class SWGPlanCounty: public SWGObject {
public:
    SWGPlanCounty();
    SWGPlanCounty(QString* json);
    virtual ~SWGPlanCounty();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGPlanCounty* fromJson(QString &jsonString);

    qint32 getId();
    void setId(qint32 id);
qint32 getPlanId();
    void setPlanId(qint32 plan_id);
qint32 getCountyId();
    void setCountyId(qint32 county_id);

private:
    qint32 id;
qint32 plan_id;
qint32 county_id;
};

} /* namespace Swagger */

#endif /* SWGPlanCounty_H_ */
