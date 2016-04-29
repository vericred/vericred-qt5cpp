/*
 * SWGPricing.h
 * 
 * 
 */

#ifndef SWGPricing_H_
#define SWGPricing_H_

#include <QJsonObject>


#include "QDate.h"

#include "SWGObject.h"


namespace Swagger {

class SWGPricing: public SWGObject {
public:
    SWGPricing();
    SWGPricing(QString* json);
    virtual ~SWGPricing();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGPricing* fromJson(QString &jsonString);

    qint32 getAge();
    void setAge(qint32 age);
QDate* getEffectiveDate();
    void setEffectiveDate(QDate* effective_date);
QDate* getExpirationDate();
    void setExpirationDate(QDate* expiration_date);
qint32 getPlanId();
    void setPlanId(qint32 plan_id);
qint32 getRatingAreaId();
    void setRatingAreaId(qint32 rating_area_id);

private:
    qint32 age;
QDate* effective_date;
QDate* expiration_date;
qint32 plan_id;
qint32 rating_area_id;
};

} /* namespace Swagger */

#endif /* SWGPricing_H_ */
