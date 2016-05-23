/*
 * SWGPlanCountyBulk.h
 * 
 * 
 */

#ifndef SWGPlanCountyBulk_H_
#define SWGPlanCountyBulk_H_

#include <QJsonObject>



#include "SWGObject.h"


namespace Swagger {

class SWGPlanCountyBulk: public SWGObject {
public:
    SWGPlanCountyBulk();
    SWGPlanCountyBulk(QString* json);
    virtual ~SWGPlanCountyBulk();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGPlanCountyBulk* fromJson(QString &jsonString);

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

#endif /* SWGPlanCountyBulk_H_ */
