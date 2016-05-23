/*
 * SWGPricing.h
 * 
 * 
 */

#ifndef SWGPricing_H_
#define SWGPricing_H_

#include <QJsonObject>


#include "QDate.h"
#include "SWGNumber.h"
#include <QString>

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
SWGNumber* getPremiumChildOnly();
    void setPremiumChildOnly(SWGNumber* premium_child_only);
SWGNumber* getPremiumFamily();
    void setPremiumFamily(SWGNumber* premium_family);
SWGNumber* getPremiumSingle();
    void setPremiumSingle(SWGNumber* premium_single);
SWGNumber* getPremiumSingleAndChildren();
    void setPremiumSingleAndChildren(SWGNumber* premium_single_and_children);
SWGNumber* getPremiumSingleAndSpouse();
    void setPremiumSingleAndSpouse(SWGNumber* premium_single_and_spouse);
SWGNumber* getPremiumSingleSmoker();
    void setPremiumSingleSmoker(SWGNumber* premium_single_smoker);
QString* getRatingAreaId();
    void setRatingAreaId(QString* rating_area_id);

private:
    qint32 age;
QDate* effective_date;
QDate* expiration_date;
qint32 plan_id;
SWGNumber* premium_child_only;
SWGNumber* premium_family;
SWGNumber* premium_single;
SWGNumber* premium_single_and_children;
SWGNumber* premium_single_and_spouse;
SWGNumber* premium_single_smoker;
QString* rating_area_id;
};

} /* namespace Swagger */

#endif /* SWGPricing_H_ */
