/*
 * SWGDrugCoverage.h
 * 
 * 
 */

#ifndef SWGDrugCoverage_H_
#define SWGDrugCoverage_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGDrugCoverage: public SWGObject {
public:
    SWGDrugCoverage();
    SWGDrugCoverage(QString* json);
    virtual ~SWGDrugCoverage();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGDrugCoverage* fromJson(QString &jsonString);

    QString* getPlanId();
    void setPlanId(QString* plan_id);
QString* getNdcPackageCode();
    void setNdcPackageCode(QString* ndc_package_code);
QString* getTier();
    void setTier(QString* tier);
bool getQuantityLimit();
    void setQuantityLimit(bool quantity_limit);
bool getPriorAuthorization();
    void setPriorAuthorization(bool prior_authorization);
bool getStepTherapy();
    void setStepTherapy(bool step_therapy);

private:
    QString* plan_id;
QString* ndc_package_code;
QString* tier;
bool quantity_limit;
bool prior_authorization;
bool step_therapy;
};

} /* namespace Swagger */

#endif /* SWGDrugCoverage_H_ */
