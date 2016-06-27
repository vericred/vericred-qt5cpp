/*
 * SWGPlanZipCounty.h
 * 
 * 
 */

#ifndef SWGPlanZipCounty_H_
#define SWGPlanZipCounty_H_

#include <QJsonObject>



#include "SWGObject.h"


namespace Swagger {

class SWGPlanZipCounty: public SWGObject {
public:
    SWGPlanZipCounty();
    SWGPlanZipCounty(QString* json);
    virtual ~SWGPlanZipCounty();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGPlanZipCounty* fromJson(QString &jsonString);

    qint32 getPlanId();
    void setPlanId(qint32 plan_id);
qint32 getCountyId();
    void setCountyId(qint32 county_id);
qint32 getZipCodeId();
    void setZipCodeId(qint32 zip_code_id);

private:
    qint32 plan_id;
qint32 county_id;
qint32 zip_code_id;
};

} /* namespace Swagger */

#endif /* SWGPlanZipCounty_H_ */
